#ifndef SINGE_H
#define SINGE_H

# include <iostream>
# include <fstream> // pour ifstream
# include <iomanip> // pour setw
# include <cstring>
# include <cassert>

# include "ConteneurTDE.h"

struct Singe
{
    ConteneurTDE        _players;
    unsigned int        _nbplayers;
    static const int    MAX = 26;
    char                _word[MAX];
    std::ifstream       in;
};

void    initSinge(struct Singe *data, const char *arg);
bool	parsingArgs(const char* argv, struct Singe *data);
bool    wordIsInFile(char *word, std::ifstream in);
bool    gameHandler(struct Singe *data, int i);
void    humanHandle(Singe *data, int i);
void    robotHandle(Singe *data, int i);
void    addToScore(Singe *data, int i);
void    addToWord(Singe *data, char s);


#endif