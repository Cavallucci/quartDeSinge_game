#include "quart_de_singe.h"

int main(int argc, const char* argv[]) 
{
	Data	d;
	
	if (argc == 2 && parsingArgs(argv[1], &d) == true)
	{
		initData(&d, argv[1]);
		std::cout << "segflt" << std::endl;
		std::cout << d._nbplayers << std::endl;
		// for (int i = 0; i < d._nbplayers; i++)
		// {
		// 	std::cout << d._players[i]._index << std::endl;
		// }
		
		
		// lecture du dictionnaire mot à mot
		std::ifstream in("ods4.txt"); // on ouvre le fichier
		if (!in) {
			std::cout << "le dictionnaire n'a pu etre ouvert" << std::endl;
			return 2;
		}

		int nb = 0, longueur = 0;
		const int MAX = 26;
		char s[MAX];
		in >> std::setw(MAX) >> s; // on essaye de lire le premier mot
		while (in) {
			++nb; // ça s'est bien passé, on le compte
			longueur += strlen(s); // et on accumule sa longueur
			in >> std::setw(MAX) >> s; // on essaye de lire le mot suivant
		}
		in.close(); // on ferme le fichier
		std::cout << nb << " mots de " << (float)longueur / nb << " car. en moyenne" << std::endl;
	}
	else
		std::cout << "Error Arguments" << std::endl;
	return 0;
}