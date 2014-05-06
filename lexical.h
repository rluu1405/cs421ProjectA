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
        fstream DictionaryFile;
        fstream ReservedWordFile;

	public:

		lexical();
		~lexical();

		void checkReserve(const string &);

		//void addLexical(const string &, const string &);

		void OutputWord(const string &, WordType);

		bool CheckWordAgainstDictionary(const string &);

		void AddWordToDictionary(const string &, const string &);

};
