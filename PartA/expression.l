%{
/*
 * Lex file for expression.y
 */

#include <stdio.h>
#include "y.tab.h"

%}
%%

 // @todo Update this
[0-9]+(\.[0-9]*)? { yylval = atoi(yytext); return NUM; }
[a-zA-Z]+[a-zA-Z0-9]* {return VAR;}
[ \t]+ {}
(^|\(|\)|\*|<|>|-|\+) {return yytext;}
\n     { return '\n'; }
\r     {}
.      { return yytext[0]; }
#.*	{/*IGNORE COMMENT*/}
%%

int yywrap()
{
    return 1;
}
