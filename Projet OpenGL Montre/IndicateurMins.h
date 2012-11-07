#ifndef INDICATEURMINS_H
#define INDICATEURMINS_H

#include "Piece.h"

class IndicateurMins : public Piece
{
private:
	double _largSocle; // largeur du socle à gauche (sur z)
	double _epaissSocle; // épaisseur du socle (sur x)
	double _hauteurSocle; // hauteur du socle (sur y)
	double _hauteurPyram; // hauteur de la pyramide tronquée (face couchée sur le plan xz)
	double _largSmt; // largeur du sommet (sur z)
	double _hauteurSmt; // hauteur du sommet (sur y)

public:
	IndicateurMins(double largSocle, double epaissSocle, double hauteurSocle, double hauteurPyram, double largSmt, double hauteurSmt);
	virtual ~IndicateurMins(void);

	virtual void BuildAndDisplay();
};

#endif