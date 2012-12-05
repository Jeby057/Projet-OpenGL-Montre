/**
 * Classe Light
 * ************
 * Regroupe toutes les méthodes Opengl concernant la lumière
 * Permet de de créer, de matérialiser une lumière, et de l'allumer ou de l'eteindre
 * 
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 29 novembre 2012
 * Version : 1
 */
#include "Include.h"

#ifndef LIGHT_H
#define LIGHT_H


class Light
{
protected:

	// Id de la lumière (entre 0 et 8)
	GLenum _id;

	// Paramètres de la lumières
	GLfloat _position[3];
	GLfloat _ambiant[4];
	GLfloat _diffuse[4];
	GLfloat _specular[4];

	public:

		/**
		 * Constrution d'une lumière
		 * id : Identifiant de la lumière
		 * position : Position de la lumière
		 * ambiant, diffuse, specular : paramètres de la lumière
		 */
		Light(GLenum id, GLfloat position[3], GLfloat ambiant[4], GLfloat diffuse[4], GLfloat specular[4]);
		virtual ~Light(void);

		/**
		 * Permet de materialiser la lumiere
		 */
		virtual void Display();

		/**
		 * Permet d'allumer la lumière
		 */
		virtual void Enable();

		/**
		 * Permet de désactiver la lumière
		 */
		virtual void Disable();
};
#endif
