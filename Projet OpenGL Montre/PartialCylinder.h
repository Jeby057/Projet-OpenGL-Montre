/**
 * Classe Cylindre partiel
 * ***********************
 *  Permet de construire un cylindre partiel
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 29 novembre 2012
 * Version : 1
 */
#ifndef PARTIAL_CYLINDER_H
#define PARTIAL_CYLINDER_H
#include "Include.h"
#include "Piece.h"

class PartialCylinder : public Piece
{
	// Start correspond au degré de coupure (en deg)
	float _start;

	// End correspond au degré de fermeture (en deg)
	float _end;

	// Nombre de subdivisions
	int _subdiv;

	// Rotation du cylindre
	float _radius;

	// Hauteur du cylindre
	float _height;

public:

	/**
	 * start: degré de départ de coupure
	 * end : degré de fin de coupure
	 * subdiv : nombre de subdivisions
	 * radius : rayon du cylindre
	 * height : hauteur du cylindre
	 */
	PartialCylinder(float start, float end, int subdiv, float radius, float height);

	virtual ~PartialCylinder(void);

	virtual void BuildAndDisplay();
};
#endif
