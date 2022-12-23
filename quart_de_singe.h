#ifndef QUART_DE_SINGE_H
#define QUART_DE_SINGE_H

# include <iostream>
# include <fstream> // pour ifstream
# include <iomanip> // pour setw
# include <cstring>
# include "players.h"
# include <vector>

struct Data
{
    unsigned int            _nbplayers;
    std::vector<struct Players *>  _players;
};

bool	        parsingArgs(const char* argv, struct Data *d);
void	        initData(struct Data *d,const char *arg);

#endif