#ifndef CONTENANT_TURBINE_H
#define CONTENANT_TURBINE_H

#include "Include.h"
#include "Piece.h"
#include "Couleurs.h"

class ContenantTurbine : public Piece
{
	float _largeur, _hauteur;
	Couleur *couleur;
public:
	ContenantTurbine(float largeur, float hauteur);
	~ContenantTurbine(void);

	virtual void BuildAndDisplay();

	void Glace();
	void MontureGlace();
};

#endif