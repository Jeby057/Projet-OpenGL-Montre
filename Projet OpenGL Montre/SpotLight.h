/**
 * Classe SpotLight
 * ****************
 *  Regroupe toutes les méthodes Opengl concernant la lumière
 *  Permet de de créer, de matérialiser une lumière, et de l'allumer ou de l'eteindre
 *  Type de lumiere : Spot
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 2 Décembre 2012
 * Version : 1
 */
#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

#include "light.h"

class SpotLight : public Light
{
	// Direction du spot
	GLfloat _direction[3];

	// Paramètre dy spot
	double _cutoff, _exponent;

public:

	/**
		 * Constrution d'une lumière
		 * id : Identifiant de la lumière
		 * direction : Direction du spot
		 * position : Position de la lumière
		 * ambiant, diffuse, specular : paramètres de la lumière
		 * cutoff, exponent : paramètre dy spot
		 */
	SpotLight(GLenum id, GLfloat position[3], GLfloat direction[3], GLfloat ambiant[4], GLfloat diffuse[4], GLfloat specular[4], double cutoff, double exponent);

	virtual ~SpotLight(void);

	/**
	 * Allume le spot
	 */
	virtual void Enable();

	/**
	 * Eteind le spot
	 */
	virtual void Disable();
};
#endif
