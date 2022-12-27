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

void	initSinge(Singe *data, const char *arg)
{
	initialiser(data->_players, data->_nbplayers + 1, data->_nbplayers + 1);
    data->_word[0] = '\0';
    for (unsigned int i = 0; i != data->_nbplayers; i++)
    {
        struct Players  p;
        p.nature = arg[i];
        p.score = 0;
        p.index = i + 1;
        ecrire(data->_players, i, p);
    }
}

bool    wordIsInFile(Singe *data)
{
    std::ifstream in("ods4.txt");
	if (!in) {
		std::cout << "le dictionnaire n'a pu etre ouvert" << std::endl;
		exit (2);
	}
    char c[data->MAX];
    in >> std::setw(data->MAX) >> c; // on essaye de lire le premier mot    
    while (in) {
        if (std::strncmp(c, data->_word, sizeof(data->_word)) == 0)
            return true;
		in >> std::setw(data->MAX) >> c; // on essaye de lire le mot suivant
	}
    in.close();
    return false;
}

int    gameHandler(Singe *data, int i)
{
    Players p = lire(data->_players, i);
    printHeader(p, data->_word);
    if (p.nature == 'R')
        robotHandle(data, i);
    else
        i = humanHandle(data, i);
    return (i);
}

int    humanHandle(Singe *data, int i)
{
    char s;
    std::cin >> std::setw(1) >> s;
    if (s == '!')
        return (giveUp(data, i));
    if (s == '?')
        return (askPrevious(data, i));
    if (std::isalpha(s))
        addToWord(data, s);
    if (sizeof(data->_word) > 1 && wordIsInFile(data))
        alreadyExist(data, i); 
    return (i);
}

void    robotHandle(Singe *data, int i)
{
    (void)data;
    (void)i;
    //addToScore(data, i);
}

void    addToScore(Singe *data, int i)
{
    Players  tmp;
    tmp = lire(data->_players, i);
    tmp.score += 0.25;
    ecrire(data->_players, i, tmp);
    data->_word[0] = '\0';
}

void    addToWord(Singe *data, char s)
{
    int j = 0;

    if (data->_word)
    {
        while (data->_word[j])
            j++;
    }
    data->_word[j] = std::toupper(s);
    data->_word[j + 1] = '\0';
}

void    printScores(ConteneurTDE p, unsigned int i)
{
    for (unsigned int j = 0; j < i; j++)
    {
        std::cout << lire(p, j).index << lire(p, j).nature;
        std::cout << " : " << lire(p, j).score;
        std::cout << "; ";
    }
    std::cout << std::endl;

}

int     giveUp(Singe *data, int i)
{
    std::cout << "le joueur " << lire(data->_players, i).index << lire(data->_players, i).nature;
    std::cout << " abandonne la manche et prend un quart de singe" << std::endl;
    addToScore(data, i);
    printScores(data->_players, data->_nbplayers);
    return (-1);
}

int     askPrevious(Singe *data, int i)
{
    int tmp;

    if (i == 0)
        tmp = data->_nbplayers - 1;
    else
        tmp = i - 1;
    std::cout << lire(data->_players, tmp).index << lire(data->_players, tmp).nature;
    if (lire(data->_players, tmp).nature == 'R')
        std::cout << "reponse robot a modifier\n";
    std::cout << ", saisir le mot >";
    std::cin >> std::setw(data->MAX) >> data->_word;
    if (!wordIsInFile(data))
    {
        std::cout << "le mot " << data->_word;
        std::cout << " ne commence pas par les lettres attendues, le joueur " << lire(data->_players, i - 1).index << lire(data->_players, i - 1).nature;
        std::cout << " prend un quart de singe" << std::endl;
        addToScore(data, tmp);
        printScores(data->_players, data->_nbplayers);
    }
    else
        alreadyExist(data, i);
    return (-1);
}

void    alreadyExist(Singe *data, int i)
{
    std::cout << "le mot " << data->_word;
    std::cout << " existe, le joueur " << lire(data->_players, i).index << lire(data->_players, i).nature;
    std::cout << " prend un quart de singe" << std::endl;
    addToScore(data, i);
    printScores(data->_players, data->_nbplayers);
}