/*test for wordScanner and wordDfa
 * */
 
 #include "wordDfa.h"
 #include "lexical.h"
 #include <fstream>
 #include <string>
 
 using namespace std;
 
 int main()
 {
	 ifstream readMe;
	 
	 wordDfa dfa;
	 lexical lex;
	 
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
				
				cout << "yup!!!\n\n";
			}
			else
			{
				cout << "nope!!!\n";
			}
			
		}//end of while(!readMe.eof())	 
	 }
	 else
	 {
		 cout << "file could not be read..." << endl;
	 }
	 
		return 0;
 }
