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
