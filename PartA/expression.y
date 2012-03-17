%{
/*
 * Expression evaluator
 */
#include "functions.h"
#include "stdio.h"

//#define YYSTYPE int

%}

%union {
	void *pval;		
	double ival;		
	char *sval;		
}

%token PRINT IF WHILE
%token<ival> NUM
%token<sval> STRING VAR ASSIGN SQRT USERSUPPORT

%type<pval> STMT DECL EXPR STMTS EXPON UNARY TERM COMP NUMBER OUTPUT PRINTSTRING PRINTLINE IFSTMT WHILESTMT EXPRESSION

%%

PROGRAM : PROGRAM '\n' {}
        | PROGRAM '\n' STMT {/* Execute */}
        | STMT {/* Execute here*/}
        | {}

STMTS : STMTS '\n'	{}
      | STMTS '\n' STMT  {}
      | STMT  {}
      | {}
	 
STMT : DECL  {}
     | EXPRESSION {PrintExpr($1); PushToStack($1);}
	 | OUTPUT {PrintPrintList($1);}
	 | USERSUPPORT {PrintUserSupport($1);}
	 | IFSTMT {}
	 | WHILESTMT {}
		
IFSTMT : IF '(' EXPRESSION ')' '\n' '{' '\n' STMTS '}' {/*$$ = CreateIf($3, $6);*/}
WHILESTMT : WHILE '(' EXPRESSION ')' '\n' '{' '\n' STMTS '}' {/*$$ = CreateWhile($3, $6);*/}

DECL : VAR ASSIGN EXPRESSION  {
    AssignVariable($1, $3);
    // NOTE: we don't clean up EXPR, it is owned by SymbolTable
}

OUTPUT : PRINT PRINTSTRING  {$$ = $2; PushToPrintStack($2);}
OUTPUT : PRINT PRINTLINE {$$ = $2; PushToPrintStack($2);}
OUTPUT : PRINT {
    $$ = AddPrintable(CreatePrintList(), CreateString(" "));
    PushToPrintStack($$);
}

PRINTSTRING : PRINTLINE STRING {$$ = AddPrintable($1, CreateString($2));}
PRINTLINE : PRINTSTRING EXPRESSION {$$ = AddPrintable($1, $2);}

PRINTSTRING : STRING {$$ = AddPrintable(CreatePrintList(), CreateString($1));}
PRINTLINE : EXPRESSION {$$ = AddPrintable(CreatePrintList(), $1);}

EXPRESSION : EXPR  {$$ = $1;}
           | COMP  {$$ = $1;}

COMP : EXPR '<' EXPR  {$$ = CreateLessThan($1, $3); }
COMP : EXPR '>' EXPR  {$$ = CreateGreaterThan($1, $3);}

EXPR : EXPR '+' TERM  {$$ = CreateAdd($1, $3);}
EXPR : EXPR '-' TERM {$$ = CreateSubtract($1, $3);}
EXPR : TERM  {$$ = $1;}

TERM : TERM '*' EXPON  {$$ = CreateMultiply($1, $3);}
TERM : TERM '/' EXPON  {$$ = CreateDivide($1, $3);}
TERM : EXPON  {$$ = $1;}

EXPON : EXPON '^' UNARY  {$$ = CreateExponent($1, $3);}
EXPON : UNARY  {$$ = $1;}

UNARY : '-' NUMBER {$$ = CreateNegate($2);}
UNARY : SQRT NUMBER {$$ = CreateSqrt($2);}
UNARY : NUMBER {$$ = $1;}

NUMBER : '(' EXPR ')'  {$$ = $2;}
NUMBER : NUM  {$$ = CreateDouble($1);}
NUMBER : VAR  {$$ = CreateVariable($1);}

%%
