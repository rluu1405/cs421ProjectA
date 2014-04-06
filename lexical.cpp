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
	
	string token_type = " ";
	
	reserveFile.open("reservedWord.txt");
	
	if(reserveFile.is_open())
	{
		while(!reserveFile.eof())
		{
			
			reserveFile >> reserve;
			
			reserveFile >> token_type;
			
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
					break;

				case 'i':
				case 'e':
					addLexical(word, "WORD2");
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

/*this prints out the result of the word
* */

				if(word == reserve)
				{
		//cout << "------------------->> "<< word << " " << token_type << endl;

					addLexical(reserve, token_type);

					break;
				}

			}
			
			
		}
		
		reserveFile.close();
		
	}
	else
	{
		cout << "needs to be reservedWord.txt" << endl;
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


