#include "parser.h"
#include <string>
#include <stack>
using namespace std;

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
    ;
}

