

#include <cstdio>
#include <iostream>
#include <string>
#include <stack>

#include "Expr.h"
#include "ExitException.h"

using namespace std;

extern "C" {
#include "y.tab.h"
    extern FILE *yyin;
    extern int yylex();
    extern int yyparse();
    extern char *yytext;

}

extern std::stack<Statement*> ToCleanUp;

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
        try {
            yyparse();
        } catch (ExitException &e) {
            // exit command
            return 0;
        }
    } while (!feof(yyin));

    while (!ToCleanUp.empty()) {
        Statement *e = ToCleanUp.top();
        delete e;
        ToCleanUp.pop();
    }

    return 0;
}

extern "C" void yyerror(char *s)
{ 
    cout << s << endl;
}
