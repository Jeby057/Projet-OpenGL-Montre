/**
 * Classe SpotLight
 * ****************
 *  Regroupe toutes les m�thodes Opengl concernant la lumi�re
 *  Permet de de cr�er, de mat�rialiser une lumi�re, et de l'allumer ou de l'eteindre
 *  Type de lumiere : Spot
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 2 D�cembre 2012
 * Version : 1
 */
#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

#include "light.h"

class SpotLight : public Light
{
	// Direction du spot
	GLfloat _direction[3];

	// Param�tre dy spot
	double _cutoff, _exponent;

public:

	/**
		 * Constrution d'une lumi�re
		 * id : Identifiant de la lumi�re
		 * direction : Direction du spot
		 * position : Position de la lumi�re
		 * ambiant, diffuse, specular : param�tres de la lumi�re
		 * cutoff, exponent : param�tre dy spot
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
