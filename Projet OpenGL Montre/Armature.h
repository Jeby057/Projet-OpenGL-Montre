#ifndef ARMATURE_H
#define ARMATURE_H

#include "Piece.h"
#include "Couleurs.h"

class Armature : public Piece
{
private:
	float _longueur;
	float _largeur;
	float _epaisseur;
	float _transparency;
	//float _rayonTurbine;
	//float _decalTurbX; // décalage en X par rapport au bord de droite pour obtenir le X du centre de la turbine
	//float _decalTurbY; // décalage en Y par rapport au bord du haut pour obtenir le Y du centre de la turbine

	Couleur *couleur;
public:

	Armature(float longueur, float largeur, float epaisseur);//, float rayonTurbine, float decalTurbX, float decalTurbY);
	virtual ~Armature(void);

	virtual void BuildAndDisplay();
	virtual void FastDisplay();
	void SetTransparency(float transparency);
};
#endif
