#include "SpotLight.h"


SpotLight::SpotLight(GLenum id, GLfloat radius, GLfloat color[4], GLfloat position[3], GLfloat direction[3], GLfloat ambiant[4], GLfloat diffuse[4], GLfloat specular[4])
	:Light(id, radius, color, position, ambiant, diffuse, specular)
{
	for(int i=0; i<3; i++)
	{
		_direction[i] = direction[i];
	}
}


SpotLight::~SpotLight(void)
{
}


void SpotLight::Display()
{
	float dx = _direction[0];
	float dy = _direction[1];
	float dz = _direction[2];

	double d = powf(dx*dx+dy*dy+dz*dz,0.5);
	glPushMatrix();
		dx /= d; 
		dy /= d; 
		dz /= d;

		if ( fabs(dz-(-1.0F)) < 0.00001 )
			glRotatef(180.0F,1.0F,0.0F,0.0F);
		else
			if ( !(fabs(dz-1.0F) < 0.00001) ) {
				double a = acos(dz) * 180 / 3.14159;
				glRotatef(a,-dy,dx,0); 
			}
	
		glPushMatrix();
			glRotatef(90.0F,1.0F,0.0F,0.0F);
			glRotatef(180.0F,0.0F,0.0F,1.0F);
			glTranslatef(0.0F,-d/2.0F,0.0F);
			glutSolidCone(0.05, 0.1, 50, 50);
		glPopMatrix();
	glPopMatrix();
}

void SpotLight::Enable()
{
	glLightfv(_id, GL_SPOT_DIRECTION, _direction);
	Light::Enable();
}

void SpotLight::Disable()
{
	Light::Disable();
}