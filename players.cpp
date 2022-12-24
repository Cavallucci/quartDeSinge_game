#include "players.h"

void    printHeader(Players p, char *word)
{
    std::cout << p.index << p.nature << ", (";
    if (word)
        for (int i = 0; word[i]; i++)
            std::cout << word[i];
    std::cout << ") >";
}

void    humanHandle(Singe *data, int i)
{
    Players  tmp;
    tmp = lire(data->_players, i);
    tmp.score = 1;
    ecrire(data->_players, i, tmp);
}

void    robotHandle(Singe *data, int i)
{
    Players  tmp;
    tmp = lire(data->_players, i);
    tmp.score = 1;
    ecrire(data->_players, i, tmp);
}

bool    checkScores(Players p)
{
    if (p.score == 1)
        return false;
    return true;
}