#pragma once
# include "Item.h"
# include "singe.h"
# include "players.h"


struct ConteneurTDE 
{
    unsigned int	capacite; 	   
	unsigned int	pasExtension; 
	Item*			tab; //ici sa nature H ou R
};

void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p);
void detruire(ConteneurTDE& c); 
Item lire(const ConteneurTDE& c, unsigned int i);
void ecrire(ConteneurTDE& c, unsigned int i, const Item& it);
