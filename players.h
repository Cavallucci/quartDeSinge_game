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
void    humanHandle(Players p, char *word);

#endif