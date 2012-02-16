%{
/*
 * Expression evaluator
 */

#include "stdio.h"
#define YYSTYPE int

%}

%token NUM VAR ASSIGN SQRT PRINT STRING

%%

STMT : STMT '\n'  {}
STMT : STMT '\n' STMTLINE  {}
STMT : STMTLINE  {}

STMTLINE : DECL  {}
STMTLINE : LINE  {}
STMTLINE : OUTPUT {}

DECL : VAR ASSIGN EXPR  {}

OUTPUT : PRINT PRINTABLE  {}

PRINTABLE : STRING  {}
PRINTABLE : PRINTABLE STRING  {}
PRINTABLE : LINE  {}
PRINTABLE : STRING LINE  {}

LINE : EXPR  {}
LINE : COMP  {}

COMP : EXPR '<' EXPR  {}
COMP : EXPR '>' EXPR  {}

EXPR : EXPR '+' TERM  {}
EXPR : EXPR '-' TERM {}
EXPR : TERM  {}

TERM : TERM '*' EXPON  {}
TERM : TERM '/' EXPON  {}
TERM : EXPON  {}

EXPON : EXPON '^' UNARY  {}
EXPON : UNARY  {}

UNARY : '(' EXPR ')'  {}
UNARY : NUM  {}
//UNARY : SQRT NUM  {}
UNARY : '-' NUM  {}

%%
