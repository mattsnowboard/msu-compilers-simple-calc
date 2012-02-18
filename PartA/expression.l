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
_[0-9a-zA-Z]+ {return VAR;}
[ \t]+ {}
(^|\(|\)|\*|<|>|-|\+) {return yytext;}
\n     { return '\n'; }
\r     {}
.      { return yytext[0]; }

%%

int yywrap()
{
    return 1;
}
