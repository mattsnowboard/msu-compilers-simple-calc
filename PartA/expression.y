%{
/*
 * Expression evaluator
 */

#include "stdio.h"
#define YYSTYPE int

%}

%token NUM VAR ASSIGN SQRT PRINT STRING

%%

STMT : LINE  {}
STMT : STMT '\n'  {}
STMT : STMT '\n' LINE  {}

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

EXPON : EXPON '^' SIGNED_NUM  {}
EXPON : SIGNED_NUM  {}

SIGNED_NUM : '(' EXPR ')'  {}
SIGNED_NUM : NUM  {}
SIGNED_NUM : '-' NUM  {}

%%
