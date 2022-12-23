#pragma once
# include "Item.h"

struct ConteneurTDE 
{
    unsigned int	capacite; 	   
	unsigned int	pasExtension; 
	Item*			tab; //
	float			score;	   
};

void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p);
void detruire(ConteneurTDE& c); 
Item lire(const ConteneurTDE& c, unsigned int i);
void ecrire(ConteneurTDE& c, unsigned int i, const Item& it);
