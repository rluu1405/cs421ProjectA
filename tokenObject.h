#ifndef TOKENOBJECT_H
#define TOKENOBJECT_H
#include "enums.h"


class TokenObject
{
public:
    TokenObject();
    TokenObject(string, WordType);
    TokenObject(string, WordType, string);
    string Word;
    WordType Token;
    string English;
};

#endif // TOKENOBJECT_H
