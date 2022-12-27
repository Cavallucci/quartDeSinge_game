#include "singe.h"

int main(int argc, const char* argv[]) 
{
	Singe		data;
	bool		playing = true;
	
	if (argc == 2 && parsingArgs(argv[1], &data) == true)
	{
		initSinge(&data, argv[1]);
		for (unsigned int i = 0; playing; i++)
		{
			playing = checkScores(lire(data._players, i));
			if (playing == false)
				break;
			i = gameHandler(&data, i);
			if (i == data._nbplayers - 1)
				i = -1;
		}
		std::cout << "La partie est finie" << std::endl;
		detruire(data._players);
	}
	else
		std::cout << "Error Arguments" << std::endl;
	return 0;
}	