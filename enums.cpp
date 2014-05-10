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
    else if(input == "PRONOUN")
    {
        return PRONOUN;
    }
    else if(input == "IS")
    {
        return IS;
    }
    else if(input == "WAS")
    {
        return WAS;
    }
    else if(input == "OBJECT")
    {
        return OBJECT;
    }
    else if(input == "SUBJECT")
    {
        return SUBJECT;
    }
    else if(input == "DESTINATION")
    {
        return DESTINATION;
    }
    else if(input == "VERB")
    {
        return VERB;
    }
    else if(input == "VERBNEG")
    {
        return VERBNEG;
    }
    else if(input == "VERBPAST")
    {
        return VERBPAST;
    }
    else if(input == "VERBPASTNEG")
    {
        return VERBPASTNEG;
    }
    else if(input == "CONNECTOR")
    {
        return CONNECTOR;
    }
    else if(input == "PERIOD")
    {
        return PERIOD;
    }
    else if(input == "EOFM")
    {
        return EOFM;
    }
    else
    {
        return UNKOWN;
    }
}

