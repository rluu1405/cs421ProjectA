#include "lexical.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <unistd.h>
using namespace std;

lexical::lexical()
{
	wordCheck = " "; //i don't know if we need this

    string inputLine;

	DictionaryFile.open("dictionary.txt", fstream::in);

	if(DictionaryFile.is_open() == false)
    {
        throw "Failed to open dictionary.txt!";
    }

	ReservedWordFile.open("reserved.txt", fstream::in);

	if(ReservedWordFile.is_open() == false)
    {
        throw "Failed to open reserved.txt!";
    }

    char pointer[500];
    while(DictionaryFile.eof() == false)
    {
        //DictionaryFile>>inputLine;
        DictionaryFile.getline(pointer, 500);
        inputLine = pointer;
        DictionaryContents.push_back(inputLine);
    }

    while(ReservedWordFile.eof() == false)
    {
        //ReservedWordFile>>inputLine;
        ReservedWordFile.getline(pointer, 500);
        inputLine = pointer;
        ReservedWordFileContents.push_back(inputLine);
    }

	ReservedWordFile.close();
	DictionaryFile.close();
}

lexical::~lexical()
{
	wordCheck = " "; //i don't know if we need this

	DictionaryFile.open("dictionary.txt", fstream::out);

	if(DictionaryFile.is_open() == false)
    {
        throw "Failed to open dictionary.txt!";
    }

    for (int i = 0; i< DictionaryContents.size(); i++)
    {
        DictionaryFile<<DictionaryContents[i]+"\n";
    }

	DictionaryFile.close();
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

void lexical::checkReserve(const string &word)
{
	int wordLength = word.size()-1;

    stringstream line(stringstream::in | stringstream::out);

	string reserve = " ";

	string others = " ";

	string token_string;

	WordType token_type;

    for(int i=0; i< ReservedWordFileContents.size(); i++)
    {
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


        /*once the token has hit the eofm im not sure if
         * i should append the eofm into the output file
         * */
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
                    AddWordToDictionary(reserve, others);
                    break;
                }

                OutputWord(reserve, token_type);
                break;
            }
        }
    }
}

void lexical::OutputWord(const string &word, WordType token)
{
	ofstream openFile;
	char* folder = get_current_dir_name();
	openFile.open((*folder + "output.txt"), ios::app);
	cout << "writing output...\n\n";
    delete folder;

	openFile << word << setw(20) << WordTokenClass::convert(token) << "\t" << "\n\n";

	openFile.close();
}
//////////////////////////////////////////

void lexical::AddWordToDictionary(const string &word, const string &others)
{

	string eng = " ";

	unsigned int i = 0;

	while(i<others.size())
	{
		if(others.at(i) >= 'a' && others.at(i) <= 'z')
		{
			eng += others.at(i);
			i++;
		}
		else
		{
			if(others.at(i) == '/')
			{
				eng += ", ";
				i++;
			}
			else
			{
				i++;
			}
		}
	}


	if(!CheckWordAgainstDictionary(word))
	{
	    DictionaryContents.push_back(word+"\t"+eng);

	}
	else
	{
		cout << "word is already in the dictionary" << endl;
	}

}

bool lexical::CheckWordAgainstDictionary(const string &word)
{

	string checkFileInput = " ";
    stringstream line(stringstream::in | stringstream::out);

    for(int i = 0; i < DictionaryContents.size(); i++)
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
