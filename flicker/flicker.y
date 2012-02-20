%{
/*
 * Flicker Application
*/
#include "stdio.h"
#include "functions.h"
%}

%union {
	void *pval;		// Pointer to tree nodes
	int   ival;		// Integer values
	char *sval;		// String values
}

%token FLICKER PRINT
%token<ival> INT_VALUE
%token<sval> STR_VALUE
 
%type<pval> program stmts stmt V

%%
program : stmts			{setRoot($1);}
;
stmts 	: stmts '\n' stmt 	{$$ = createNodeStmts($1, $3);}
	| stmt            	{$$ = $1;}
;
stmt 	:                  	{$$ = NULL;}
	| FLICKER V V      	{$$ = createNodeFlicker($2, $3);}
;
V 	: INT_VALUE           	{$$ = createNodeInt($1);}
	| STR_VALUE           	{$$ = createNodeStr($1);  free($1);}
%%
