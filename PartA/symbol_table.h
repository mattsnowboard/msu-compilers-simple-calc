

#include <map>
#include <string>


using namespace std;


class SymbolTable {
private:
	map<string,int> symbolMap;
public:

	bool add( string, int);
	bool exists( string );
	bool update( string, int);
	int get(string);

};
