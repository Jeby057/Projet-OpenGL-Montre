#ifndef MONTRE_H
#define MONTRE_H


#include "Include.h"
#include "Piece.h"
#include "Engrenage.h"
#include "Maitresse.h"
#include "EntourantCube.h"
#include "IndicateurMins.h"
#include "CubeHeure.h"

class Montre : public Piece
{
	
	float rotation, rotationHeure[3], rotationGlobalHeure[3];

	// Création des engrenages
	Engrenage* engrenage_M0p01_0p85;
	Engrenage* engrenage_M0p01_0p45;

	// Création de la piece maitresse
	Maitresse* maitresse;

	// Cache engrenage
	CacheEngrenage* _cacheEngrenage;

	// Cadre horraire
	EntourantCube* _pointeurHorraire;

	// Indicateur des minutes
	IndicateurMins* _indicateurMin;

	// Rotor
	PartialDisque *_rotorEngrenageFinal, *_rotorCubeHeure;

	// Cube heure
	CubeHeure *_cubeHeure[3];

public:
	Montre(void);
	virtual ~Montre(void);

	virtual void BuildAndDisplay();
	virtual void Update();
};

#endif