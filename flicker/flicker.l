%{
/*
* Lex file for flicker.y
*/

#include <stdio.h>
#include "y.flicker.h"

%}
%%
flicker		{return FLICKER;}
print       	{return PRINT;}
[0-9]+      	{yylval.ival = atoi(yytext); return INT_VALUE;}
\"[^\"\n]+\"	{
			int len = strlen(yytext) - 2; 
			yylval.sval = malloc(len + 1); 
			strncpy(yylval.sval, yytext+1, len); 
			yylval.sval[len] = 0; 
			return STR_VALUE;
		}
" "		{}
"\t"		{}
"\n"	    	{return '\n';}
.           	{return yytext[0];}
%%

int yywrap()
{
	return 1;
}

