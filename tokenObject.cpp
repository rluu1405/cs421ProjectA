#include <string>
using namespace std;
#include "tokenObject.h"

TokenObject::TokenObject()
{
    Word = "";
    Token = UNKOWN;
    English = "";
}

TokenObject::TokenObject(string word, WordType type)
{
    Word = word;
    Token = type;
    English = "";
}

TokenObject::TokenObject(string word, WordType type, string english)
{
    Word = word;
    Token = type;
    English = english;
}
