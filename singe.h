#ifndef QUART_DE_SINGE_H
#define QUART_DE_SINGE_H

# include <iostream>
# include <fstream> // pour ifstream
# include <iomanip> // pour setw
# include <cstring>
# include <cassert>
# include "ConteneurTDE.h"

struct Singe
{
    ConteneurTDE    _players;
    unsigned int    _nbplayers;
};

void            initSinge(struct Singe *data, const char *arg);
bool	        parsingArgs(const char* argv, struct Singe *data);
bool            checkScores(ConteneurTDE players);

#endif