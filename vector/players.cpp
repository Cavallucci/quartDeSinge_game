# include "players.h"
# include <iostream>

void    initPlayer(struct Players p, char nature, unsigned int index)
{
    std::cout << "initplayer\n";
    p._index = index;
    std::cout << "initplayer\n";
    p._nature = nature;
    p._score = 0;
}