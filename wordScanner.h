/*
 * 
 * */
 
 #include <iostream>
 #include <string>
 #include <vector> //maybe use this
 #include <fstream>
 
 using namespace std;
 
 class wordScanner
 {
	protected:
		string word;
	public:
		wordScanner();
		
		bool scanMe(const &string);
	 
 };
