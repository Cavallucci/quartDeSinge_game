#include <cassert>
#include <iostream> 

#include "ConteneurTS.h"
#include "ConteneurTD.h"
#include "ConteneurTDE.h"
#include "Pile.h"
#include "File.h"
#include "Liste.h"

/** 
* @brief Un programme illustrant les diff�rents conteneurs et structures 
* de donn�es classiques vus en cours, td et tp de SDA.
* Chaque structure a �t� d�velopp�e suite � des choix d'impl�mentation. Ces 
* choix sont souvent arbitraires et conduisent parfois � des limitations. Par exemple,
* les piles et les files ont une capacit� maximale stricte d�cid�e lors de l'initialisation.
* Ces choix d'impl�mentation peuvent �tre remis en question selon les besoins des utilisateurs.
* Certaines impl�mentations (File et Liste par exemple) reposent sur d'autres 
* conteneurs (ConteneurTD et ConteneurTDE).
*/
int main() {
std::cout << "====== TS ======" << std::endl;
	ConteneurTS ts;
	initialiser(ts);
	for (int i = 0; i < 3; ++i)
		ecrire(ts, i, i);
	for (int i = 0; i < 3; ++i)
		assert(lire(ts, i) == i);
for (int i = 0; i < ts.nbItems; ++i)
	std::cout << "tab = " << ts.tab[i] << std::endl;
	/////////////////////////////////////
std::cout << "====== TDE ======" << std::endl;
	ConteneurTDE tde;
	initialiser(tde, 2, 2);
	for (int i = 0; i < 3; ++i)
		ecrire(tde, i, i);
	for (int i = 0; i < 3; ++i)
		assert(lire(tde, i) == i);
for (int i = 0; i < tde.capacite; ++i)
	std::cout << "tab = " << tde.tab[i] << std::endl;
	detruire(tde);
	// /////////////////////////////////////
std::cout << "====== PILE ======" << std::endl;
	Pile p;
	initialiser(p, 10);
	assert(estVide(p));
	empiler(p, 7);
	assert(!estVide(p));
	assert(sommet(p) == 7);
	empiler(p, 3);
	assert(!estVide(p));
	assert(sommet(p) == 3);
	depiler(p);
	assert(!estVide(p));
	assert(sommet(p) == 7);
	depiler(p);
	assert(estVide(p));
for (int i = 0; i < p.capacite; ++i)
{
	std::cout << "tab = " << p.tab[i] << std::endl;
	std::cout << "sommet = " << p.sommet << std::endl;
}
	detruire(p);
	// /////////////////////////////////////
std::cout << "====== FILE ======" << std::endl;
	File f;
	initialiser(f, 3);
	assert(estVide(f));
	assert(!estPleine(f));
	entrer(f, 1);
	assert(!estVide(f));
	assert(!estPleine(f));
	assert(tete(f) == 1);
	entrer(f, 2);
	assert(!estVide(f));
	assert(!estPleine(f));
	assert(tete(f) == 1);
	entrer(f, 3);
for (int i = 0; i < f.nb; ++i)
{
	std::cout << "indPremier = " << f.indPremier << std::endl;
	std::cout << "indProchain = " << f.indProchain << std::endl;
}
	assert(!estVide(f));
	assert(estPleine(f));
	assert(tete(f) == 1);
	sortir(f);
	assert(!estVide(f));
	assert(!estPleine(f));
	assert(tete(f) == 2);
	entrer(f, 4);
	sortir(f);
	assert(!estVide(f));
	assert(!estPleine(f));
	assert(tete(f) == 3);
	sortir(f);
	assert(!estVide(f));
	assert(!estPleine(f));
	assert(tete(f) == 4);
	sortir(f);
	assert(estVide(f));
for (int i = 0; i < f.nb; ++i)
{
	std::cout << "indPremier = " << f.indPremier << std::endl;
	std::cout << "indProchain = " << f.indProchain << std::endl;
}
	detruire(f);
	// /////////////////////////////////////
std::cout << "====== LISTE ======" << std::endl;
	Liste li;
	initialiser(li, 2, 2);
	for (int i = 0; i < 3; ++i)
		inserer(li, i, i);
	assert(longueur(li) == 3);
	for (int i = 0; i < 3; ++i)
		assert(lire(li, i) == i);
	inserer(li, 0, -1);
	assert(longueur(li) == 4);
	for (int i = 0; i < 4; ++i)
		assert(lire(li, i) == i - 1);
	supprimer(li, 0);
	assert(longueur(li) == 3);
	for (int i = 0; i < 3; ++i)
		assert(lire(li, i) == i);
for (int i = 0; i < li.nb; ++i)
{
	std::cout << "c.tab = " << li.c.tab[i] << std::endl;
}
	detruire(li);
}
