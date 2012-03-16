
#include <stack>
#include <cstring>


#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "LessThan.h"
#include "GreaterThan.h"
#include "Exponent.h"
#include "Negate.h"
#include "Sqrt.h"
#include "Value.h"
#include "Variable.h"
#include "Statement.h"
#include "Conditional.h"
#include "IfStmt.h"
#include "String.h"
#include "SymbolTable.h"
#include "PrintList.h"
#include "ExitException.h"


extern "C" {
#include "functions.h"    
}

std::stack<Expr*> ToCleanUp;
std::stack<PrintList*> ToCleanUpPrint;

extern "C" void * CreateNegate(void *expr)
{
    Negate *node = new Negate((Numerical *)expr);
    return node;
}

extern "C" void * CreateSqrt(void *expr)
{
    Sqrt *node = new Sqrt((Numerical *)expr);
    return node;
}

extern "C" void * CreateAdd(void *left, void *right)
{
    Add *node = new Add((Numerical *)left, (Numerical *)right);
    return node;
}

extern "C" void * CreateSubtract(void *left, void *right)
{
    Subtract *node = new Subtract((Numerical *)left, (Numerical *)right);
    return node;
}

extern "C" void * CreateDivide(void *left, void *right)
{
    Divide *node = new Divide((Numerical *)left, (Numerical *)right);
    return node;
}

extern "C" void * CreateMultiply(void *left, void *right)
{
    Multiply *node = new Multiply((Numerical *)left, (Numerical *)right);
    return node;
}

extern "C" void * CreateExponent(void *left, void *right)
{
    Exponent *node = new Exponent((Numerical *)left, (Numerical *)right);
    return node;
}

extern "C" void * CreateLessThan(void *left, void *right)
{
    LessThan *node = new LessThan((Numerical *)left, (Numerical *)right);
    return node;
}

extern "C" void * CreateGreaterThan(void *left, void *right)
{
    GreaterThan *node = new GreaterThan((Numerical *)left, (Numerical *)right);
    return node;
}

extern "C" void * CreateDouble(double d)
{
    Value *node = new Value(d);
    return node;
}

extern "C" void * CreateVariable(const char *name)
{
    Variable *node = new Variable(name);
    return node;
}

extern "C" void * CreateString(const char *s)
{
    String *node = new String(s);
    return node;
}

extern "C" void PushToStack(void *expr)
{
    ToCleanUp.push((Expr*) expr);
}

extern "C" void PushToPrintStack(void *pl)
{
    ToCleanUpPrint.push((PrintList *) pl);
}

extern "C" void PrintExpr(void *expr)
{
    Expr *e = (Expr *)expr;
    e->Evaluate();
    std::cout << "Answer: " << *e << std::endl;
}

extern "C" void AssignVariable(const char *name, void *expr)
{
    SymbolTable &s = SymbolTable::GetInstance();
    s.AddVar(name, (Numerical *) expr);
}

extern "C" void * AddPrintable(void *plist, void *expr)
{
    PrintList *p = (PrintList *)plist;
    p->AddItem((Expr *)expr);
    return p;
}

extern "C" void * CreatePrintList()
{
    PrintList *p = new PrintList;
    return p;
}

extern "C" void PrintPrintList(void *plist)
{
    PrintList *p = (PrintList *)plist;
    std::cout << *p << std::endl;
}

extern "C" void * CreateIf(void *cond, void *stmts) 
{
	IfStmt *p = new IfStmt((Numerical *)cond, (StatementList *)stmts);
	return p;
} 

extern "C" void PrintUserSupport(const char *command)
{
    if(!strcmp(command, "exit"))
    {
        // this gave me an error (exit not declared)
        // I'm tryign an exception approach but revert if you have a better
        // idea
        //exit(1);
        throw ExitException();
    }
    if(!strcmp(command, "help"))
    {
         std::cout << "*************SimpleCalc Help*************" << std::endl << std::endl;
         std::cout << "*************Available Commands**********" << std::endl;
         std::cout << "exit       :     Quits the current SimpleCalc program or command prompt" << std::endl;
         std::cout << "clear      :     Clears the current Symbol Table, resetting variable declarations.\n\
                 Note, all variables must be redeclared before use, otherwise they default to value 0." << std::endl;
         std::cout << "help       :     Print this help message." << std::endl << std::endl;
         std::cout << "*************Programming Grammar*********" << std::endl;
         std::cout << "Comments   :     Lines beginning with # are ignored by the interpreter and are comments.\n\
                 Any text betwen  and  are ignored by the interpreter and are also comments." << std::endl;
         
         std::cout << "Variables  :     A variable is declared by using the \":=\" operator.\n\
                 EXAMPLE:\n\
                 a:=2" << std::endl;    
    }
    if(!strcmp(command, "clear"))
    {
        SymbolTable &theTable = SymbolTable::GetInstance();
        theTable.Clear();
    }
}

