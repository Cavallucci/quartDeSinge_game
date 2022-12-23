#include "players.h"

void    printHeader(Players p, char *word)
{
    std::cout << p.index << p.nature << ", (";
    if (word)
        for (int i = 0; word[i]; i++)
            std::cout << word[i];
    std::cout << ") >";
}

void    humanHandle(Players p, char *word)
{
    std::getline(std::cin, word);
    p.score = 1;
}