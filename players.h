#ifndef PLAYERS_H
#define PLAYERS_H

# include "singe.h"
# include "ConteneurTDE.h"

struct Singe;
struct ConteneurTDE;

struct Players
{
    unsigned int    index;
    char            nature;
    float           score;
};

void    printHeader(Players p, char *word);
void    humanHandle(Singe *data, int i);
void    robotHandle(Singe *data, int i);
bool    checkScores(Players p);

#endif