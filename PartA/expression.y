%{
/*
 * Expression evaluator
 */

#include "stdio.h"
#define YYSTYPE int

%}

%token NUM VAR ASSIGN SQRT PRINT STRING

%%

S : E  {}
S : S '\n'  {}
S : S '\n' E  {}

E : E '+' T  {}
E : E '-' T {}
E : T  {}
T : T '*' N  {}
T : T '/' N  {}
T : N  {}

N : '(' E ')'  {}
N : NUM  {}
N : '-' NUM  {}

%%
