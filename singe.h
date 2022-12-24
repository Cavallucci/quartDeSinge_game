#ifndef QUART_DE_SINGE_H
#define QUART_DE_SINGE_H

# include <iostream>
# include <fstream> // pour ifstream
# include <iomanip> // pour setw
# include <cstring>
# include <cassert>
# include "players.h"
# include "ConteneurTDE.h"


struct Players;
struct ConteneurTDE;

struct Singe
{
    ConteneurTDE     _players;
    unsigned int            _nbplayers;
    static const int	    MAX = 26;
    char                    _word[MAX];
};

void    initSinge(struct Singe *data, const char *arg);
bool	parsingArgs(const char* argv, struct Singe *data);
bool    wordIsInFile(char *word, std::ifstream in);
bool    gameHandler(struct Singe *data, int i);

#endif