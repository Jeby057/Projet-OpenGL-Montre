/**
 * Classe Cylindre partiel
 * ***********************
 *  Permet de construire un cylindre partiel
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 29 novembre 2012
 * Version : 1
 */
#ifndef PARTIAL_CYLINDER_H
#define PARTIAL_CYLINDER_H
#include "Include.h"
#include "Piece.h"

class PartialCylinder : public Piece
{
	// Start correspond au degr� de coupure (en deg)
	float _start;

	// End correspond au degr� de fermeture (en deg)
	float _end;

	// Nombre de subdivisions
	int _subdiv;

	// Rotation du cylindre
	float _radius;

	// Hauteur du cylindre
	float _height;

public:

	/**
	 * start: degr� de d�part de coupure
	 * end : degr� de fin de coupure
	 * subdiv : nombre de subdivisions
	 * radius : rayon du cylindre
	 * height : hauteur du cylindre
	 */
	PartialCylinder(float start, float end, int subdiv, float radius, float height);

	virtual ~PartialCylinder(void);

	virtual void BuildAndDisplay();
};
#endif
