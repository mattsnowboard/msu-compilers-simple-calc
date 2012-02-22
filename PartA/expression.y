%{
/*
 * Expression evaluator
 */
#include "functions.h"
#include "stdio.h"

//#define YYSTYPE int

%}

%union {
	void *pval;		
	int   ival;		
	char *sval;		
}

%token PRINT 
%token<ival> NUM
%token<sval> STRING VAR ASSIGN SQRT

%type<pval> STMT DECL EXPR STMTLINE EXPON UNARY TERM LINE  '<' '+' '-' '>' '*' '/' '^' '('')'

%%

STMT : STMT '\n'	{}
     | STMT '\n' STMTLINE  {createNodeStmts($1, $3);}
     | STMTLINE  {}

STMTLINE : DECL  {}
	 | LINE  {}
	 | OUTPUT {}

DECL : VAR ASSIGN EXPR  {createAssignmentN($1,$3);}

OUTPUT : PRINT PRINTABLE  {}

PRINTABLE : STRING  {}
PRINTABLE : PRINTABLE STRING  {}
PRINTABLE : LINE  {}
PRINTABLE : STRING LINE  {}

LINE : EXPR  {setRoot($1);}
LINE : COMP  {}

COMP : EXPR '<' EXPR  {createLessThenN($1,$3); }
COMP : EXPR '>' EXPR  {createGrtrThenN($1,$3);}

EXPR : EXPR '+' TERM  {createAddNode($1,$3);}
EXPR : EXPR '-' TERM {createMinusNode($1,$3);}
EXPR : TERM  {}

TERM : TERM '*' EXPON  {createMultiplyNode($1,$3);}
TERM : TERM '/' EXPON  {createDivideNode($1,$3);}
TERM : EXPON  {}

EXPON : EXPON '^' UNARY  {createEXPNode($1,$3);}
EXPON : UNARY  {}

UNARY : '(' EXPR ')'  {createParenNode($2); }
UNARY : NUM  {createNodeInt($1);}
//UNARY : SQRT NUM  {createSqrtNode($2)}
UNARY : '-' NUM  {createNodeStr($1); createNodeInt($2);}
UNARY : VAR  {createNodeStr($1);}
UNARY : '-' VAR  {createNodeStr($1); createNodeStr($2);}

%%
