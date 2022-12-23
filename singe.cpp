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
    for (int i = 0; i != data->_nbplayers; i++)
    {
        ecrire(data->_players, i, arg[i]);
    }
}

bool    checkScores(ConteneurTDE players)
{
    for (int i = 0; i < players.capacite; i++)
        std::cout << std::endl;
    return false;
}