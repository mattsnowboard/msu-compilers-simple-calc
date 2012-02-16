%{
/*
 * Lex file for expression.y
 */

#include <stdio.h>
#include "y.tab.h"

%}
%%

 // @todo Update this
[0-9]+ { yylval = atoi(yytext); return NUM; }
[ \t]+ {}
\n     { return '\n'; }
\r     {}
.      { return yytext[0]; }

%%

int yywrap()
{
    return 1;
}
