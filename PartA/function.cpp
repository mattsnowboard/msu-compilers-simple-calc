
#include <stack>
#include <cstring>


#include "Program.h"

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
#include "StatementList.h"
#include "IfStmt.h"
#include "WhileStmt.h"
#include "String.h"
#include "SymbolTable.h"
#include "PrintList.h"
#include "UserCommandStmt.h"

extern "C" {
#include "functions.h"    
}

//std::stack<Statement*> ToCleanUp;
Program program;

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

extern "C" void * CreateStatementList(void *stmt)
{
    StatementList* s = new StatementList;
    s->AddItem((Statement*)stmt);
    return s;
}

extern "C" void * AddStatementToList(void *stmtlist, void *stmt)
{
    StatementList* s = (StatementList*)stmtlist;
    s->AddItem((Statement*)stmt);
    return s;
}

extern "C" void * CreateIfStmt(void *cond, void *stmtlist)
{
    IfStmt* ifst = new IfStmt((Numerical*)cond, (StatementList*) stmtlist);
    return ifst;
}

extern "C" void * CreateWhileStmt(void *cond, void *stmtlist)
{
    WhileStmt* wst = new WhileStmt((Numerical*)cond, (StatementList*)stmtlist);
    return wst;
}

extern "C" void * CreatePrintStmt(void *plist)
{
    // @todo
    return plist;
}

extern "C" void * CreateAssignStatement(const char *name, void *expr)
{
    // @todo
    return expr;
}

/*extern "C" void PushToStack(void *expr)
{
    ToCleanUp.push((Statement*) expr);
    }*/

/*extern "C" void PrintExpr(void *expr)
{
    Expr *e = (Expr *)expr;
    e->Evaluate();
    std::cout << "Answer: " << *e << std::endl;
}

extern "C" void AssignVariable(const char *name, void *expr)
{
    SymbolTable &s = SymbolTable::GetInstance();
    s.AddVar(name, (Numerical *) expr);
    }*/

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

extern "C" void ExecuteStatement(void *stmt)
{
    Statement* s = (Statement*)stmt;
    program.AddStatement(s);
    program.ExecuteTop();
}


/*extern "C" void PrintPrintList(void *plist)
{
    PrintList *p = (PrintList *)plist;
    std::cout << *p << std::endl;
}

extern "C" void * CreateIf(void *cond, void *stmts) 
{
	IfStmt *p = new IfStmt((Numerical *)cond, (StatementList *)stmts);
	return p;
    } */


extern "C" void * CreateUserCommand(const char *command)
{
    UserCommandStmt* s = new UserCommandStmt(command);
    return s;
}

