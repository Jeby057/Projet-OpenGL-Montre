#include "CacheEngrenage.h"


CacheEngrenage::CacheEngrenage(float diametreInterne, float diametreExterne, int slices, float height, int angle, float hjupe, float ljupe):
	_diametreExterne(diametreExterne),
	_diametreInterne(diametreInterne),
	_slices(slices),
	_height(height),
	_angle(angle),
	_hjupe(hjupe),
	_ljupe(ljupe)
{
	partialDisqueInterne = new PartialDisque(0, diametreInterne, _height, _slices, 180);
	partialDisqueInterne->BuildAndSave();
}


CacheEngrenage::~CacheEngrenage(void)
{
	delete partialDisqueInterne;
}


void CacheEngrenage::BuildAndDisplay()
{
	Material mat = Material();
	mat.ToGreyReflect();
	mat.Enable();


	// Calcul de l'angle partiel
	float anglePartH   =(_angle-180) / 2;
	float anglePartB   = -anglePartH;
	float decal = 0.1 * _diametreExterne;

	// Affichage du disque interne
	partialDisqueInterne->FastDisplay();
	
	// Calculs des points de références
	Point3D pIntH(0, _diametreInterne/2, 0);
	Point3D pIntB(0, -_diametreInterne/2, 0);
	Point3D pExtIntH(0, _diametreExterne/2, 0);
	Point3D pExtIntB(0, -_diametreExterne/2, 0);
	Point3D pExtH(pExtIntH._x * cosf(DEGREES_TO_RADIANS(anglePartH)) - pExtIntH._y * sinf(DEGREES_TO_RADIANS(anglePartH)), pExtIntH._x * sinf(DEGREES_TO_RADIANS(anglePartH)) + pExtIntH._y * cosf(DEGREES_TO_RADIANS(anglePartH)), pExtIntH._z);
	Point3D pExtB(pExtIntB._x * cosf(DEGREES_TO_RADIANS(anglePartB)) - pExtIntB._y * sinf(DEGREES_TO_RADIANS(anglePartB)), pExtIntB._x * sinf(DEGREES_TO_RADIANS(anglePartB)) + pExtIntB._y * cosf(DEGREES_TO_RADIANS(anglePartB)), pExtIntB._z);
	Point3D pOppH(-_diametreExterne/2, _diametreExterne/4, 0);
	Point3D pOppB(-_diametreExterne/2, -_diametreExterne/4, 0);

	// Centre vers le haut 
	glBegin(GL_QUADS);
		glVertex3f(pIntH._x, pIntH._y, pIntH._z + _height);
		glVertex3f(pIntH._x, pIntH._y, pIntH._z);
		glVertex3f(pExtH._x, pExtH._y, pExtH._z);
		glVertex3f(pExtH._x, pExtH._y, pExtH._z + _height);
	glEnd();

	// Centre vers le bas
	glBegin(GL_QUADS);
		glVertex3f(pIntB._x, pIntB._y, pIntB._z + _height);
		glVertex3f(pIntB._x, pIntB._y, pIntB._z);
		glVertex3f(pExtB._x, pExtB._y, pExtB._z);
		glVertex3f(pExtB._x, pExtB._y, pExtB._z + _height);
	glEnd();

	// Decalage en haut
	glBegin(GL_QUADS);
		glVertex3f(pExtH._x, pExtH._y, pExtH._z - _hjupe);
		glVertex3f(pExtH._x, pExtH._y, pExtH._z + _height);
		glVertex3f(pExtH._x - decal - _ljupe, pExtH._y, pExtH._z + _height);
		glVertex3f(pExtH._x - decal - _ljupe, pExtH._y, pExtH._z - _hjupe);
	glEnd();

	// Decalage en bas
	glBegin(GL_QUADS);
		glVertex3f(pExtB._x, pExtB._y, pExtB._z - _hjupe);
		glVertex3f(pExtB._x, pExtB._y, pExtB._z + _height);
		glVertex3f(pExtB._x - decal - _ljupe, pExtB._y, pExtB._z + _height);
		glVertex3f(pExtB._x - decal - _ljupe, pExtB._y, pExtB._z - _hjupe);
	glEnd();

	// Fermeture haut
	glBegin(GL_QUADS);
		glVertex3f(pOppH._x - _ljupe, pOppH._y, pOppH._z - _hjupe);
		glVertex3f(pOppH._x - _ljupe, pOppH._y, pOppH._z + _height);
		glVertex3f(pExtH._x - decal - _ljupe, pExtH._y, pExtH._z + _height);
		glVertex3f(pExtH._x - decal - _ljupe, pExtH._y, pExtH._z - _hjupe);
	glEnd();

	// Fermeture bas
	glBegin(GL_QUADS);
		glVertex3f(pOppB._x - _ljupe, pOppB._y, pOppB._z - _hjupe);
		glVertex3f(pOppB._x - _ljupe, pOppB._y, pOppB._z + _height);
		glVertex3f(pExtB._x - decal - _ljupe, pExtB._y, pExtB._z + _height);
		glVertex3f(pExtB._x - decal - _ljupe, pExtB._y, pExtB._z - _hjupe);
	glEnd();

	// Fermeture finale
	glBegin(GL_QUADS);
		glVertex3f(pOppH._x - _ljupe, pOppH._y, pOppH._z - _hjupe);
		glVertex3f(pOppH._x - _ljupe, pOppH._y, pOppH._z + _height);
		glVertex3f(pOppB._x - _ljupe, pOppB._y, pOppB._z + _height);
		glVertex3f(pOppB._x - _ljupe, pOppB._y, pOppB._z - _hjupe);
	glEnd();

	// Cache du haut
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0,0,_height);
		glVertex3f(pIntH._x, pIntH._y, pIntH._z + _height);
		glVertex3f(pExtH._x, pExtH._y, pExtH._z + _height);
		glVertex3f(pExtH._x - decal - _ljupe, pExtH._y, pExtH._z + _height);
		glVertex3f(pOppH._x - _ljupe, pOppH._y, pOppH._z + _height);
		glVertex3f(pOppB._x - _ljupe, pOppB._y, pOppB._z + _height);
		glVertex3f(pExtB._x - decal - _ljupe, pExtB._y, pExtB._z + _height);
		glVertex3f(pExtB._x, pExtB._y, pExtB._z + _height);
		glVertex3f(pIntB._x, pIntB._y, pIntB._z + _height);
	glEnd();

	// Cache du bas
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(pIntH._x, pIntH._y, pIntH._z );
		glVertex3f(pExtH._x, pExtH._y, pExtH._z );
		glVertex3f(pExtH._x - decal, pExtH._y, pExtH._z );
		glVertex3f(pOppH._x, pOppH._y, pOppH._z );
		glVertex3f(pOppB._x, pOppB._y, pOppB._z);
		glVertex3f(pExtB._x - decal, pExtB._y, pExtB._z);
		glVertex3f(pExtB._x, pExtB._y, pExtB._z);
		glVertex3f(pIntB._x, pIntB._y, pIntB._z );
	glEnd();

	// Création de la jupe
	glBegin(GL_TRIANGLE_STRIP);
		//glVertex3f(pExtH._x, pExtH._y, pExtH._z);
	    //glVertex3f(pExtH._x , pExtH._y, pExtH._z - _hjupe);
		//glVertex3f(pExtH._x + decal - _ljupe, pExtH._y - _ljupe, pExtH._z);
		//glVertex3f(pExtH._x + decal - _ljupe, pExtH._y - _ljupe, pExtH._z - _hjupe);
		glVertex3f(pExtH._x - decal - _ljupe, pExtH._y - _ljupe, pExtH._z);
		glVertex3f(pExtH._x - decal - _ljupe, pExtH._y - _ljupe, pExtH._z - _hjupe);
		glVertex3f(pOppH._x , pOppH._y, pOppH._z);
		glVertex3f(pOppH._x , pOppH._y, pOppH._z - _hjupe);
		glVertex3f(pOppB._x , pOppB._y, pOppB._z);
		glVertex3f(pOppB._x, pOppB._y, pOppB._z - _hjupe);
		glVertex3f(pExtB._x - decal - _ljupe, pExtB._y + _ljupe, pExtB._z);
		glVertex3f(pExtB._x - decal - _ljupe, pExtB._y + _ljupe, pExtB._z - _hjupe);
		//glVertex3f(pExtB._x + decal - _ljupe, pExtB._y + _ljupe, pExtB._z);
		//glVertex3f(pExtB._x + decal - _ljupe, pExtB._y + _ljupe, pExtB._z - _hjupe);
		//glVertex3f(pExtB._x, pExtB._y, pExtB._z);
		//glVertex3f(pExtB._x , pExtB._y, pExtB._z - _hjupe);
	glEnd();

	// Fermeture en bas de la jupe
	glBegin(GL_TRIANGLE_STRIP);
		//glVertex3f(pExtH._x + decal - _ljupe, pExtH._y - _ljupe, pExtH._z - _hjupe);
		//glVertex3f(pExtH._x, pExtH._y, pExtH._z - _hjupe);
		//glVertex3f(pExtH._x, pExtH._y - _ljupe, pExtH._z - _hjupe);
		//glVertex3f(pExtH._x - decal - _ljupe, pExtH._y, pExtH._z - _hjupe);
		glVertex3f(pExtH._x - decal - _ljupe, pExtH._y - _ljupe, pExtH._z - _hjupe);
		glVertex3f(pOppH._x - _ljupe, pOppH._y, pOppH._z - _hjupe);
		glVertex3f(pOppH._x, pOppH._y, pOppH._z - _hjupe);
		glVertex3f(pOppB._x - _ljupe, pOppB._y, pOppB._z - _hjupe);
		glVertex3f(pOppB._x, pOppB._y, pOppB._z - _hjupe);
		glVertex3f(pExtB._x - decal - _ljupe, pExtB._y, pExtB._z - _hjupe);
		//glVertex3f(pExtB._x - decal - _ljupe, pExtB._y + _ljupe, pExtB._z - _hjupe);
		//glVertex3f(pExtB._x, pExtB._y, pExtB._z - _hjupe);
		//glVertex3f(pExtB._x, pExtB._y + _ljupe, pExtB._z - _hjupe);
		//glVertex3f(pExtB._x + decal - _ljupe, pExtB._y + _ljupe, pExtB._z - _hjupe);
	glEnd();
}

