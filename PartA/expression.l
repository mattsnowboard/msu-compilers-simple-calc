%{
/*
 * Lex file for expression.y
 */

#include <stdio.h>
#include "y.tab.h"


%}

%s COMMENT

%%

(sqrt) {return SQRT;}
(if) {return IF;}
(while) {return WHILE;}
(print) {return PRINT;}
(add) {return ADDFUNC;}
(mean) {return MEANFUNC;}
(std) {return STDFUNC;}
(help|exit|clear) {yylval.sval = strdup(yytext); return USERSUPPORT;}
[0-9]+(\.[0-9]*)? { yylval.ival = atof(yytext); return NUM; }
[a-zA-Z]+[a-zA-Z0-9]* { yylval.sval = strdup(yytext); return VAR;}
(\^|\(|\)|\*|<|>|-|\+|\/|\}|\{|\,) {return yytext[0];}
(:=) {return ASSIGN;}

^[ \t]*\n {/* ignore blank lines */}
[ \t]+ {}

 /* this was a regex I looked up for strings
 it's nice because we can return a single "string" token
 so the grammer doesn't need to piece together the characters */
\"(\\.|[^\\\"])*\" { yylval.sval = strdup(yytext); return STRING; }

\n     { return '\n'; }
\r     {}

#.*\n	{/*ignore comments*/}
%%

int yywrap()
{
    return 1;
}
