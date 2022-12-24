#include "singe.h"

int main(int argc, const char* argv[]) 
{
	Singe		data;
	bool		playing = true;
	
	if (argc == 2 && parsingArgs(argv[1], &data) == true)
	{
		initSinge(&data, argv[1]);
		std::ifstream in("ods4.txt");
		if (!in) {
			std::cout << "le dictionnaire n'a pu etre ouvert" << std::endl;
			return 2;
		}
		for (unsigned int i = 0; playing; i++)
		{
			std::cout << "i = " << i << std::endl;
			std::cout << "lire = " << lire(data._players, i).index << std::endl;
			playing = gameHandler(&data, i);
			if (i == data._nbplayers - 1)
				i = -1;
		}
		in.close(); // on ferme le fichier
		detruire(data._players);
	}
	else
		std::cout << "Error Arguments" << std::endl;
	return 0;
}	