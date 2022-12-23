#ifndef PLAYERS_H
#define PLAYERS_H

struct Players
{
    unsigned int        _index;
    char                _nature;
    float               _score;
};

void    initPlayer(struct Players p, char nature, unsigned int index);

#endif