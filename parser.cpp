#include "parser.h"
#include <string>
#include <stack>
using namespace std;

InvalidTokenException::InvalidTokenException(string expected, string actual)
{
    ExpectedValue = expected;
    ActualValue = actual;
}

TokenObject::TokenObject()
{
    Word = "";
    Token = "";
}

TokenObject::TokenObject(string word, string type)
{
    Word = word;
    Token = type;
}

Parser::Parser()
{
    stack<TokenObject> dummy;

    contents = dummy;
    //ctor
}

Parser::~Parser()
{
    //dtor
}

void Parser::AddToken(TokenObject Content)
{
    contents.push(Content);
}

void Parser::AddToken(string word, string type)
{
    TokenObject dummy(word, type);
    AddToken(dummy);
}

bool Parser::Process()
{
    return false;
}

bool Parser::VerbTensePeriod()
{
    TokenObject nextToken = contents.top();
    TokenObject prevToken;
    if(nextToken.Token == "PERIOD")
    {
        ;
        prevToken = nextToken;
        contents.pop();
        nextToken = contents.top();
        //<tense> := VERBPAST  | VERBPASTNEG | VERB | VERBNEG
        if(nextToken.Token == "tense")
        {
            ;
            prevToken = nextToken;
            contents.pop();
            nextToken = contents.top();
            //<verb> ::= WORD2
            if(nextToken.Token == "WORD2")
            {
                contents.pop();
                return true;
            }
        }
    }


    return false;
}

bool Parser::NounBePeriod()
{

    TokenObject nextToken = contents.top();
    TokenObject prevToken;
    if(nextToken.Token == "PERIOD")
    {
        ;
        prevToken = nextToken;
        contents.pop();
        nextToken = contents.top();
        if(nextToken.Token == "tense")
        {
            ;
            prevToken = nextToken;
            contents.pop();
            nextToken = contents.top();
            if(nextToken.Token == "verb")
            {
                contents.pop();
                return true;
            }
        }
    }


    return false;
}

bool Parser::NounObject()
{

    TokenObject nextToken = contents.top();
    TokenObject prevToken;
    if(nextToken.Token == "PERIOD")
    {
        ;
        prevToken = nextToken;
        contents.pop();
        nextToken = contents.top();
        if(nextToken.Token == "tense")
        {
            ;
            prevToken = nextToken;
            contents.pop();
            nextToken = contents.top();
            if(nextToken.Token == "verb")
            {
                contents.pop();
                return true;
            }
        }
    }


    return false;
}

bool Parser::NounDestination()
{
    ;
    return false;
}

bool Parser::ConnectorNounSubject()
{

    TokenObject nextToken = contents.top();
    TokenObject prevToken;
    if(nextToken.Token == "Subject")
    {
        ;
        prevToken = nextToken;
        contents.pop();
        nextToken = contents.top();
        if(nextToken.Token == "Noun")
        {
            ;
            prevToken = nextToken;
            contents.pop();
            nextToken = contents.top();
            if(nextToken.Token == "Connector")
            {
                contents.pop();
                return true;
            }
        }
    }


    return false;
}


