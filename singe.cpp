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

void	initSinge(struct Singe *data, const char *arg)
{
	initialiser(data->_players, data->_nbplayers, data->_nbplayers);
    for (unsigned int i = 0; i != data->_nbplayers; i++)
    {
        struct Players  p;
        p.nature = arg[i];
        p.score = 0;
        ecrire(data->_players, i, p);
    }
}

bool    checkScores(ConteneurTDE players)
{
    for (unsigned int i = 0; i < players.capacite; i++)
    {
        if (lire(players, i).score == 1)
            return false;
        else {
            std::cout << "le joueur de nature " << lire(players, i).nature;
            std::cout << " a un score de : " << lire(players, i).score << std::endl;}
    }
    return false;
}