#ifndef MONTRE_H
#define MONTRE_H


#include "Include.h"
#include "Piece.h"
#include "Engrenage.h"
#include "Maitresse.h"

class Montre : public Piece
{
	
	float rotation;

	// Création des engrenages
	Engrenage* engrenage_M0p01_0p85;
	Engrenage* engrenage_M0p01_0p45;

	// Création de la piece maitresse
	Maitresse* maitresse;

public:
	Montre(void);
	virtual ~Montre(void);

	virtual void BuildAndDisplay();
	virtual void Update();
};

#endif