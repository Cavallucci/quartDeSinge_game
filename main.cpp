#include "singe.h"

int main(int argc, const char* argv[]) 
{
	Singe		data;
	bool		playing = true;
	
	if (argc == 2 && parsingArgs(argv[1], &data) == true)
	{
		initSinge(&data, argv[1]);
		if (!data.in) {
			std::cout << "le dictionnaire n'a pu etre ouvert" << std::endl;
			return 2;
		}
		for (unsigned int i = 0; playing; i++)
		{
			playing = gameHandler(&data, i);
			if (i == data._nbplayers - 1)
				i = -1;
		}
		data.in.close(); // on ferme le fichier
		detruire(data._players);
	}
	else
		std::cout << "Error Arguments" << std::endl;
	return 0;
}	