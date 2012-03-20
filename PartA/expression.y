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
%token<sval> STRING VAR ASSIGN SQRT USERSUPPORT ADDFUNC MEANFUNC STDFUNC STRVAR

%type<pval> STMT DECL EXPR STMTS EXPON UNARY TERM COMP NUMBER OUTPUT PRINTSTRING PRINTLINE IFSTMT WHILESTMT EXPRESSION EXPRLIST STATS STR STRDECL

%%

PROGRAM : PROGRAM '\n' {}
        | PROGRAM '\n' STMT { ExecuteStatement($3); }
        | STMT { ExecuteStatement($1); }
        | {}

STMTS : STMTS '\n'	{ $$ = $1; }
      | STMTS '\n' STMT  { $$ = AddStatementToList($1, $3); }
      | STMT  { $$ = CreateStatementList($1); }
      | {}
	 
STMT : DECL  { $$ = $1; }
     | STRDECL { $$ = $1; }
     | EXPRESSION { $$ = $1; }
	 | OUTPUT { $$ = $1; }
	 | USERSUPPORT { $$ = CreateUserCommand($1); }
	 | IFSTMT { $$ = $1; }
	 | WHILESTMT { $$ = $1; }

IFSTMT : IF '(' EXPRESSION ')' '\n' '{' '\n' STMTS '}' {
    $$ = CreateIfStmt($3, $8);
}
WHILESTMT : WHILE '(' EXPRESSION ')' '\n' '{' '\n' STMTS '}' {
    $$ = CreateWhileStmt($3, $8);
}

STRDECL : STRVAR ASSIGN PRINTSTRING {$$ = CreateStrAssignStatement($1, $3);}
| STRVAR ASSIGN PRINTLINE {$$ = CreateStrAssignStatement($1, $3);}
DECL : VAR ASSIGN EXPRESSION  { $$ = CreateAssignStatement($1, $3); }

OUTPUT : PRINT PRINTSTRING  { $$ = CreatePrintStmt($2); }
OUTPUT : PRINT PRINTLINE { $$ = CreatePrintStmt($2); }
OUTPUT : PRINT {
    $$ = CreatePrintStmt(
        AddPrintable(CreatePrintList(), CreateString(" ")));
}

PRINTSTRING : PRINTLINE STRING {$$ = AddPrintable($1, CreateString($2));}
PRINTLINE : PRINTSTRING EXPRESSION {$$ = AddPrintable($1, $2);}

PRINTSTRING : STR {$$ = AddPrintable(CreatePrintList(), CreateString($1));}
PRINTLINE : EXPRESSION {$$ = AddPrintable(CreatePrintList(), $1);}

STR : STRING {$$ = CreateString($1);}
    | STRVAR { $$ = CreateStrVariable($1);}

EXPRLIST : EXPRESSION { $$ = CreateNumericalList($1); }
         | EXPRLIST ',' EXPRESSION { $$ = AddNumericalToList($1, $3); }

EXPRESSION : EXPR  {$$ = $1;}
           | COMP  {$$ = $1;}
           | STATS {$$ = $1;}

STATS : ADDFUNC '(' EXPRLIST ')' { $$ = CreateAddFunction($3); }
      | MEANFUNC '(' EXPRLIST ')' { $$ = CreateMeanFunction($3); }
      | STDFUNC '(' EXPRLIST ')' { $$ = CreateStdFunction($3); }

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

NUMBER : '(' EXPRESSION ')'  {$$ = $2;}
NUMBER : NUM  {$$ = CreateDouble($1);}
NUMBER : VAR  {$$ = CreateVariable($1);}

%%
