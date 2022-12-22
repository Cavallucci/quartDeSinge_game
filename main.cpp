#include "quart_de_singe.h"

bool	parsingArgs(const char* argv, struct Data *d)
{
	int	countR = 0;
	int countH = 0;

	for (int i = 0; argv[i] != '\0'; i++)
	{
		if (argv[i] == 'H')
			countH++;
		else if (argv[i] == 'R')
			countR++;
		else
			return false;
	}
	d->_nbR = countR;
	d->_nbH = countH;
	return true;
}

void	initData(struct Data *d)
{
	d->_nbR = 0;
	d->_nbH = 0;
}

int main(int argc, const char* argv[]) 
{
	Data	d;

	initData(&d);
	if (argc == 2 && parsingArgs(argv[1], &d) == true)
	{
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