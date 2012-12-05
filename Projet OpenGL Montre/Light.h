/**
 * Classe Light
 * ************
 * Regroupe toutes les m�thodes Opengl concernant la lumi�re
 * Permet de de cr�er, de mat�rialiser une lumi�re, et de l'allumer ou de l'eteindre
 * 
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 29 novembre 2012
 * Version : 1
 */
#include "Include.h"

#ifndef LIGHT_H
#define LIGHT_H


class Light
{
protected:

	// Id de la lumi�re (entre 0 et 8)
	GLenum _id;

	// Param�tres de la lumi�res
	GLfloat _position[3];
	GLfloat _ambiant[4];
	GLfloat _diffuse[4];
	GLfloat _specular[4];

	public:

		/**
		 * Constrution d'une lumi�re
		 * id : Identifiant de la lumi�re
		 * position : Position de la lumi�re
		 * ambiant, diffuse, specular : param�tres de la lumi�re
		 */
		Light(GLenum id, GLfloat position[3], GLfloat ambiant[4], GLfloat diffuse[4], GLfloat specular[4]);
		virtual ~Light(void);

		/**
		 * Permet de materialiser la lumiere
		 */
		virtual void Display();

		/**
		 * Permet d'allumer la lumi�re
		 */
		virtual void Enable();

		/**
		 * Permet de d�sactiver la lumi�re
		 */
		virtual void Disable();
};
#endif
