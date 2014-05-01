#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "enums.h"

using namespace std;

class lexical
{
	protected:

		string wordCheck;

	public:

		lexical();

		void checkReserve(const string &);

		void addLexical(const string &, const string &);

		void addLexical(const string &, WordType);

		bool checkMe(const string &);

		void addMe(const string &, const string &);

};
