#include "wordDfa.h"

using namespace std;

wordDfa::wordDfa()
{
	wordChar = ' ';
	state = 0;
}

/*note of add:
 * the add of the scanMe was due to 
 * not being able to keep the state from 
 * reverting back to zero. this is only temporary....
 * */
 
bool wordDfa::scanMe(const string &wordToTest)
 {
	 
	 wordDfa dfa;
	 
	 unsigned int i = 0;
	 
	// bool validLetter = true;
	 
	 while(i<wordToTest.size())
	 {
		 /*pass each character over to the 
		  * wordDfa. If the return is false the scan stops
		  * and the word is considered not a valid word. Otherwise
		  * it is true and will continue on to the next letter.
		  * The process is continued until the loop has reached the last
		  * letter of the word.
		  * */
		  
		//  validLetter = dfa.checkState(wordToTest.at(i));
		
			/*note to self:
			 * 
			 * the current state in the wordDfa resets, so 
			 * every word is considered true... FAKK!
			 * */
		  
		  if( (checkState(wordToTest.at(i)) ) == true)
		  {
			cout << "the index of the word is " << i << " and the letter is " << wordToTest.at(i) << endl;
			cout << "the current state is for the letter is " << state << endl;
			i++;
		  }
		  else
		  {
			  return (false);
		  }
		  
	 }
	 
	 /*for now this will check to see if the last letter of the
	  * word ends up in either q0 or q1.
	  * */
	 
	 if(state == 0 || state == 1)
	 {
		 return (true);
	 }
	 else
	 {
		 return (false);
	 }
	 
	 /*if the word scan is able to run through the word 
	  * and make it all the way, then the overall word is 
	  * valid
	  * */
	 
	 
 }

bool wordDfa::checkState(const char &character)
{
	
	wordChar = character;
	
	
	
	switch(state)
	{
		case 0:
			return(q0(wordChar));
			//return (true);
			break;
		
		case 1:
			return(q1(wordChar));
			//return (true);
			break;
		
		case 2:
			return(q2(wordChar));
			//return (true);
			break;
		
		case 3:
			return(q3(wordChar));
			//return (true);
			break;
		
		case 4:
			return(q4(wordChar));
			//return (true);
			break;
		
		case 5:
			return(q5(wordChar));
			//return (true);
			break;
		
		case 6:
			return(q6(wordChar));
			//return (true);
			break;
		
		case 7:
			/*needs some tuning*/
			cout << "still under construction" << endl;
		
		default:
			return (false);
	}
}

/*note of error:
 * between the q0 state and q1, q1 does not like having two
 * different cases of 'n'
 * 
 * the dfa will continue even if the spelling of the word is wrong
 * 
 * 
 * */

bool wordDfa::q0(const char &character)
{
	
	switch(character)
	{
		
	case 't':
		state = 2;
		return (true);
		break;
		
	case 'b':
	case 'g':
	case 'h':
	case 'k':
	case 'm':
	case 'n':
	case 'p':
	case 'r':
		state = 3;
		return (true);
		break;
		
	case 'a':
	case 'i':
	case 'u':
	case 'e':
	case 'o':
		state = 1;
		return (true);
		break;
		
	case 'd':
	case 'j':
	case 'w':
	case 'y':
	case 'z':
		state = 5;
		return (true);
		break;
		
	case 's':
		state = 4;
		return (true);
		break;
		
	case 'c':
		state = 7;
		return (true);
		break;
	/*
	case 'n':
		state = 0;
		return (true);
		break;
	*/
	default:
		return (false);
		
	}
}

bool wordDfa::q1(const char &character)
{
	switch(character)
	{
		
	case 't':
		state = 2;
		return (true);
		break;
		
	case 'b':
	case 'g':
	case 'h':
	case 'k':
	case 'm':
	case 'n':
	case 'p':
	case 'r':
		state = 3;
		return (true);
		break;
		
	case 'a':
	case 'i':
	case 'u':
	case 'e':
	case 'o':
		state = 1;
		return (true);
		break;
		
	case 'd':
	case 'j':
	case 'w':
	case 'y':
	case 'z':
		state = 5;
		return (true);
		break;
		
	case 's':
		state = 4;
		return (true);
		break;
		
	case 'c':
		state = 7;
		return (true);
		break;
/*	
	case 'n':
		state = 0;
		return (true);
		break;
	*/
	default:
		return (false);
		
	}
}

bool wordDfa::q2(const char &character)
{
	switch(character)
	{
		case 's':
			state = 6;
			return (true);
			break;
		
		case 'a':
		case 'i':
		case 'u':
		case 'e':
		case 'o':
			state = 1;
			return (true);
			break;
		
		default:
			return (false);
	}
	
}

bool wordDfa::q3(const char &character)
{
	switch(character)
	{
		case 'y':
			state = 6;
			return (true);
			break;
		
		case 'a':
		case 'i':
		case 'u':
		case 'e':
		case 'o':
			state = 1;
			return (true);
			break;
		
		default:
		cout << "fakk" << endl;
			return (false);
	}
}

bool wordDfa::q4(const char &character)
{
	switch(character)
	{
		case 'h':
			state = 6;
			return (true);
			break;
		
		case 'a':
		case 'i':
		case 'u':
		case 'e':
		case 'o':
			state = 1;
			return (true);
			break;
		
		default:
			return (false);
	}
}

bool wordDfa::q5(const char &character)
{
	switch(character)
	{
		
		case 'a':
		case 'i':
		case 'u':
		case 'e':
		case 'o':
			state = 1;
			return (true);
			break;
		
		default:
			return (false);
	}
}

bool wordDfa::q6(const char &character)
{
	switch(character)
	{
		case 's':
			state = 6;
			return (true);
			break;
		
		case 'a':
		case 'i':
		case 'u':
		case 'e':
		case 'o':
			state = 1;
			return (true);
			break;
		
		default:
			return (false);
	}
}

bool wordDfa::q7(const char &character)
{

}
