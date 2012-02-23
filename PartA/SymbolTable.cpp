
#include "functions.h"
#include "SymbolTable.h"
//
#include "Expr.h"
#include <map>
#include <string>
#include "Numerical.h"

using namespace std;



void SymbolTable::AddVar(string Var, Expr* exprssn )
{VarMap.insert(pair< string, Expr*>(Var, exprssn));}

Expr* SymbolTable::GetVal( string Var )
{
    return VarMap[Var];
}

bool SymbolTable::DoesExist( string Var )
{   
    return (VarMap.find(Var) != VarMap.end());
}

extern "C" void AddVarFromBison(string BVar, int BVal ) 
{} //symTable.AddVar(pair< string, int>(BVar, BVal));

