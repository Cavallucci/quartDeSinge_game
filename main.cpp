#include "singe.h"

int main(int argc, const char* argv[]) 
{
	Singe		data;
	bool		playing = true;
	const int	MAX = 26;
	char		s[MAX];
	
	if (argc == 2 && parsingArgs(argv[1], &data) == true)
	{
		initSinge(&data, argv[1]);
		std::ifstream in("ods4.txt");
		if (!in) {
			std::cout << "le dictionnaire n'a pu etre ouvert" << std::endl;
			return 2;
		}
		in >> std::setw(MAX) >> s;
		while (playing && in)
		{
			playing = checkScores(data._players);
		}

		in.close(); // on ferme le fichier
		detruire(data._players);
	}
	else
		std::cout << "Error Arguments" << std::endl;
	return 0;
}