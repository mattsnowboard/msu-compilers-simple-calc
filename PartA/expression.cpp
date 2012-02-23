

#include <cstdio>
#include <iostream>
#include <string>
#include <stack>

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
#include "String.h"

using namespace std;

extern "C" {
#include "y.tab.h"
#include "functions.h"
    extern FILE *yyin;
    extern int yylex();
    extern int yyparse();
    extern char *yytext;

}

std::stack<Expr*> ToCleanUp;

int main(int argc, char **argv)
{
    FILE *file;

    if (argc < 2)
    {
        fprintf(stderr, "Using Standard input: Use ^D to exit.\n");
        file = stdin; 
    } else {
        file = fopen(argv[1], "r");
    }

    if (!file)
    {
        fprintf(stderr, "Unable to open file %s", argv[1]);
        return 1;
    }

    cout << "Expression Calculator!" << endl;

    yyin = file;

    do
    {
        yyparse();
    } while (!feof(yyin));

    while (!ToCleanUp.empty()) {
        Expr *e = ToCleanUp.top();
        delete e;
        ToCleanUp.pop();
    }

    return 0;
}

extern "C" void yyerror(char *s)
{ 
    cout << s << endl;
}

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
    Variable *node = new Variable(name, NULL);
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

extern "C" void PrintExpr(void *expr)
{
    Expr *e = (Expr *)expr;
    e->Evaluate();
    std::cout << *e << std::endl;
}
