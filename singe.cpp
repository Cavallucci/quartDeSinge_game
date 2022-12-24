#include "singe.h"

bool	parsingArgs(const char* argv, struct Singe *data)
{
	int	count = 0;
    int countH = 0;

	for (int i = 0; argv[i] != '\0'; i++)
	{
		if (argv[i] != 'H' && argv[i] != 'R')
            return false;
        if (argv[i] == 'H')
            countH++;
        count++;
	}
    if (count < 2 || countH == 0)
        return false;
    data->_nbplayers = count;
	return true;
}

void	initSinge(Singe *data, const char *arg)
{
	initialiser(data->_players, data->_nbplayers + 1, data->_nbplayers + 1);
    for (unsigned int i = 0; i != data->_nbplayers; i++)
    {
        struct Players  p;
        p.nature = arg[i];
        p.score = 0;
        p.index = i + 1;
        ecrire(data->_players, i, p);
    }
}

bool    wordIsInFile(Singe *data, std::ifstream in)
{
    char    tmp[data->MAX];
    while (in)
    {
        in >> std::setw(data->MAX) >> tmp;
        if (tmp == data->_word)
            return true;
    }
    return false;
}

bool    gameHandler(Singe *data, int i)
{
    Players p = lire(data->_players, i);
    printHeader(p, data->_word);
    if (p.nature == 'R')
        robotHandle(data, i);
    else
        humanHandle(data, i);
    return (checkScores(p));
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