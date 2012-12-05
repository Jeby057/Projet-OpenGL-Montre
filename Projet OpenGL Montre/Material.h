/**
 * Classe Maitresse
 * ****************
 * Pièce maitresse en 3 bras de la montre.
 * Permet de maintenir les bras tenant les cubes des heures
 * 
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 29 novembre 2012
 * Version : 1
 */
#ifndef MATERIAL_H
#define MATERIAL_H

#include "Include.h"

class Material
{
private:
	GLfloat _ambiant[4];
	GLfloat _diffuse[3];
	GLfloat _specular[3];
	GLfloat _shininess;

public:
	Material(GLfloat alpha = 1.0);
	Material(const GLfloat ambiant[4], const GLfloat diffuse[3], const GLfloat specular[3], const GLfloat shininess, GLfloat alpha = 1.0);
	~Material(void);
	
	void Enable();
	void Disable();


	void ToChrome();
	void ToSilver();
	void ToBlackRubber();
	void ToMagentaReflect();
	void ToBlackReflect();
	void ToGreyReflect();
	void ToWhiteReflect();
	void ToRedReflect();
	void ToBlueDark();
	void ToCopper();
	void ToGold();
	void ToRuby();
};
#endif
