%{
/*
 * Lex file for expression.y
 */

#include <stdio.h>
#include "y.tab.h"


%}

%s COMMENT

%%

 // @todo Update this
<INITIAL>(sqrt) {return SQRT;}
<INITIAL>(print) {return PRINT;}
<INITIAL>(help|exit|clear) {yylval.sval = strdup(yytext); return USERSUPPORT;}
<INITIAL>[0-9]+(\.[0-9]*)? { yylval.ival = atof(yytext); return NUM; }
<INITIAL>[a-zA-Z]+[a-zA-Z0-9]* { yylval.sval = strdup(yytext); return VAR;}
<INITIAL>[ \t]+ {}
<INITIAL>(\^|\(|\)|\*|<|>|-|\+) {return yytext[0];}
<INITIAL>(:=) {return ASSIGN;}

 /* this was a regex I looked up for strings
 it's nice because we can return a single "string" token
 so the grammer doesn't need to piece together the characters */
\"(\\.|[^\\\"])*\" { yylval.sval = strdup(yytext); return STRING; }

<INITIAL>\n     { return '\n'; }

\r     {}

<INITIAL>#	{BEGIN(COMMENT);}
<INITIAL>.      { return yytext[0]; }
<COMMENT>. {/*ignore*/}
<COMMENT>\n {BEGIN(INITIAL);}
%%

int yywrap()
{
    return 1;
}
