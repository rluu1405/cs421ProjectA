#include <string>
#include "enums.h"
using namespace std;

string WordTokenClass::convert(WordType input)
{
    switch(input)
    {
    case WORD1:
        return "WORD1";
    case WORD2:
        return "WORD2";
    case PRONOUN:
        return "PRONOUN";
    case IS:
        return "IS";
    case WAS:
        return "WAS";
    case OBJECT:
        return "OBJECT";
    case SUBJECT:
        return "SUBJECT";
    case DESTINATION:
        return "DESTINATION";
    case VERB:
        return "VERB";
    case VERBNEG:
        return "VERBNEG";
    case VERBPAST:
        return "VERBPAST";
    case VERBPASTNEG:
        return "VERBPASTNEG";
    case CONNECTOR:
        return "CONNECTOR";
    case PERIOD:
        return "PERIOD";
    case EOFM:
        return "EOFM";
    default:
        return "UNKOWN";
    }

}

WordType WordTokenClass::convert(string input)
{
    if(input == "WORD1")
    {
        return WORD1;
    }
    else if(input == "WORD2")
    {
        return WORD2;
    }
    else if(input == "PRONOUN" || input == "pronoun")
    {
        return PRONOUN;
    }
    else if(input == "IS" || input == "is")
    {
        return IS;
    }
    else if(input == "WAS" || input == "was")
    {
        return WAS;
    }
    else if(input == "OBJECT" || input == "object")
    {
        return OBJECT;
    }
    else if(input == "SUBJECT" || input == "subject")
    {
        return SUBJECT;
    }
    else if(input == "DESTINATION" || input == "destination")
    {
        return DESTINATION;
    }
    else if(input == "VERB" || input == "verb")
    {
        return VERB;
    }
    else if(input == "VERBNEG" || input == "verbneg")
    {
        return VERBNEG;
    }
    else if(input == "VERBPAST" || input == "verbpast")
    {
        return VERBPAST;
    }
    else if(input == "VERBPASTNEG" || input == "verbpastneg")
    {
        return VERBPASTNEG;
    }
    else if(input == "CONNECTOR" || input == "connector")
    {
        return CONNECTOR;
    }
    else if(input == "PERIOD")
    {
        return PERIOD;
    }
    else if(input == "EOFM" || input == "eofm")
    {
        return EOFM;
    }
    else
    {
        return UNKOWN;
    }
}

