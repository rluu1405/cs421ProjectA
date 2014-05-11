#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>
#include "enums.h"
#include "tokenObject.h"
using namespace std;

class InvalidTokenException
{
public:
    string ExpectedValue;
    string ActualValue;
    InvalidTokenException(string, string);
};

class Parser
{
public:
    Parser();
    virtual ~Parser();
    void AddToken(TokenObject);
    void AddToken(string, WordType);
    bool Process();
protected:
    vector<TokenObject> contents;
    bool VerbTensePeriod(int);
    bool NounBePeriod(int);
    bool NounObject(int);
    bool NounDestination(int);
    bool ConnectorNounSubject(int);
private:

};

#endif // PARSER_H
