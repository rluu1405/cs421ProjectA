#include <iostream>
#include <iomanip>
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
	
		void addLexical(const string &, const string &);
			
		bool checkMe(const string &);
		
		void addMe(const string &, const string &);
	
};
