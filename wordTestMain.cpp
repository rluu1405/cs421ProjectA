/*test for wordScanner and wordDfa
 * */
 
 #include "wordDfa.h"
 #include "lexical.h"
 #include "pDfa.h"
 #include <fstream>
 #include <string>
 
 using namespace std;
 
 int main()
 {
	 ifstream readMe;
	 
	 wordDfa dfa;
	 lexical lex;
	 pDfa period;
	 string userInput = " ";
	 
	 string testMe = " ";
	 
	 cout << "name of file: \n";
	 cin >> userInput;
	 
	 /*file reader
	  * opens and reads the words into the scanner
	  * */
	
	readMe.open(userInput.c_str());
	 
	 if(readMe.is_open())
	 {
		while(!readMe.eof())
		{
			
			readMe >> testMe;
			
			/*if the word is true 
			* pass to a function that first checks for the reserved words
			* the check to see if it is in the dictionary (lexicon). if it
			* is not in the dictionary already, then it adds the new word 
			* into the dictionary.
			* */
	 
			if(dfa.scanMe(testMe))
			{
				
				lex.checkReserve(testMe);
				
				//cout << "yup!!!\n\n";
			}
			else
			{
				if(period.scanPeriod(testMe))
				{
					lex.checkReserve(testMe);
				}
				else
				{
					cout << "Lexical Error!!!\n";
				}
			}
			
		}//end of while(!readMe.eof())	 
	 }
	 else
	 {
		 cout << "file could not be read..." << endl;
	 }
	 
		return 0;
 }
