#ifndef _SYMBOLTABLE_H
#define _SYMBOLTABLE_H


#include <map>
#include <string>


using namespace std;


class SymbolTable 
{
public:

	bool DoesExist( string );
	int& GetVal( string );
	void AddVar( string, int );


private:
	map<string,int> VarMap;
};

#endif
