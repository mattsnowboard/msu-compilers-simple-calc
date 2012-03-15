#ifndef _SYMBOLTABLE_H
#define _SYMBOLTABLE_H


#include <map>
#include <string>
#include "Expr.h"

using namespace std;


class SymbolTable 
{
public:

	bool DoesExist( string );
	Expr* GetVal( string );
	void AddVar( string, Expr* );


private:
	std::map<string,Expr*> VarMap;	
};

#endif
