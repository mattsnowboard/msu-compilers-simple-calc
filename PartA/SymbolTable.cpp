
#include "SymbolTable.h"
#include "Numerical.h"
#include <map>
#include <string>

using namespace std;



void SymbolTable::AddVar(string Var, int Val )
{VarMap.insert(pair< string, int>(Var, Val));}

int &SymbolTable::GetVal( string Var )
{
    return VarMap[Var];
}

bool SymbolTable::DoesExist( string Var )
{   
    return (VarMap.find(Var) != VarMap.end());
}
/*
extern "C" void AddVarFromBison(string BVar, int BVal ) 
{VarMap.insert(pair< string, int>(BVar, BVal));}*/

