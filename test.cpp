/*test.cpp
 * testing reading file
 * */
 #include <iostream>
 #include <string>
 #include <fstream>
 
 using namespace std;
 
 int main()
 {
		string test = " ";
		string userInput = " ";
		unsigned int number = 0;
	
		//cin >> userInput;
		
		fstream supFile;
		
		supFile.open("random.txt"); //userInput.c_str()
		
		//if(supFile.is_open()){
			
			cout << "test" << endl;
			
			while(!supFile.eof())
			{
				getline(supFile, test);
				
				cout << test << endl;
				
				cout << number << endl;
				
				number++;
			}
			
			supFile.close();
	//}
		//else
		//{
			//cout << "no file...";
		//}
		
		return 0;
 }
 
