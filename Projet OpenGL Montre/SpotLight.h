#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

#include "light.h"

class SpotLight : public Light
{

	GLfloat _direction[3];
	double _cutoff, _exponent;

public:
	SpotLight(GLenum id, GLfloat position[3], GLfloat direction[3], GLfloat ambiant[4], GLfloat diffuse[4], GLfloat specular[4], double cutoff, double exponent);
	virtual ~SpotLight(void);

	virtual void Display();
	virtual void Enable();
	virtual void Disable();
};
#endif
