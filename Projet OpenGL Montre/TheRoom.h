#ifndef	THEROOM_H
#define THEROOM_H

#include "Include.h"
#include "Piece.h"
#include "PPMImage.h"
#include "Couleurs.h"

class TheRoom : public Piece
{
	float _taille;
	Couleur *couleur;

	//les face de cube
	GLuint	_mur1, _mur2, _mur3, _mur4,
			_plafond, _sole;
public:
	TheRoom(float taille);
	virtual ~TheRoom(void);
	
	virtual void BuildAndDisplay();


	void TheMuseum();
	void VitrineExposition(float largeur, float hauteur);
	void Lustre(float largeur, float hauteur);

	//fonction partielle
	void VitreTransparante();
	void CylindreRemplis();
	void CylindreCrue(float epaisseur);
};
#endif
