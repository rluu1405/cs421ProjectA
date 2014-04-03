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
	
	string reserve = " ";
	
	string token_type = " ";
	
	reserveFile.open("reservedWord.txt");
	
	if(reserveFile.is_open())
	{
		while(!reserveFile.eof())
		{
			
			reserveFile >> reserve;
			
			reserveFile >> token_type;
			
			if(token_type == "eofm")
			{
				cout << "------------------->> " << "end of file marker" << endl;
				
				//addLexical(word);
				
				break;
			}
			else
			{
				
				/*this prints out the result of the word 
				 * */
				
				if(word == reserve)
				{
					cout << "------------------->> "<< word << " " << token_type << endl;
				
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

void lexical::addLexical(const string &word)
{
	ofstream openFile;
	
	
}


