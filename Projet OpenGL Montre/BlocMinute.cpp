#include "BlocMinute.h"


BlocMinute::BlocMinute(float rayon, float largBase, float longBase, float largBras, float longBras, float hauteur)
	:_rayon(rayon), _largBase(largBase), _longBase(longBase), _largBras(largBras), _longBras(longBras), _hauteur(hauteur)
{
}


BlocMinute::~BlocMinute(void)
{
}

void BlocMinute::BuildAndDisplay()
{
	float cos60 = cosf(DEGREES_TO_RADIANS(60.0));
	float sin60 = sinf(DEGREES_TO_RADIANS(60.0));
	float eHauteur = 0.5;
	float eHauteurTiges = 0.8;
	Point3D* pts = new Point3D[120 + 4 * 2];
	
	int nb = 0;
	// Point central
	//pts[nb++] = Point3D(cos60 + _longBase, 0.0, 0.0);

	// Faces gauche
	pts[nb++] = Point3D(_longBase + cos60, 0.0, _longBase/2);
	pts[nb++] = Point3D(cos60 + _longBras, 0.0, sin60 + _largBras);
	pts[nb++] = Point3D(cos60, 0.0, sin60 + _largBras);

	// Faces arcs
	int iArc1 = nb;
	for(int slice = 60; slice >= -60; slice--)
	{
		pts[nb++] = Point3D(_rayon * cosf(DEGREES_TO_RADIANS(slice)), 0.0, _rayon *  sinf(DEGREES_TO_RADIANS(slice)) );
	}
	int iArc2 = nb;
		
	// Faces droites
	pts[nb++] = Point3D(cos60, 0.0, - sin60 - _largBras);
	pts[nb++] = Point3D(cos60 + _longBras, 0.0, - sin60 - _largBras);
	pts[nb++] = Point3D(_longBase + cos60, 0.0, -_longBase/2);

	//glPolygonMode(GL_FRONT, GL_LINE);

	Material mat = Material();
	mat.ToChrome();
	mat.Enable();
	
	// Face du bas gauche
	glBegin(GL_TRIANGLE_FAN);
		for(int i=0; i<=iArc1 + 60; i++)
			glVertex3f(pts[i]._x, pts[i]._y, pts[i]._z);
	glEnd();

	// Face du bas droit
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(pts[nb-1]._x, pts[nb-1]._y, pts[nb-1]._z);
		for(int i=iArc1 + 60 ; i< nb-1; i++)
			glVertex3f(pts[i]._x, pts[i]._y, pts[i]._z);
	glEnd();

	// On relie les 2 faces du bas de droite et gauche
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(pts[nb-1]._x, pts[nb-1]._y, pts[nb-1]._z);
		glVertex3f(pts[iArc1+60]._x, pts[iArc1+60]._y, pts[iArc1+60]._z);
		glVertex3f(pts[0]._x, pts[0]._y, pts[0]._z);
	glEnd();

	// Face du haut gauche
	glBegin(GL_TRIANGLE_FAN);
		for(int i=0; i<iArc1; i++)
			glVertex3f(pts[i]._x, pts[i]._y + _hauteur, pts[i]._z);
		for(int i=iArc1; i<=iArc1 + 60; i++)
			glVertex3f(pts[i]._x, pts[i]._y + _hauteur * eHauteur, pts[i]._z);
	glEnd();

	// Face du haut droit
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(pts[nb-1]._x, pts[nb-1]._y + _hauteur, pts[nb-1]._z);
		for(int i=iArc1 + 60 ; i< iArc2; i++)
			glVertex3f(pts[i]._x, pts[i]._y + _hauteur * eHauteur, pts[i]._z);
		for(int i=iArc2 ; i< nb-1; i++)
			glVertex3f(pts[i]._x, pts[i]._y + _hauteur, pts[i]._z);
	glEnd();

	// On relie les 2 faces du haut de droite et gauche
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(pts[nb-1]._x, pts[nb-1]._y + _hauteur, pts[nb-1]._z);
		glVertex3f(pts[iArc1+60]._x, pts[iArc1+60]._y + _hauteur * eHauteur, pts[iArc1+60]._z);
		glVertex3f(pts[0]._x, pts[0]._y + _hauteur, pts[0]._z);
	glEnd();

	// Faces de cotés
	glBegin(GL_TRIANGLE_STRIP);
		for(int i=0; i<iArc1; i++)
		{
			glVertex3f(pts[i]._x, pts[i]._y, pts[i]._z);
			glVertex3f(pts[i]._x, pts[i]._y + _hauteur, pts[i]._z);
		}
		for(int i=iArc1 ; i<iArc2; i++)
		{
			glVertex3f(pts[i]._x, pts[i]._y, pts[i]._z);
			glVertex3f(pts[i]._x, pts[i]._y + _hauteur * eHauteur, pts[i]._z);
		}
		for(int i=iArc2; i<nb; i++)
		{
			glVertex3f(pts[i]._x, pts[i]._y, pts[i]._z);
			glVertex3f(pts[i]._x, pts[i]._y + _hauteur, pts[i]._z);
		}
		glVertex3f(pts[0]._x, pts[0]._y, pts[0]._z);
		glVertex3f(pts[0]._x, pts[0]._y + _hauteur, pts[0]._z);
	glEnd();

	mat = Material();
	mat.ToRuby();
	mat.Enable();
	
		float angle = 2;
		Point3D pCentre = Point3D(_rayon, _hauteur*eHauteur/1.15, 0);
		for(int i=-60; i<=60; i+=2)
		{
			
			glPushMatrix();

				float rad = DEGREES_TO_RADIANS(i);
				glRotatef(2.0, 0.0, 0.0, 1.0);
				glTranslatef(cosf(rad) * pCentre._x + sinf(rad) * pCentre._z , pCentre._y - (60-abs(i)) * 0.001, -sinf(rad) * pCentre._x + cosf(rad) * pCentre._z);
				glRotatef(i, 0.0, 1.0, 0.0);
				
				if(abs(i)<=20)
					glRotatef(20, 0.0, 0.0, 1.0);
				else if(abs(i) > 20 && abs(i) <= 30)
					glRotatef(20, 0.0, 0.0, 1.0);
				else if(abs(i) > 30 && abs(i) <= 40)
					glRotatef(25, 0.0, 0.0, 1.0);
				else if(abs(i) > 40 && abs(i) <= 50)
					glRotatef(27.5, 0.0, 0.0, 1.0);
				else if(abs(i) > 50)
					glRotatef(30, 0.0, 0.0, 1.0);

				glTranslatef(_largBras * 0.25, 0.0, 0.0);
				glScalef(i%5==0?_largBras * 0.35:_largBras*0.35/2, _largBase/(60 * 1.5), _largBase/(60 * 1.5));

				glPushMatrix();
					glutSolidCube(1);
				glPopMatrix();
			glPopMatrix();
		}

	mat.Disable();

	delete pts;
}

