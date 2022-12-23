#include "quart_de_singe.h"

bool	parsingArgs(const char* argv, struct Data *d)
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
    d->_nbplayers = count;
	return true;
}

void	initData(struct Data *d, const char *arg)
{
    for (int i = 0; i != d->_nbplayers; i++)
    {
        std::cout << "initdata\n";
        struct Players  p;
        d->_players.insert(i, p);
        //initPlayer(d->_players[i], arg[i], i);
    }
}
