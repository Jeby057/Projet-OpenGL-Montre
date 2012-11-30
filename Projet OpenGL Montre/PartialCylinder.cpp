#include "PartialCylinder.h"


PartialCylinder::PartialCylinder(float start, float end, int subdiv, float radius, float height)
	:_start(start),
	_end(end),
	_subdiv(subdiv),
	_radius(radius),
	_height(height)
{
}


PartialCylinder::~PartialCylinder(void)
{
}


void PartialCylinder::BuildAndDisplay(){

	

	const float lStep = (_end - _start) / (_subdiv - 1);
	Point3D** pCylinder = new Point3D*[_subdiv];
	Point3D pattern(0, _radius, 0);

	for (int k = 0 ; k < _subdiv ; k++)
		pCylinder[k] = new Point3D(pattern._x * cosf(-k * DEGREES_TO_RADIANS(_start+lStep)) - pattern._y * sinf(-k * DEGREES_TO_RADIANS(lStep)), pattern._x * sinf(-k * DEGREES_TO_RADIANS(_start+lStep)) + pattern._y * cosf(-k * DEGREES_TO_RADIANS(_start+lStep)), pattern._z);

	// Pourtour
	glBegin(GL_TRIANGLE_STRIP);
		for (int k = 0 ; k < _subdiv ; k++)
		{
			glVertex3f(pCylinder[k]->_x, pCylinder[k]->_y, pCylinder[k]->_z);
			glVertex3f(pCylinder[k]->_x, pCylinder[k]->_y, pCylinder[k]->_z + _height);
		}
    glEnd();
	
	// Cotés
	for(int i=0; i<_subdiv; i+=_subdiv-1)
	{
		glBegin(GL_QUADS);
			glVertex3f(0.0F, 0.0F, _height);
			glVertex3f(0.0F, 0.0F, 0.0F);
			glVertex3f(pCylinder[i]->_x, pCylinder[i]->_y, pCylinder[i]->_z);
			glVertex3f(pCylinder[i]->_x, pCylinder[i]->_y, pCylinder[i]->_z + _height);
		glEnd();
	}
	
	for(int i=0; i<_subdiv; i++)
		delete[] pCylinder[i];
	delete[] pCylinder;

}