%{
/*
 * Expression evaluator
 */

#include "stdio.h"
#define YYSTYPE int

%}

%token NUM

%%

S : E  {}
S : S '\n'  {}
S : S '\n' E  {}

E : E '+' T  {}
E : T  {}
T : T '*' NUM  {}
T : NUM  {}

%%
