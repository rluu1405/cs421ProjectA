#include "lexical.h"
#include "tokenObject.h"
#include "enums.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <unistd.h>
using namespace std;

lexical::lexical()
{
	wordCheck = " "; //i don't know if we need this

    ReadDictionary();
    ReadReservedWord();
}

lexical::~lexical()
{
    SaveDictionary();
}

void lexical::ReadDictionary()
{
    string jWord;
    string eWord;
    string type;
    string inputLine;
    stringstream line(stringstream::in | stringstream::out);
    char pointer[500];

	DictionaryFile.open("dictionary.txt", fstream::in);

	if(DictionaryFile.is_open() == true)
    {
        while(DictionaryFile.eof() == false)
        {
            //DictionaryFile>>inputLine;
            DictionaryFile.getline(pointer, 500);

            inputLine = pointer;
            //DictionaryContents.push_back(inputLine);

            line << inputLine;

            line >> jWord;
            line >> eWord;

            Dictionary.insert(make_pair(jWord, eWord));
            line.clear();
        }
    }
	DictionaryFile.close();
}

void lexical::SaveDictionary()
{
	DictionaryFile.open("dictionary.txt", fstream::out);

	if(DictionaryFile.is_open() == false)
    {
        throw "Failed to open dictionary.txt!";
    }

    for (map<string, string>::iterator it = Dictionary.begin(); it != Dictionary.end(); ++it)
    {
        DictionaryFile<<it->first<<"\t"<<it->second<<"\n";
    }


	DictionaryFile.close();
}

void lexical::ReadReservedWord()
{
    string jWord;
    string eWord;
    string type;
    string inputLine;
    stringstream line(stringstream::in | stringstream::out);
    char pointer[500];

	ReservedWordFile.open("reserved.txt", fstream::in);

	if(ReservedWordFile.is_open() == false)
    {
        throw "Failed to open reserved.txt!";
    }
    else
    {
        TokenObject payload;
        while(ReservedWordFile.eof() == false)
        {
            //ReservedWordFile>>inputLine;
            ReservedWordFile.getline(pointer, 500);
            inputLine = pointer;
            //ReservedWordFileContents.push_back(inputLine);

            line << inputLine;

            line >> jWord;
            line >> eWord;
            if(eWord[0] == '(')
            {
                line >> type;
            }
            else
            {
                type = eWord;
                eWord = " ";
            }
            Dictionary.insert(make_pair(jWord, SanitizeEnglish(eWord)));
            payload.Word = jWord;
            payload.Token = WordTokenClass::convert(type);
            payload.English = eWord;
            ReservedWord.insert(make_pair(jWord, payload));
            line.clear();
        }
    }
	ReservedWordFile.close();
}

/* the checkReserve opens the reservedWord.txt and
 *
 * checks to see if the word being passed into the
 *
 * function is already part of the reserved words.
 *
 * if it is then it classifies it as some token type.
 *
 * but if it is not part of the reserved words, then it
 *
 * it is passed into addLexical function were it is added into
 *
 * the dictionary
 * */

TokenObject lexical::ProcessWord(const string &word)
{
	int wordLength = word.size()-1;

    stringstream line(stringstream::in | stringstream::out);

	string reserve = " ";

	string others = " ";

	string token_string;

	WordType token_type;

    TokenObject result;
    /*
    for(unsigned int i=0; i< ReservedWordFileContents.size(); i++)
    {
        line.clear();
        line.str(ReservedWordFileContents[i]);
        line >> reserve;

        line >> token_string;

        if(token_string.at(0) == '(')
        {
            others = token_string;

            line >> token_string;
        }

        //add in error handling later
        token_type = WordTokenClass::convert(token_string);


        //once the token has hit the eofm im not sure if
        // i should append the eofm into the output file

        if(token_type == EOFM)
        {
            cout << "------------------->> " << "end of file marker" << endl;

            switch(word.at(wordLength))
            {
                case 'a':
                case 'u':
                case 'o':
                case 'n':
                    OutputWord(word, WORD1);
                    AddWordToDictionary(word, " ");
                    break;

                case 'i':
                case 'e':
                    OutputWord(word, WORD2);
                    AddWordToDictionary(word, " ");
                    break;

                case '.':
                    OutputWord(word, PERIOD);
                    break;

                default:
                    break;

            }

            break;

        }
        else
        {
            if(word == reserve)
            {

                if(token_type == PRONOUN || token_type == CONNECTOR)
                {
                    OutputWord(reserve, token_type);
                    //AddWordToDictionary(reserve, others);
                    break;
                }

                OutputWord(reserve, token_type);
                break;
            }
        }
    }
    */

    if(ReservedWord.count(word) == 0)
    {
        result.Word = word;
        switch(word.at(wordLength))
        {
            case 'a':
            case 'u':
            case 'o':
            case 'n':
                result.Token = WORD1;
                result.English = " ";
                OutputWord(word, WORD1);
                AddWordToDictionary(word, " ");
                break;

            case 'i':
            case 'e':
                result.Token = WORD2;
                result.English = " ";
                OutputWord(word, WORD2);
                AddWordToDictionary(word, " ");
                break;

            case '.':
                result.Token = PERIOD;
                result.English = " ";
                OutputWord(word, PERIOD);
                break;
            default:
                result.English = " ";
                result.Token = UNKOWN;
                break;
        }
    }
    else
    {
        result = ReservedWord[word];
        token_type = result.Token;
        if(token_type == PRONOUN || token_type == CONNECTOR)
        {
            AddWordToDictionary(result.Word, result.English);
        }

        OutputWord(result.Word, token_type);

    }
    return result;
}

void lexical::OutputWord(const string &word, WordType token)
{
	ofstream openFile;
	openFile.open("output.txt", ios::app);
	cout << "writing output...\n\n";

	openFile << word << setw(20) << WordTokenClass::convert(token) << "\t" << "\n\n";

	openFile.close();
}
//////////////////////////////////////////

string lexical::SanitizeEnglish(const string &english)
{
	string eng = " ";
    bool result = false;
    for(unsigned int i = 0; i<english.size(); i++)//while(i<english.size())
    {
        result=islower(english[i]) || isupper(english[i]);

        if(result == true)// english.at(i) >= 'a' && english.at(i) <= 'z')
        {
            eng += english[i];
            //i++;
        }
        else if(english[i] == '/')
        {
            eng += ",";
            //i++;
        }
        //else
        //{
            //i++;
            //cout<<"unrecognized character in "<<english<<"."<<endl;
            //eng = " ";
            //break;
        //}
    }
    return eng;
}

void lexical::AddWordToDictionary(const string &word, const string &english)
{
	//string eng = " ";

	//if(CheckWordAgainstDictionary(word) == false)
	if(Dictionary.count(word) == 0)
	{
	    Dictionary.insert(make_pair(word, SanitizeEnglish(english)));
	    //DictionaryContents.push_back(word+"\t"+SanitizeEnglish(english));
	}
	else
	{
		cout << "word is already in the dictionary" << endl;
	}

}

//not used
/*
bool lexical::CheckWordAgainstDictionary(const string &word)
{

	string checkFileInput = " ";
    stringstream line(stringstream::in | stringstream::out);

    for(unsigned int i = 0; i < DictionaryContents.size(); i++)
    {
        line.str(DictionaryContents[i]);
        line >> checkFileInput;
        if(checkFileInput == word)
		{
			return (true);
		}
    }

	return (false);
}
*/
