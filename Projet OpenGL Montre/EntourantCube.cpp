#include "EntourantCube.h"
#include "Include.h"

EntourantCube::EntourantCube(double largeurG, double longCoinG, double longHaut, double epaissG, double epaissD, double longNiveau,
	double longBas, double prcLargPoseTri, double hauteur)
	: _largeurG(largeurG),
	_longCoinG(longCoinG),
	_longHaut(longHaut),
	_epaissG(epaissG),
	_epaissD(epaissD),
	_longNiveau(longNiveau),
	_longBas(longBas),
	_prcLargPoseTri(prcLargPoseTri),
	_hauteur(hauteur)
{
	_angleCoinG = DEGREES_TO_RADIANS(45);
	_angleNiveau = DEGREES_TO_RADIANS(30);
	_angleInvNiveau = DEGREES_TO_RADIANS(30);

	_largeurD = sinf(_angleCoinG)*_longCoinG*2 + _largeurG;

	_prctLargD = 0.7;
}

EntourantCube::~EntourantCube(void)
{
}

void EntourantCube::BuildAndDisplay()
{
	double angle = atanf((cosf(_angleCoinG)*_epaissG)/_longCoinG);
	double diag = sqrt(cosf(_angleCoinG)*_epaissG*cosf(_angleCoinG)*_epaissG + _longCoinG*_longCoinG);
	double largPoseTri = _prcLargPoseTri*_largeurD; // La largeur pour poser l'indicateur minutes
	double largD = ((1 - _prcLargPoseTri)* _largeurD)/2; // Le reste de largeur divisé par 2 (de chaque coté car moitié bas et moitié bas)
	double posX, posY, posZ;
	double xNiv, yNiv;

	Point3D ptsTourExt[21], ptsTourInt[15]; // points du tour intérieur et extérieur, dessus
	Point3D ptsTourExtS[16], ptsTourIntS[10]; // points du tour intérieur et extérieur, dessous

	// Remplissage des tableaux de points

	// moitié bas
	
	ptsTourExt[0] = Point3D(-_epaissG, _largeurG, 0.0);
	ptsTourExt[1] = Point3D(-_epaissG, 0.0, 0.0);
	ptsTourExt[2] = Point3D(-(cosf(_angleCoinG)*cosf(_angleCoinG)*_epaissG), -(cosf(_angleCoinG)*sinf(_angleCoinG)*_epaissG), 0.0);
	ptsTourExt[3] = Point3D(diag*cosf(_angleCoinG+angle), -diag*sinf(_angleCoinG+angle), 0.0);

	ptsTourInt[0] = Point3D(0.0, 0.0, 0.0);
	ptsTourInt[1] = Point3D(0.0, _largeurG, 0.0);
	ptsTourInt[14] = Point3D(cosf(_angleCoinG)*_longCoinG, -sinf(_angleCoinG)*_longCoinG, 0.0);

	posX = cosf(_angleCoinG)*_longCoinG;
	posY = -sinf(_angleCoinG)*_longCoinG;

	ptsTourExt[4] = Point3D(posX, posY - _epaissG, 0.0);
	ptsTourExt[5] = Point3D(posX + _longHaut, posY - _epaissG, 0.0);

	ptsTourInt[13] = Point3D(posX + _longHaut, posY, 0.0);

	posX += _longHaut;
	posZ = -cosf(_angleNiveau)*_longNiveau;
	xNiv = sinf(_angleNiveau)*_longNiveau;

	ptsTourInt[12] = Point3D(posX + xNiv, posY, posZ);

	ptsTourExt[6] = Point3D(posX + xNiv, posY - _epaissG, posZ);
	ptsTourExt[7] = Point3D(posX + xNiv + _longBas, posY - _epaissD, posZ);
	ptsTourExt[8] = Point3D(posX + xNiv + _longBas, posY, posZ);

	posX += xNiv + _longBas;

	yNiv = largD*(1 - _prctLargD);

	ptsTourInt[11] = Point3D(posX - _epaissD, posY, posZ);
	ptsTourInt[10] = Point3D(posX - _epaissD, posY + largD * _prctLargD, posZ);
	ptsTourInt[9] = Point3D(posX - _epaissD, posY + largD * _prctLargD + yNiv, 0.0);
	ptsTourInt[8] = Point3D(posX - _epaissD, posY + largD * _prctLargD + yNiv + largPoseTri/2, 0.0);

	ptsTourExt[9] = Point3D(posX, posY + largD * _prctLargD, posZ);
	ptsTourExt[10] = Point3D(posX, posY + largD * _prctLargD + yNiv, 0.0);
	ptsTourExt[11] = Point3D(posX, posY + largD * _prctLargD + yNiv + largPoseTri/2, 0.0);

	// moitié haut

	posX = 0.0;
	posY = _largeurG;

	ptsTourExt[20] = Point3D(-(cosf(_angleCoinG)*cosf(_angleCoinG)*_epaissG), posY + cosf(_angleCoinG)*sinf(_angleCoinG)*_epaissG, 0.0);
	ptsTourExt[19] = Point3D(diag*cosf(_angleCoinG+angle), posY + diag*sinf(_angleCoinG+angle), 0.0);

	ptsTourInt[2] = Point3D(cosf(_angleCoinG)*_longCoinG, posY + sinf(_angleCoinG)*_longCoinG, 0.0);

	posX = cosf(_angleCoinG)*_longCoinG;
	posY = _largeurG + sinf(_angleCoinG)*_longCoinG;

	ptsTourExt[18] = Point3D(posX, posY + _epaissG, 0.0);
	ptsTourExt[17] = Point3D(posX + _longHaut, posY + _epaissG, 0.0);

	ptsTourInt[3] = Point3D(posX + _longHaut, posY, 0.0);

	posX += _longHaut;
	posZ = -cosf(_angleNiveau)*_longNiveau;
	xNiv = sinf(_angleNiveau)*_longNiveau;

	ptsTourExt[16] = Point3D(posX + xNiv, posY + _epaissG, posZ);
	ptsTourExt[15] = Point3D(posX + xNiv + _longBas, posY + _epaissD, posZ);
	ptsTourExt[14] = Point3D(posX + xNiv + _longBas, posY, posZ);

	ptsTourInt[4] = Point3D(posX + xNiv, posY, posZ);

	posX += xNiv + _longBas;

	ptsTourExt[13] = Point3D(posX, posY - largD * _prctLargD, posZ);
	ptsTourExt[12] = Point3D(posX, posY - largD * _prctLargD - yNiv, 0.0);

	ptsTourInt[5] = Point3D(posX - _epaissD, posY, posZ);
	ptsTourInt[6] = Point3D(posX - _epaissD, posY - largD * _prctLargD, posZ);
	ptsTourInt[7] = Point3D(posX - _epaissD, posY - largD * _prctLargD - yNiv, 0.0);

	for(int i = 0; i < 9; i++)
		ptsTourExtS[i] = Point3D(ptsTourExt[i]._x, ptsTourExt[i]._y, - _hauteur);

	for(int i = 14; i < 21; i++)
		ptsTourExtS[i-5] = Point3D(ptsTourExt[i]._x, ptsTourExt[i]._y, - _hauteur);

	for(int i = 0; i < 6; i++)
		ptsTourIntS[i] = Point3D(ptsTourInt[i]._x, ptsTourInt[i]._y, - _hauteur);

	for(int i = 11; i < 15; i++)
		ptsTourIntS[i-5] = Point3D(ptsTourInt[i]._x, ptsTourInt[i]._y, - _hauteur);

	//Construction de la pièce

	Material mat = Material();
	mat.ToChrome();
	mat.Enable();

	// faces du dessus, moitié du bas, gauche jusqu'aux extremités

	glBegin(GL_TRIANGLE_FAN);
		for(int i = 0; i < 2; i++)
			glVertex3f(ptsTourInt[i]._x, ptsTourInt[i]._y, ptsTourInt[i]._z);

		for(int i=0; i < 4; i++)
			glVertex3f(ptsTourExt[i]._x, ptsTourExt[i]._y, ptsTourExt[i]._z);

		glVertex3f(ptsTourInt[14]._x, ptsTourInt[14]._y, ptsTourInt[14]._z);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(ptsTourInt[14]._x, ptsTourInt[14]._y, ptsTourInt[14]._z);

		for(int i=3; i<6; i++)
			glVertex3f(ptsTourExt[i]._x, ptsTourExt[i]._y, ptsTourExt[i]._z);

		glVertex3f(ptsTourInt[13]._x, ptsTourInt[13]._y, ptsTourInt[13]._z);
	glEnd();

	glBegin(GL_QUAD_STRIP);
		for(int i=5; i<7; i++)
		{
			glVertex3f(ptsTourInt[18-i]._x, ptsTourInt[18-i]._y, ptsTourInt[18-i]._z);
			glVertex3f(ptsTourExt[i]._x, ptsTourExt[i]._y, ptsTourExt[i]._z);
		}

		for(int i=8; i > 6; i--)
			glVertex3f(ptsTourExt[i]._x, ptsTourExt[i]._y, ptsTourExt[i]._z);
	glEnd();

	// faces de droite entre les 2 extremités

	glBegin(GL_QUAD_STRIP);
		for(int i=8; i<15; i++)
		{
			glVertex3f(ptsTourInt[19-i]._x, ptsTourInt[19-i]._y, ptsTourInt[19-i]._z);
			glVertex3f(ptsTourExt[i]._x, ptsTourExt[i]._y, ptsTourExt[i]._z);
		}
	glEnd();

	// moitié du haut, gauche jusqu'aux extremités

	glBegin(GL_TRIANGLE_FAN);
		for(int i = 1; i < 3; i++)
			glVertex3f(ptsTourInt[i]._x, ptsTourInt[i]._y, ptsTourInt[i]._z);

		for(int i = 19; i < 21; i++)
			glVertex3f(ptsTourExt[i]._x, ptsTourExt[i]._y, ptsTourExt[i]._z);

		glVertex3f(ptsTourExt[0]._x, ptsTourExt[0]._y, ptsTourExt[0]._z);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		for(int i = 2; i < 4; i++)
			glVertex3f(ptsTourInt[i]._x, ptsTourInt[i]._y, ptsTourInt[i]._z);

		for(int i = 17; i < 20; i++)
			glVertex3f(ptsTourExt[i]._x, ptsTourExt[i]._y, ptsTourExt[i]._z);
	glEnd();
	
	glBegin(GL_QUAD_STRIP);
		for(int i=17; i>15; i--)
		{
			glVertex3f(ptsTourExt[i]._x, ptsTourExt[i]._y, ptsTourExt[i]._z);
			glVertex3f(ptsTourInt[20-i]._x, ptsTourInt[20-i]._y, ptsTourInt[20-i]._z);
		}

		for(int i=15; i > 13; i--)
			glVertex3f(ptsTourExt[i]._x, ptsTourExt[i]._y, ptsTourExt[i]._z);
	glEnd();

	// faces du dessous
	// moitié bas, de gauche jusqu'aux extrémités

	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(ptsTourIntS[0]._x, ptsTourIntS[0]._y, ptsTourIntS[0]._z);
		glVertex3f(ptsTourIntS[9]._x, ptsTourIntS[9]._y, ptsTourIntS[9]._z);

		for(int i=3; i > -1; i--)
			glVertex3f(ptsTourExtS[i]._x, ptsTourExtS[i]._y, ptsTourExtS[i]._z);

		for(int i = 1; i > 0; i--)
			glVertex3f(ptsTourIntS[i]._x, ptsTourIntS[i]._y, ptsTourIntS[i]._z);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		for(int i = 9; i > 7; i--)
			glVertex3f(ptsTourIntS[i]._x, ptsTourIntS[i]._y, ptsTourIntS[i]._z);

		for(int i=5; i > 2; i--)
			glVertex3f(ptsTourExtS[i]._x, ptsTourExtS[i]._y, ptsTourExtS[i]._z);
	glEnd();

	glBegin(GL_QUAD_STRIP);
		for(int i=5; i<7; i++)
		{
			glVertex3f(ptsTourExtS[i]._x, ptsTourExtS[i]._y, ptsTourExtS[i]._z);
			glVertex3f(ptsTourIntS[13-i]._x, ptsTourIntS[13-i]._y, ptsTourIntS[13-i]._z);
		}

		for(int i = 7; i < 9; i++)
			glVertex3f(ptsTourExtS[i]._x, ptsTourExtS[i]._y, ptsTourExtS[i]._z);
	glEnd();

	// entre les extrémités de droite

	glBegin(GL_QUADS);
		for(int i = 6; i > 4; i--)
			glVertex3f(ptsTourIntS[i]._x, ptsTourIntS[i]._y, ptsTourIntS[i]._z);

		for(int i = 9; i > 7; i--)
			glVertex3f(ptsTourExtS[i]._x, ptsTourExtS[i]._y, ptsTourExtS[i]._z);
	glEnd();

	// moitié haut, de gauche jusqu'aux extrémités

	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(ptsTourIntS[1]._x, ptsTourIntS[1]._y, ptsTourIntS[1]._z);

		glVertex3f(ptsTourExtS[0]._x, ptsTourExtS[0]._y, ptsTourExtS[0]._z);

		for(int i = 15; i > 13; i--)
			glVertex3f(ptsTourExtS[i]._x, ptsTourExtS[i]._y, ptsTourExtS[i]._z);

		glVertex3f(ptsTourIntS[2]._x, ptsTourIntS[2]._y, ptsTourIntS[2]._z);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(ptsTourIntS[2]._x, ptsTourIntS[2]._y, ptsTourIntS[2]._z);

		for(int i = 14; i > 11; i--)
			glVertex3f(ptsTourExtS[i]._x, ptsTourExtS[i]._y, ptsTourExtS[i]._z);

		glVertex3f(ptsTourIntS[3]._x, ptsTourIntS[3]._y, ptsTourIntS[3]._z);
	glEnd();
	
	glBegin(GL_QUAD_STRIP);
		for(int i = 12; i > 10; i--)
		{
			glVertex3f(ptsTourIntS[15-i]._x, ptsTourIntS[15-i]._y, ptsTourIntS[15-i]._z);
			glVertex3f(ptsTourExtS[i]._x, ptsTourExtS[i]._y, ptsTourExtS[i]._z);
		}

		for(int i = 9; i < 11; i++)
			glVertex3f(ptsTourExtS[i]._x, ptsTourExtS[i]._y, ptsTourExtS[i]._z);
	glEnd();

	// faces sur le coté, à l'extérieur
	
	glBegin(GL_QUAD_STRIP);
		for(int i = 0; i < 9; i++)
		{
			glVertex3f(ptsTourExt[i]._x, ptsTourExt[i]._y, ptsTourExt[i]._z);
			glVertex3f(ptsTourExtS[i]._x, ptsTourExtS[i]._y, ptsTourExtS[i]._z);
		}

		for(int i = 14; i < 21; i++)
		{
			glVertex3f(ptsTourExt[i]._x, ptsTourExt[i]._y, ptsTourExt[i]._z);
			glVertex3f(ptsTourExtS[i-5]._x, ptsTourExtS[i-5]._y, ptsTourExtS[i-5]._z);
		}

		glVertex3f(ptsTourExt[0]._x, ptsTourExt[0]._y, ptsTourExt[0]._z);
		glVertex3f(ptsTourExtS[0]._x, ptsTourExtS[0]._y, ptsTourExtS[0]._z);
	glEnd();

	// faces sur le coté, à l'intérieur
	
	glBegin(GL_QUAD_STRIP);
		for(int i = 0; i < 6; i++)
		{
			glVertex3f(ptsTourInt[i]._x, ptsTourInt[i]._y, ptsTourInt[i]._z);
			glVertex3f(ptsTourIntS[i]._x, ptsTourIntS[i]._y, ptsTourIntS[i]._z);
		}

		for(int i = 11; i < 15; i++)
		{
			glVertex3f(ptsTourInt[i]._x, ptsTourInt[i]._y, ptsTourInt[i]._z);
			glVertex3f(ptsTourIntS[i-5]._x, ptsTourIntS[i-5]._y, ptsTourIntS[i-5]._z);
		}

		glVertex3f(ptsTourInt[0]._x, ptsTourInt[0]._y, ptsTourInt[0]._z);
		glVertex3f(ptsTourIntS[0]._x, ptsTourIntS[0]._y, ptsTourIntS[0]._z);
	glEnd();

	// faces des 2 cotés au changement de niveau à droite
	
	glBegin(GL_QUADS);
		for(int i = 10; i > 5; i--)
		{
			if(i == 8)
				continue;

			glVertex3f(ptsTourInt[i]._x, ptsTourInt[i]._y, ptsTourInt[i]._z);
		}
	glEnd();
	
	glBegin(GL_QUADS);
		for(int i = 13; i >8; i--)
		{
			if(i == 11)
				continue;

			glVertex3f(ptsTourExt[i]._x, ptsTourExt[i]._y, ptsTourExt[i]._z);
		}
	glEnd();
}
