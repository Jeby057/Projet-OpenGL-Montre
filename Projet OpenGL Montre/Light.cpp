#include "Light.h"


Light::Light(GLenum id, GLfloat radius, GLfloat color[4], GLfloat position[3], GLfloat ambiant[4], GLfloat diffuse[4], GLfloat specular[4])
	:_id(id), _radius(radius)
{
	for(int i=0; i<4; i++)
	{
		_color[i] = color[i];
		_ambiant[i] = ambiant[i];
		_diffuse[i] = diffuse[i];
		_specular[i] = specular[i];
		if(i!=3)
			_position[i] = position[i];
	}
}


Light::~Light(void)
{
}


void Light::Display()
{
	glPushMatrix();
		glTranslatef(_position[0], _position[1], _position[2] );
		glutSolidSphere(0.1, 50, 50);
	glPopMatrix();
}

void Light::Enable()
{
	glLightfv(_id, GL_POSITION, _position);
	glLightfv(_id, GL_AMBIENT, _ambiant);
	glLightfv(_id, GL_DIFFUSE, _diffuse);
	glLightfv(_id, GL_SPECULAR, _specular);
	glEnable(_id);
}

void Light::Disable()
{
	glDisable(_id);
}