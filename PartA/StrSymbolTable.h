#ifndef _StrSymbolTable_H
#define _StrSymbolTable_H


#include <map>
#include <string>
#include "Numerical.h"

class StrSymbolTable 
{
public:

	bool DoesExist( std::string );
	Expr * GetStr(std::string );
	void AddVar( std::string, Expr* );

    // Singleton pattern
    static StrSymbolTable& GetInstance()
    {
        static StrSymbolTable instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
	
	void Clear();

    ~StrSymbolTable();

private:
    void Cleanup();

    StrSymbolTable() {}
    StrSymbolTable(const StrSymbolTable &);
    StrSymbolTable& operator=(const StrSymbolTable &);

	std::map<std::string,Expr*> _VarMap;	
};

#endif
