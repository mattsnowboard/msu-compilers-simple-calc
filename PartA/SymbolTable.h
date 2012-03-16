#ifndef _SYMBOLTABLE_H
#define _SYMBOLTABLE_H


#include <map>
#include <string>
#include "Numerical.h"

class SymbolTable 
{
public:

	bool DoesExist( std::string );
	Numerical * GetVal( std::string );
	void AddVar( std::string, Numerical* );

    // Singleton pattern
    static SymbolTable& GetInstance()
    {
        static SymbolTable instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
	
	void Clear();

    ~SymbolTable();

private:
    void Cleanup();

    SymbolTable() {}
    SymbolTable(const SymbolTable &);
    SymbolTable& operator=(const SymbolTable &);

	std::map<std::string,Numerical*> _VarMap;	
};

#endif
