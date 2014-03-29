/*wordDfa.h
 * */
 
 #include <iostream>
 #include <string>
 
 using namespace std;
 
 class wordDfa
 {
	protected:
	
		char wordChar;
		
		unsigned int state;
		
	public:
	
		wordDfa();
		
		bool scanMe(const string &);
		
		bool checkState(const char &);
		
		bool q0(const char &);
		
		bool q1(const char &);
		
		bool q2(const char &);
		
		bool q3(const char &);
		
		bool q4(const char &);
		
		bool q5(const char &);
		
		bool q6(const char &);
		
		bool q7(const char &);
		
 };
 
 
