#include "IndicateurMins.h"
#include "Include.h"

IndicateurMins::IndicateurMins(double largSocle, double epaissSocle, double hauteurSocle, double hauteurPyram, double largSmt, double hauteurSmt)
	: _largSocle(largSocle),
	_epaissSocle(epaissSocle),
	_hauteurSocle(hauteurSocle),
	_hauteurPyram(hauteurPyram),
	_largSmt(largSmt),
	_hauteurSmt(hauteurSmt)
{
}

IndicateurMins::~IndicateurMins()
{
}

void IndicateurMins::BuildAndDisplay()
{
	Material mat = Material();
	

	Point3D * socleGauche = new Point3D[4]; // rectangle de gauche (socle)
	Point3D * socleDroite = new Point3D[4]; // 4 points du haut du socle (milieu)
	Point3D * smtPyram = new Point3D[4]; // rectangle de droite (sommet de la pyramide tronquée)

	//////////////////////////////////////
	// Remplissage des tableaux de points
	//////////////////////////////////////

	socleGauche[0] = Point3D(0.0, 0.0, 0.0);
	socleGauche[1] = Point3D(0.0, _hauteurSocle, 0.0);
	socleGauche[2] = Point3D(0.0, _hauteurSocle, -_largSocle);
	socleGauche[3] = Point3D(0.0, 0.0, - _largSocle);

	socleDroite[0] = Point3D(_epaissSocle, 0.0, 0.0);
	socleDroite[1] = Point3D(_epaissSocle, _hauteurSocle, 0.0);
	socleDroite[2] = Point3D(_epaissSocle, _hauteurSocle, -_largSocle);
	socleDroite[3] = Point3D(_epaissSocle, 0.0, - _largSocle);

	double posZ = -(_largSocle - _largSmt) / 2; // la face de droite (sommet de la pyramide) se trouve au centre par rapport à celle du socle

	smtPyram[0] = Point3D(_epaissSocle + _hauteurPyram, 0.0, posZ);
	smtPyram[1] = Point3D(_epaissSocle + _hauteurPyram, _hauteurSmt, posZ);
	smtPyram[2] = Point3D(_epaissSocle + _hauteurPyram, _hauteurSmt, posZ - _largSmt);
	smtPyram[3] = Point3D(_epaissSocle + _hauteurPyram, 0.0, posZ - _largSmt);

	/////////////////////////////
	// Construction de la pièce
	/////////////////////////////

	
	mat.ToWhiteReflect();
	mat.Enable();

	// la face de gauche (socle)

	glBegin(GL_QUADS);
		for(int i = 0; i < 4; i++)
			glVertex3f(socleGauche[i]._x, socleGauche[i]._y, socleGauche[i]._z);
	glEnd();

	// la face de droite (sommet de la pyramide tronquée)

	glBegin(GL_QUADS);
		for(int i = 3; i > -1; i--)
			glVertex3f(smtPyram[i]._x, smtPyram[i]._y, smtPyram[i]._z);
	glEnd();
	
	// les faces autour des bases pour le socle

	glBegin(GL_QUAD_STRIP);
		for(int i = 0; i < 4; i++)
		{
			glVertex3f(socleGauche[i]._x, socleGauche[i]._y, socleGauche[i]._z);
			glVertex3f(socleDroite[i]._x, socleDroite[i]._y, socleDroite[i]._z);
		}
		glVertex3f(socleGauche[0]._x, socleGauche[0]._y, socleGauche[0]._z);
		glVertex3f(socleDroite[0]._x, socleDroite[0]._y, socleDroite[0]._z);
	glEnd();
	
	// les faces autour des bases pour la pyramide tronquée
	

	glBegin(GL_QUAD_STRIP);
		for(int i = 0; i < 4; i++)
		{
			glVertex3f(socleDroite[i]._x, socleDroite[i]._y, socleDroite[i]._z);
			glVertex3f(smtPyram[i]._x, smtPyram[i]._y, smtPyram[i]._z);
		}
		
		glVertex3f(socleDroite[0]._x, socleDroite[0]._y, socleDroite[0]._z);
		glVertex3f(smtPyram[0]._x, smtPyram[0]._y, smtPyram[0]._z);
	glEnd();

	mat.ToBlackRubber();
	mat.Enable();

	// Sur indicateur
	glBegin(GL_QUADS);
		float ecartSoclePyrX = abs(socleDroite[1]._x - smtPyram[1]._x) * 0.02;
		float ecartSocleZ = abs(socleDroite[1]._y - socleDroite[2]._z) * 0.1;
		float ecartSmtPyrZ = abs(smtPyram[1]._z - smtPyram[2]._z) * 0.3;

		glVertex3f(socleDroite[1]._x + ecartSoclePyrX, socleDroite[1]._y + 0.002, socleDroite[1]._z - ecartSocleZ);
		glVertex3f(smtPyram[1]._x - ecartSoclePyrX, smtPyram[1]._y + 0.002, smtPyram[1]._z - ecartSmtPyrZ);
		glVertex3f(smtPyram[2]._x - ecartSoclePyrX, smtPyram[2]._y + 0.002, smtPyram[2]._z + ecartSmtPyrZ);
		glVertex3f(socleDroite[2]._x + ecartSoclePyrX, socleDroite[2]._y + 0.002, socleDroite[2]._z + ecartSocleZ);
	glEnd();

	mat.Disable();
}