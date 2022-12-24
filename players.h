#ifndef PLAYERS_H
#define PLAYERS_H

# include <iostream>

struct Players
{
    unsigned int    index;
    char            nature;
    float           score;
};

void    printHeader(Players p, char *word);
bool    checkScores(Players p);

#endif