
#include "Include.h"

#ifndef LIGHT_H
#define LIGHT_H


class Light
{
protected:
	GLenum _id;
	GLfloat _radius;
	GLfloat _color[4];
	GLfloat _position[3];
	GLfloat _ambiant[4];
	GLfloat _diffuse[4];
	GLfloat _specular[4];

	public:
		Light(GLenum id, GLfloat radius, GLfloat color[4], GLfloat position[3], GLfloat ambiant[4], GLfloat diffuse[4], GLfloat specular[4]);
		virtual ~Light(void);

		virtual void Display();
		virtual void Enable();
		virtual void Disable();
};

#endif