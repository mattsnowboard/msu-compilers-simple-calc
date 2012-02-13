%{
/*
* Lex file for simple.y
*/

#include "y.tab.h"

%}
%%
^\t {return COMMAND;}
\:	{return COLON;}
[a-zA-Z0-9_\.\-\+\/]+     {yylval.str_val = strdup(yytext); return FILENAME;}
\n    {return NEWLINE;}
.     { printf("");}
%%
int yywrap()
{
	return 1;
}
