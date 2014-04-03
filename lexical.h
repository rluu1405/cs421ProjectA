#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class lexical
{
	protected:
		
		string wordCheck;
		
	public:
	
		lexical();
	
		void checkReserve(const string &);
		
		void addLexical(const string &);
	
};
