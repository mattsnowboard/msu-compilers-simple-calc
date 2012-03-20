
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
#include "StrVar.h"
#include "String.h"
#include "Statement.h"
#include "StatementList.h"

#include "IfStmt.h"
#include "WhileStmt.h"

#include "SymbolTable.h"
#include "StrSymbolTable.h"
#include "PrintList.h"
#include "UserCommandStmt.h"
#include "AssignStmt.h"
#include "PrintStmt.h"
#include "NumericalList.h"
#include "AddFunction.h"
#include "MeanFunction.h"
#include "StdFunction.h"

extern "C" {
#include "functions.h"    
}

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

extern "C" void * CreateAddFunction(void *list)
{
    AddFunction *node = new AddFunction((NumericalList*) list);
    return node;
}

extern "C" void * CreateMeanFunction(void *list)
{
    MeanFunction *node = new MeanFunction((NumericalList*) list);
    return node;
}

extern "C" void * CreateStdFunction(void *list)
{
    StdFunction *node = new StdFunction((NumericalList*) list);
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

extern "C" void * CreateStrVariable(const char *name)
{
    StrVar *node = new StrVar(name);
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

extern "C" void * CreateNumericalList(void *node)
{
    NumericalList* n = new NumericalList;
    n->AddItem((Numerical*)node);
    return n;
}

extern "C" void * AddNumericalToList(void *nodelist, void *node)
{
    NumericalList* n = (NumericalList*)nodelist;
    n->AddItem((Numerical*)node);
    return n;
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
    PrintStmt* pst = new PrintStmt((PrintList*) plist);
    return pst;
}

extern "C" void * CreateAssignStatement(const char *name, void *expr)
{
    AssignStmt* asn = new AssignStmt(name, (Numerical*)expr);
    return asn;
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

extern "C" void ExecuteStatement(void *stmt)
{
    Statement* s = (Statement*)stmt;
    program.AddStatement(s);
    program.ExecuteTop();
}

extern "C" void * CreateUserCommand(const char *command)
{
    UserCommandStmt* s = new UserCommandStmt(command);
    return s;
}

