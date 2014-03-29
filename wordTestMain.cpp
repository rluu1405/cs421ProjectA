/*test for wordScanner and wordDfa
 * */
 
 #include "wordDfa.h"
 
 using namespace std;
 
 int main()
 {
	 
	 wordDfa dfa;
	 
	 string userInput = " ";
	 
	 cin >> userInput;
	 
	 /*the word is either valid or not*/
	 
	 if(dfa.scanMe(userInput))
	 {
		 cout << "yup!!!\n";
	 }
	 else
	 {
		 cout << "nope!!!\n";
	 }
	 
	 return 0;
 }
