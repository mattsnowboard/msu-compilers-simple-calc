
#include "SymbolTable.h"
//
#include "Expr.h"
#include <map>
#include <string>
#include "Numerical.h"

void SymbolTable::AddVar(std::string Var, Numerical* exprssn )
{
    std::pair<std::map<std::string, Numerical*>::iterator, bool> ret
        = _VarMap.insert(std::make_pair(Var, exprssn));
    if (ret.second == false) {
        // we are overwriting, that is fine as long as we clean it up
        Numerical *cleanMe = _VarMap[Var];
        _VarMap[Var] = exprssn;
        delete cleanMe;
    }

}

Numerical* SymbolTable::GetVal( std::string Var )
{
    return _VarMap[Var];
}

bool SymbolTable::DoesExist( std::string Var )
{
    return (_VarMap.find(Var) != _VarMap.end());
}

SymbolTable::~SymbolTable()
{
    for (std::map<std::string, Numerical*>::iterator it = _VarMap.begin();
         it != _VarMap.end();
         ++it) {
        if (it->second != NULL) {
            delete it->second;
        }
    }
}
