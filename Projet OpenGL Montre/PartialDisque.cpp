#include "PartialDisque.h"


PartialDisque::PartialDisque(float diametreInterieur, float diametreExterieur, float height, int slices, float angle)
	:_diametreInterieur(diametreInterieur),
	_diametreExterieur(diametreExterieur),
	_height(height),
	_slices(slices),
	_angle(angle)
{
	_cylExtPartiel = new PartialCylinder(0, _angle, _slices, _diametreExterieur/2, _height);
	_cylExtPartiel->BuildAndSave();
}


PartialDisque::~PartialDisque(void)
{
	delete _cylExtPartiel;
}


void PartialDisque::BuildAndDisplay()
{

	// Génération du cylindre partiel exterieur
	_cylExtPartiel->FastDisplay();

	// Génération du cylindre interieur
	if(_diametreInterieur != 0){
		GLUquadric* paramsCylInt = gluNewQuadric();
		gluCylinder(paramsCylInt, _diametreInterieur/2, _diametreInterieur/2,_height,_slices,1);
	}

	// Géréation des 2 disques
	GLUquadric* paramsDiscH = gluNewQuadric();
	gluPartialDisk(paramsDiscH,_diametreInterieur/2,_diametreExterieur/2,_slices,1, 0, _angle);
	gluDisk(paramsDiscH,0,_diametreInterieur/2,_slices,1);

	glPushMatrix();
		glTranslatef(0.0, 0.0, _height);
		GLUquadric* paramsDiscB = gluNewQuadric();
		gluPartialDisk(paramsDiscH,_diametreInterieur/2,_diametreExterieur/2,_slices,1, 0, _angle);
		gluDisk(paramsDiscH,0,_diametreInterieur/2,_slices,1);
	glPopMatrix();
	
	float angle = DEGREES_TO_RADIANS(15);
	// Pattern
	Point3D patternFlanc[2], flanc[4];
	patternFlanc[0] = Point3D(0, -_diametreExterieur/2, 0);
	patternFlanc[1] = Point3D(0, -_diametreExterieur/2, _height);

	for(int i=0; i<4; i++)
		flanc[i] = Point3D(patternFlanc[i%2]._x * cosf((i>1)?-angle:angle) - patternFlanc[i%2]._y * sinf((i>1)?-angle:angle), patternFlanc[i%2]._x * sinf((i>1)?-angle:angle) + patternFlanc[i%2]._y * cosf((i>1)?-angle:angle), patternFlanc[i%2]._z);

}
