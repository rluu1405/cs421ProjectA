#include "lexical.h"

using namespace std;

lexical::lexical()
{
	wordCheck = " "; //i don't know if we need this
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
	ifstream reserveFile;

	int wordLength = word.size()-1;

	string reserve = " ";

	string others = " ";

	string token_type = " ";

	reserveFile.open("reserved.txt");

	if(reserveFile.is_open())
	{
		while(!reserveFile.eof())
		{

			reserveFile >> reserve;

			reserveFile >> token_type;

			if(token_type.at(0) == '(')
			{
				others = token_type;

				reserveFile >> token_type;
			}




			/*once the token has hit the eofm im not sure if
			 * i should append the eofm into the output file
			 * */
			if(token_type == "eofm")
			{
				cout << "------------------->> " << "end of file marker" << endl;

				switch(word.at(wordLength))
				{
					case 'a':
					case 'u':
					case 'o':
					case 'n':
						addLexical(word, "WORD1");
						addMe(word, " ");
						break;

					case 'i':
					case 'e':
						addLexical(word, "WORD2");
						addMe(word, " ");
						break;

					case '.':
						addLexical(word, "PERIOD\n\n==========================================\n\n");
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

					if(token_type == "pronoun" || token_type == "connector")
					{
						addLexical(reserve, token_type);
						addMe(reserve, others);
						break;
					}

					addLexical(reserve, token_type);
					break;
				}
			}

		}

		reserveFile.close();

	}
	else
	{
		cout << "needs to be reserved.txt" << endl;
	}

}

/* if the word is not part of the reserved word it is passed
 *
 * over to the addLexical to be added into the dictionary
 * */

void lexical::addLexical(const string &word, const string &token)
{
	ofstream openFile;

	openFile.open("output.txt", ios::app);

	cout << "writing output...\n\n";

	openFile << word << setw(20) << token << "\t" << "\n\n";

	openFile.close();
}

//////////////////////////////////////////

void lexical::addMe(const string &word, const string &others)
{

	string eng = " ";

	unsigned int i = 0;

	ofstream addIt;

	addIt.open("dictionary.txt", ios::app);

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



	if(!checkMe(word))
	{
		addIt << word << setw(20) << eng << endl;

	}
	else
	{
		cout << "word is already in the dictionary" << endl;

	}

	addIt.close();
}

bool lexical::checkMe(const string &word)
{
	ifstream check;

	check.open("dictionary.txt");

	string checkWord = " ";

	while(!check.eof())
	{
		check >> checkWord;

		if(checkWord == word)
		{
			return (true);
		}
	}

	check.close();

	return (false);
}
