#include "AiguillesSec.h"

AiguillesSec::AiguillesSec(float longueur, float rayon, float epaiss) : _longueur(longueur), _rayon(rayon), _epaiss(epaiss)
{
}

AiguillesSec::~AiguillesSec()
{
}

void AiguillesSec::BuildAndDisplay()
{

	Material mat = Material();
	mat.ToBlackReflect();
	mat.Enable();

	GLUquadric * params = gluNewQuadric();

	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		gluCylinder(params, _rayon, _rayon, _epaiss, 100, 1);
		glTranslatef(0.0, 0.0, _epaiss);
		gluDisk(params, _rayon/6, _rayon, 100, 1);
		glTranslatef(0.0, 0.0, -_epaiss);
		glRotatef(180.0, 1.0, 0.0, 0.0);
		gluDisk(params, _rayon/6, _rayon, 100, 1);
	glPopMatrix();

	float largAig = _rayon/3;

	_aiguilleG = new Point3D[4];
	_aiguilleD = new Point3D[4];

	float posAig = -_rayon + _rayon/10;

	_aiguilleG[0] = Point3D(-1.5*largAig, 0, posAig);
	_aiguilleG[1] = Point3D(-largAig/4, 0, posAig);
	_aiguilleG[2] = Point3D(-largAig/4, 0, posAig - _longueur);
	_aiguilleG[3] = Point3D(-largAig, 0, posAig - _longueur);

	_aiguilleD[0] = Point3D(largAig/4, 0, posAig);
	_aiguilleD[1] = Point3D(1.5*largAig, 0, posAig);
	_aiguilleD[2] = Point3D(largAig, 0, posAig - _longueur);
	_aiguilleD[3] = Point3D(largAig/4, 0, posAig - _longueur);

	ConstrAig(_aiguilleG, 20);
	ConstrAig(_aiguilleD, 20);

	float diminuAig = 0.35;

	_aiguilleG[2]._z += _longueur * diminuAig;
	_aiguilleG[3]._z += _longueur * diminuAig;

	_aiguilleD[2]._z += _longueur * diminuAig;
	_aiguilleD[3]._z += _longueur * diminuAig;
	
	glPushMatrix();
		glRotatef(120, 0, 1, 0);
		ConstrAig(_aiguilleG, 20);
		ConstrAig(_aiguilleD, 20);
		
		glRotatef(120, 0, 1, 0);
		ConstrAig(_aiguilleG, 20);
		ConstrAig(_aiguilleD, 20);
	glPopMatrix();
}

void AiguillesSec::ConstrAig(Point3D * aiguille, float longPic)
{
	glBegin(GL_QUADS);
		for(int i = 0; i < 4; i++)
			glVertex3f(aiguille[i]._x, aiguille[i]._y, aiguille[i]._z);
	glEnd();
	
	glBegin(GL_QUADS);
		for(int i = 3; i > -1; i--)
			glVertex3f(aiguille[i]._x, aiguille[i]._y - _epaiss, aiguille[i]._z);
	glEnd();

	glBegin(GL_QUAD_STRIP);
		for(int i = 1; i < 4; i++)
		{
			glVertex3f(aiguille[i]._x, aiguille[i]._y, aiguille[i]._z);
			glVertex3f(aiguille[i]._x, aiguille[i]._y -_epaiss, aiguille[i]._z);
		}
		glVertex3f(aiguille[0]._x, aiguille[0]._y, aiguille[0]._z);
		glVertex3f(aiguille[0]._x, aiguille[0]._y - _epaiss, aiguille[0]._z);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0, -_epaiss / 2, _aiguilleG[3]._z - _longueur / longPic);
		glVertex3f(_aiguilleG[3]._x, _aiguilleG[3]._y, _aiguilleG[3]._z);
		glVertex3f(_aiguilleD[2]._x, _aiguilleD[2]._y, _aiguilleD[2]._z);
		glVertex3f(_aiguilleD[2]._x, _aiguilleD[2]._y - _epaiss, _aiguilleD[2]._z);
		glVertex3f(_aiguilleG[3]._x, _aiguilleG[3]._y - _epaiss, _aiguilleG[3]._z);
		glVertex3f(_aiguilleG[3]._x, _aiguilleG[3]._y, _aiguilleG[3]._z);
	glEnd();
}