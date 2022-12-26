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
    data.in("ods4.txt");
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
    char s;
    std::cin >> std::setw(1) >> s;
    //if s is ! alors abandonner le mot
    //et mettre word a null

    //if s is ? alors demander a player -i
    //si il a le mot, -0,25 pour nous 
    //sinon pour lui
    //et mettre word a null
    addToWord(data, s);

    //check si word existe, si c'est le cas
    //le joueur perd cette manche
    //et mettre word a null
    addToScore(data, i);
}

void    robotHandle(Singe *data, int i)
{
    addToScore(data, i);
}

void    addToScore(Singe *data, int i)
{
    Players  tmp;
    tmp = lire(data->_players, i);
    tmp.score += 0.25;
    ecrire(data->_players, i, tmp);
}

void    addToWord(Singe *data, char s)
{
    int j = 0;

    if (data->_word)
    {
        while (data->_word[j])
            j++;
    }
    data->_word[j] = s;
}