#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

#include "light.h"

class SpotLight : public Light
{

	GLfloat _direction[3];

public:
	SpotLight(GLenum id, GLfloat radius, GLfloat color[4], GLfloat position[3], GLfloat direction[3], GLfloat ambiant[4], GLfloat diffuse[4], GLfloat specular[4]);
	virtual ~SpotLight(void);

	virtual void Display();
	virtual void Enable();
	virtual void Disable();
};

#endif

