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
	int   ival;		
	char *sval;		
}

%token PRINT 
%token<ival> NUM
%token<sval> STRING VAR ASSIGN SQRT

%type<pval> STMT DECL EXPR STMTLINE EXPON UNARY TERM LINE COMP NUMBER

%%

STMT : STMT '\n'	{}
     | STMT '\n' STMTLINE  {}
     | STMTLINE  {}

STMTLINE : DECL  {}
     | LINE  {PrintExpr($1);}
	 | OUTPUT {}

DECL : VAR ASSIGN EXPR  {
    AssignVariable($1, $3);
    // NOTE: we don't clean up EXPR, it is owned by SymbolTable
}

OUTPUT : PRINT PRINTABLE  {}

PRINTABLE : STRING  {}
PRINTABLE : PRINTABLE STRING  {}
PRINTABLE : LINE  {}
PRINTABLE : STRING LINE  {}

LINE : EXPR  {$$ = $1; PushToStack($1);}
LINE : COMP  {$$ = $1; PushToStack($1);}

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
