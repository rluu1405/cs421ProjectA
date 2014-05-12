#include <string>
#include <stack>
#include <iostream>
#include <fstream>
using namespace std;
#include "parser.h"
#include "wordDfa.h"
#include "lexical.h"
#include "pDfa.h"


InvalidTokenException::InvalidTokenException(string expected, string actual)
{
    ExpectedValue = expected;
    ActualValue = actual;
}

Parser::Parser()
{
    vector<TokenObject> dummy;

    contents = dummy;
    //ctor
}

Parser::~Parser()
{
    //dtor
}

void Parser::AddToken(TokenObject Content)
{
    contents.push_back(Content);
}

void Parser::AddToken(string word, WordType type)
{
    TokenObject dummy(word, type);
    AddToken(dummy);
}


void Parser::ProcessFile(string userInput)
{
         ifstream inputFile;

         wordDfa dfa;
         lexical lex;
        bool result;
         pDfa period;

         string singleWord = " ";

        inputFile.open(userInput.c_str());

        try
        {
         if(inputFile.is_open())
         {
            while(!inputFile.eof())
            {

                inputFile >> singleWord;

                /*if the word is true
                * pass to a function that first checks for the reserved words
                * the check to see if it is in the dictionary (lexicon). if it
                * is not in the dictionary already, then it adds the new word
                * into the dictionary.
                * */

                if(dfa.scanMe(singleWord) || period.scanPeriod(singleWord))
                {

                    AddToken(lex.ProcessWord(singleWord));

                    //cout << "yup!!!\n\n";
                }
                else if(period.scanPeriod(singleWord))
                {
                    AddToken(lex.ProcessWord(singleWord));
                    result = ProcessStack();
                    if(result == false)
                    {
                        cout << "Parser Error!!!\n";
                        return;
                    }
                    else
                    {
                        ;
                    }
                }
                else
                {
                    cout << "Lexical Error!!!\n";
                    return;
                }

            }//end of while(!readMe.eof())
         }
         else
         {
             cout << "file could not be read..." << endl;
         }
     }
     catch (string mes)
     {
         cout<<mes;
     }
}

bool Parser::ProcessStack()
{
    int index = contents.size() - 1;
    if(VerbTensePeriod(index) == true)
    {
        index-=3;
        if(NounDestination(index) == true)
        {
            index-=2;
            if(NounObject(index) == true)
            {
                index-=2;
                return ConnectorNounSubject(index);
            }
            else
            {
                return ConnectorNounSubject(index);
            }
        }
        else if(NounObject(index) == true)
        {
            index-=2;
            return ConnectorNounSubject(index);
        }
        else
        {
            return ConnectorNounSubject(index);
        }
    }
    else if(NounBePeriod(index) == true)
    {
        index-=3;
        return ConnectorNounSubject(index);
    }
    return false;
}

bool Parser::VerbTensePeriod(int position)
{
    TokenObject nextToken = contents[position];
    TokenObject prevToken;
    if(nextToken.Token == PERIOD)
    {
        position--;
        prevToken = nextToken;
        nextToken = contents[position];
        //<tense> := VERBPAST  | VERBPASTNEG | VERB | VERBNEG
        switch(nextToken.Token)
        {
            case VERBPAST:
            case VERBPASTNEG:
            case VERB:
            case VERBNEG:
            position--;
            prevToken = nextToken;
            nextToken = contents[position];
                //<verb> ::= WORD2
                if(nextToken.Token == WORD2)
                {
                    return true;
                }
            default:
                return false;
        }

    }

    return false;
}

bool Parser::NounBePeriod(int position)
{

    TokenObject nextToken = contents[position];
    TokenObject prevToken;
    if(nextToken.Token == PERIOD)
    {
        position--;
        prevToken = nextToken;
        nextToken = contents[position];
        switch(nextToken.Token)
        {
            case IS:
            case WAS:
                position--;
                prevToken = nextToken;
                nextToken = contents[position];
                switch(nextToken.Token)
                {
                    case WORD1:
                    case WORD2:
                    case PRONOUN:
                        return true;
                    default:
                        return false;
                }
            default:
                    return false;
        }
    }

    return false;
}

bool Parser::NounObject(int position)
{

    TokenObject nextToken = contents[position];
    TokenObject prevToken;
    switch (nextToken.Token)
    {
        case OBJECT:
            position--;
            prevToken = nextToken;
            nextToken = contents[position];
            switch(nextToken.Token)
            {
                case WORD1:
                case WORD2:
                case PRONOUN:
                    return true;
                default:
                    return false;
            }
        default:
            return false;
    }
    return false;
}

bool Parser::NounDestination(int position)
{
    TokenObject nextToken = contents[position];
    TokenObject prevToken;
    switch (nextToken.Token)
    {
        case DESTINATION:
            position--;
            prevToken = nextToken;
            nextToken = contents[position];
            switch(nextToken.Token)
            {
                case WORD1:
                case WORD2:
                case PRONOUN:
                    return true;
                default:
                    return false;
            }
        default:
            return false;
    }
    return false;
}

bool Parser::ConnectorNounSubject(int position)
{

    TokenObject nextToken = contents[position];
    TokenObject prevToken;
    switch (nextToken.Token)
    {
        case SUBJECT:
            position--;
            prevToken = nextToken;
            nextToken = contents[position];
            switch(nextToken.Token)
            {
                case WORD1:
                case WORD2:
                case PRONOUN:
                position--;
                prevToken = nextToken;
                nextToken = contents[position];
                    if(nextToken.Token == CONNECTOR)
                    {
                        return true;
                    }
                default:
                    return false;
            }
        default:
            return false;
    }
    return false;
}


