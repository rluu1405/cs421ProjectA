#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "enums.h"
#include "tokenObject.h"

using namespace std;

class lexical
{
	protected:

		string wordCheck;
        fstream DictionaryFile;
        fstream ReservedWordFile;

        map<string, string> Dictionary;
        map<string, TokenObject> ReservedWord;
        //vector<string> DictionaryContents;
        //vector<string> ReservedWordFileContents;

        void ReadDictionary();
        void SaveDictionary();
        void ReadReservedWord();
	public:

		lexical();
		~lexical();

		TokenObject ProcessWord(const string &);

		//void addLexical(const string &, const string &);
        string SanitizeEnglish(const string&);
		void OutputWord(const string &, WordType);

		//bool CheckWordAgainstDictionary(const string &);

		void AddWordToDictionary(const string &, const string &);

};
