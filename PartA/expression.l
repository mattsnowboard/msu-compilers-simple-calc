%{
/*
 * Lex file for expression.y
 */

#include <stdio.h>
#include "y.tab.h"

%}

%s COMMENT STRING

%%

 // @todo Update this
<INITIAL>[0-9]+(\.[0-9]*)? { yylval = atoi(yytext); return NUM; }
<INITIAL>[a-zA-Z]+[a-zA-Z0-9]* {return VAR;}
<INITIAL>[ \t]+ {}
<INITIAL>(\^|\(|\)|\*|<|>|-|\+) {return yytext[0];}
<INITIAL>\" {BEGIN(STRING); }
\n     {BEGIN(INTIAL); return '\n'; }
\r     {}
<INITIAL>.      { return yytext[0]; }
<INITIAL>#	{BEGIN(COMMENT);}
<COMMENT>. {/*ignore*/}
%%

int yywrap()
{
    return 1;
}
