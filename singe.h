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
};

void    initSinge(struct Singe *data, const char *arg);
bool	parsingArgs(const char* argv, struct Singe *data);
bool    wordIsInFile(Singe *data);
int     gameHandler(struct Singe *data, int i);
int     humanHandle(Singe *data, int i);
void    robotHandle(Singe *data, int i);
void    addToScore(Singe *data, int i);
void    addToWord(Singe *data, char s);
void    printScores(ConteneurTDE p, unsigned int i);
int     giveUp(Singe *data, int i);
int     askPrevious(Singe *data, int i);
void    alreadyExist(Singe *data, int i);


#endif