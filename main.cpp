#include "quart_de_singe.hpp"

bool	parsingArgs()

int main(int argc, const char* argv[]) {
	// parametre sur la ligne de commande
	if (argc == 2 && parsingArgs(argv))
	{

	}
	else
		std::cout << "Error Arguments" << std::endl;
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

	return 0;
}