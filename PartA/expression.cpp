

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <unistd.h> // getopt

#include "Expr.h"
#include "ExitException.h"
#include "DotStatementVisitor.h"

using namespace std;

extern "C" {
#include "y.tab.h"
    extern FILE *yyin;
    extern int yylex();
    extern int yyparse();
    extern char *yytext;

}

//extern std::stack<Statement*> ToCleanUp;
extern Program program;

int main(int argc, char **argv)
{
    FILE *file;

//    if (argc < 2)
//    {
    fprintf(stderr, "Using Standard input: Use ^D to exit.\n");
    file = stdin; 
//    } else {
//        file = fopen(argv[1], "r");
//    }

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
            break;
        }
    } while (!feof(yyin));

    // now export the dot file optionally
    // look for -dot MyFile.dot
    if (argc > 2) {
        int opt;
        std::string dotFileName;
        while ((opt = getopt(argc, argv, "d:")) != -1) {
            switch (opt) {
            case 'd':
                dotFileName = optarg;
                break;
            default:
                break;
            }
        }

        if (!dotFileName.empty()) {
            std::ofstream dotfile(dotFileName.c_str());
            if (!dotfile) {
                std::cerr << "There was a problem creating dot file."
                          << std::endl;
            } else {
                DotStatementVisitor dsv(dotfile);
                dsv.Visit(program);
                // create the dot file by visiting the root
            }
        }
    }

/*    while (!ToCleanUp.empty()) {
        Statement *e = ToCleanUp.top();
        if (e) {
            delete e;
        }
        ToCleanUp.pop();
        }*/

    return 0;
}

extern "C" void yyerror(char *s)
{ 
    cout << s << endl;
}
