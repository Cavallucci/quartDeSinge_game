#include "players.h"

void    printHeader(Players p, char *word)
{
    std::cout << p.index << p.nature << ", (";
    if (word)
        for (int i = 0; word[i]; i++)
            std::cout << word[i];
    std::cout << ") >";
}

bool    checkScores(Players p)
{
    if (p.score == 1)
        return false;
    return true;
}