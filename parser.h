#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <stack>
using namespace std;

class TokenObject
{
public:
    TokenObject();
    TokenObject(string, string);
    string Word;
    string Token;
};

class Parser
{
    public:
        Parser();
        virtual ~Parser();
        void AddToken(TokenObject);
        void AddToken(string, string);
        bool Process();
    protected:
        stack<TokenObject> contents;
    private:

};

#endif // PARSER_H
