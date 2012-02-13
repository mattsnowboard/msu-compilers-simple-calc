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

vector<char*> sources;
vector<char*> target;
string buildPieces;
string buildPiecesS;

int main(int argc, char **argv)
{
  FILE *file;

  if(argc < 2)
  {
       fprintf(stderr, "Using Standard input: Use ^D to exit.\n");
       file = stdin; 
  } else {
	  file = fopen(argv[1], "r");
  }

  if(!file)
  {
      fprintf(stderr, "Unable to open file %s", argv[1]);
      return 1;
  }

  //cout << "Simple Bison 2.0!" << endl;

  yyin = file;

  cout << "digraph " << argv[1] << " {" << endl;
  do
    {
	
      yyparse();
    } while(!feof(yyin));
	cout << "}";

  return 0;
}


extern "C" void yyerror(char *s)
{ 
  cout << s << endl;
}

extern "C" void myfunction(char *s)
{
	cout << "Printing inside of C++ " << s << endl;
} 

extern "C" void addBuildFiles(char* s)
{
	string temp;
	temp = s;
	buildPieces = temp + " " + buildPieces;
	//buildPieces >> buildPiecesS;
}

extern "C" void addSRC(char* s)
{
	sources.push_back(s);
}

extern "C" void addTAR(char* s)
{
	target.push_back(s);
}

extern "C" void makeDot()
{
	for(int i = 0; i < target.size(); i++)
	{
		for(int j = 0; j < sources.size(); j++)
		{
			if(buildPieces.size() > 0)
				cout << "\""<< sources[j] << "\"->\"" << target[i] << "\"" << "[label =\"" << buildPieces << "\"]" << endl;
			else
				cout << "\""<< sources[j] << "\"->\"" << target[i] << "\"" << endl;
		}
	}
	
	buildPieces.clear();
	sources.clear();
	target.clear();
}