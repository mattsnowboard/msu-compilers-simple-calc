#include <cstdio>
#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

extern "C" {
#include "y.tab.h"
    extern FILE *yyin;
    extern int yylex();
    extern int yyparse();
    extern char *yytext;
}

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

    return 0;
}

extern "C" void yyerror(char *s)
{ 
    cout << s << endl;
}
