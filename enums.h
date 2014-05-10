#ifndef ENUMS_H
#define ENUMS_H
#include <string>
using namespace std;


enum WordType
{
    UNKOWN = 0,
    WORD1,
    WORD2,
    PRONOUN,
    IS,
    WAS,
    OBJECT,
    SUBJECT,
    DESTINATION,
    VERB,
    VERBNEG,
    VERBPAST,
    VERBPASTNEG,
    CONNECTOR,
    PERIOD,
    EOFM
};

class WordTokenClass
{
public:
    static string convert(WordType);
    static WordType convert(string);
};


#endif // ENUMS_H
