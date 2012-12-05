#include "SpotLight.h"


SpotLight::SpotLight(GLenum id, GLfloat position[3], GLfloat direction[3], GLfloat ambiant[4], GLfloat diffuse[4], GLfloat specular[4], double cutoff, double exponent)
	:Light(id, position, ambiant, diffuse, specular), _cutoff(cutoff), _exponent(exponent)
{
	for(int i=0; i<3; i++)
	{
		_direction[i] = direction[i];
	}
}


SpotLight::~SpotLight(void)
{
}


void SpotLight::Enable()
{
	glLightfv(_id, GL_SPOT_DIRECTION, _direction);
	glLightf(_id,GL_SPOT_CUTOFF,_cutoff);
	glLightf(_id,GL_SPOT_EXPONENT,_exponent);
	Light::Enable();
}

void SpotLight::Disable()
{
	Light::Disable();
}
