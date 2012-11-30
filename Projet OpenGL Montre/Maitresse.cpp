#include "Maitresse.h"


Maitresse::Maitresse(float hBras, float hMargeBrasEspace, float hEspace, float hBase, float epaisseur, float longueurBras, float diametreRotBras)
	:_hBras(hBras),
	_hMargeBrasEspace(hMargeBrasEspace),
	_hEspace(hEspace),
	_hBase(hBase),
	_epaisseur(epaisseur),
	_longueurBras(longueurBras),
	_diametreRotBras(diametreRotBras)
{
	float lBrasExt = 2 * (_hBras + _hMargeBrasEspace) / sqrtf(3);
	_brasMaitre = new BrasMaitre(_longueurBras, lBrasExt, _epaisseur, _diametreRotBras);
	_brasMaitre->BuildAndSave();
}


Maitresse::~Maitresse(void)
{
	delete _brasMaitre;
}

void Maitresse::BuildAndDisplay()
{
	Material mat = Material();
	mat.ToSilver();
	mat.Enable();
	 
	// Hauteur du triangle
	float hauteur = cos(DEGREES_TO_RADIANS(60)) * (_hBras + _hMargeBrasEspace + _hEspace + _hBase);

	// Rayon circonscrit
	float rCirc = _hMargeBrasEspace + _hEspace + _hBase;

	// Calcul de la longueur du bras
	float lBrasInt = 2 * (_hBras + _hMargeBrasEspace + _hEspace) / sqrtf(3);
	float lBrasExt = 2 * (_hBras + _hMargeBrasEspace) / sqrtf(3);

	// Calcul du pattern de la base
	Point3D ptsBase[12];
	ptsBase[0] = Point3D(-lBrasInt / 2, 0.0, _hBase);
	ptsBase[1] = Point3D(-lBrasInt / 4, 0.0, _hBase);
	ptsBase[2] = Point3D(lBrasInt / 4, 0.0, _hBase);
	ptsBase[3] = Point3D(lBrasInt / 2, 0.0, _hBase);

	// Calcul du pattern de la base extrieur
	Point3D ptsBaseExt[16];
	ptsBaseExt[0] = Point3D(-lBrasExt / 2, 0.0, _hBase + _hEspace);
	ptsBaseExt[1] = Point3D(-lBrasExt / 4, 0.0, _hBase + _hEspace);
	ptsBaseExt[2] = Point3D(lBrasExt / 4, 0.0, _hBase + _hEspace);
	ptsBaseExt[3] = Point3D(lBrasExt / 2, 0.0, _hBase + _hEspace);

	// Calcul du pattern de la base extrieur avec la marge
	Point3D ptsBaseExMarge[16];
	ptsBaseExMarge[0] = Point3D(-lBrasExt / 2, 0.0, _hBase + _hEspace + _hMargeBrasEspace);
	ptsBaseExMarge[1] = Point3D(-lBrasExt / 4, 0.0, _hBase + _hEspace + _hMargeBrasEspace);
	ptsBaseExMarge[2] = Point3D(lBrasExt / 4, 0.0, _hBase + _hEspace + _hMargeBrasEspace);
	ptsBaseExMarge[3] = Point3D(lBrasExt / 2, 0.0, _hBase + _hEspace + _hMargeBrasEspace);


	// Calcul des autres points de la bases
	float angle = DEGREES_TO_RADIANS(120);
	for(int i=4; i<12; i++){
		ptsBase[i] = Point3D(ptsBase[i-4]._x * cosf(angle) + ptsBase[i-4]._z * sinf(angle), ptsBase[i-4]._y, -ptsBase[i-4]._x * sinf(angle) + ptsBase[i-4]._z * cosf(angle));
		ptsBaseExt[i] = Point3D(ptsBaseExt[i-4]._x * cosf(angle) + ptsBaseExt[i-4]._z * sinf(angle), ptsBaseExt[i-4]._y, -ptsBaseExt[i-4]._x * sinf(angle) + ptsBaseExt[i-4]._z * cosf(angle));
		ptsBaseExMarge[i] = Point3D(ptsBaseExMarge[i-4]._x * cosf(angle) + ptsBaseExMarge[i-4]._z * sinf(angle), ptsBaseExMarge[i-4]._y, -ptsBaseExMarge[i-4]._x * sinf(angle) + ptsBaseExMarge[i-4]._z * cosf(angle));
	}
	
	// Face du dessous
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0, ptsBase[0]._y,  0.0);
		for(int i=0; i<12; i++)
		{
			glVertex3f(ptsBase[i]._x, ptsBase[i]._y, ptsBase[i]._z);
		}
		glVertex3f(ptsBase[0]._x, ptsBase[0]._y, ptsBase[0]._z);
	glEnd();

	// Face du dessus
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0, ptsBase[0]._y + _epaisseur,  0.0);
		for(int i=0; i<12; i++)
			glVertex3f(ptsBase[i]._x, ptsBase[i]._y + _epaisseur, ptsBase[i]._z);
		glVertex3f(ptsBase[0]._x, ptsBase[0]._y + _epaisseur, ptsBase[0]._z);
	glEnd();

	// Faces de coté
	glBegin(GL_TRIANGLE_STRIP);
		for(int i=0; i<12; i++)
		{
			glVertex3f(ptsBase[i]._x, ptsBase[i]._y, ptsBase[i]._z);
			glVertex3f(ptsBase[i]._x, ptsBase[i]._y + _epaisseur, ptsBase[i]._z);
		}
		glVertex3f(ptsBase[0]._x, ptsBase[0]._y, ptsBase[0]._z);
		glVertex3f(ptsBase[0]._x, ptsBase[0]._y + _epaisseur, ptsBase[0]._z);
	glEnd();
	
	// Faces de coté : Exterieur
	glBegin(GL_TRIANGLE_STRIP);
		for(int i=0; i<12; i++)
		{
			glVertex3f(ptsBaseExt[i]._x, ptsBaseExt[i]._y, ptsBaseExt[i]._z);
			glVertex3f(ptsBaseExt[i]._x, ptsBaseExt[i]._y + _epaisseur, ptsBaseExt[i]._z);
		}
		glVertex3f(ptsBaseExt[0]._x, ptsBaseExt[0]._y, ptsBaseExt[0]._z);
		glVertex3f(ptsBaseExt[0]._x, ptsBaseExt[0]._y + _epaisseur, ptsBaseExt[0]._z);
	glEnd();

	// Faces de dessus : Exterieur
	for(int i=0; i<12; i=i+2)
	{
		glBegin(GL_QUADS);
			glVertex3f(ptsBase[i]._x, ptsBase[i]._y, ptsBase[i]._z);
			glVertex3f(ptsBaseExt[i]._x, ptsBaseExt[i]._y, ptsBaseExt[i]._z);
			glVertex3f(ptsBaseExt[i+1]._x, ptsBaseExt[i+1]._y, ptsBaseExt[i+1]._z);
			glVertex3f(ptsBase[i+1]._x, ptsBase[i+1]._y, ptsBase[i+1]._z);
		glEnd();

		// Flanc gauche / Droite
		for(int j=i+1; j<i+3; j++)
		{
			glVertex3f(ptsBase[j]._x, ptsBase[j]._y, ptsBase[j]._z);
			glVertex3f(ptsBaseExt[j]._x, ptsBaseExt[j]._y, ptsBaseExt[j]._z);
			glVertex3f(ptsBaseExt[j]._x, ptsBaseExt[j]._y + _epaisseur, ptsBaseExt[j]._z);
			glVertex3f(ptsBase[j]._x, ptsBase[j]._y + _epaisseur, ptsBase[j]._z);
		}

		// Avec epaisseur
		glBegin(GL_QUADS);
			glVertex3f(ptsBase[i]._x, ptsBase[i]._y + _epaisseur, ptsBase[i]._z);
			glVertex3f(ptsBaseExt[i]._x, ptsBaseExt[i]._y + _epaisseur, ptsBaseExt[i]._z);
			glVertex3f(ptsBaseExt[i+1]._x, ptsBaseExt[i+1]._y + _epaisseur, ptsBaseExt[i+1]._z);
			glVertex3f(ptsBase[i+1]._x, ptsBase[i+1]._y + _epaisseur, ptsBase[i+1]._z);
		glEnd();
	}

	// Faces des marges : dessous
	glBegin(GL_TRIANGLE_STRIP);
		for(int i=0; i<12; i++)
		{
			glVertex3f(ptsBaseExt[i]._x, ptsBaseExt[i]._y, ptsBaseExt[i]._z);
			glVertex3f(ptsBaseExMarge[i]._x, ptsBaseExMarge[i]._y, ptsBaseExMarge[i]._z);
		}
		glVertex3f(ptsBaseExt[0]._x, ptsBaseExt[0]._y, ptsBaseExt[0]._z);
		glVertex3f(ptsBaseExMarge[0]._x, ptsBaseExMarge[0]._y, ptsBaseExMarge[0]._z);
	glEnd();

	// Face des marges : dessus
	glBegin(GL_TRIANGLE_STRIP);
		for(int i=0; i<12; i++)
		{
			glVertex3f(ptsBaseExt[i]._x, ptsBaseExt[i]._y + _epaisseur, ptsBaseExt[i]._z);
			glVertex3f(ptsBaseExMarge[i]._x, ptsBaseExMarge[i]._y + _epaisseur, ptsBaseExMarge[i]._z);
		}
		glVertex3f(ptsBaseExt[0]._x, ptsBaseExt[0]._y + _epaisseur, ptsBaseExt[0]._z);
		glVertex3f(ptsBaseExMarge[0]._x, ptsBaseExMarge[0]._y + _epaisseur, ptsBaseExMarge[0]._z);
	glEnd();

	// Face des marges : coté exterieur
	glBegin(GL_TRIANGLE_STRIP);
		for(int i=0; i<12; i++)
		{
			glVertex3f(ptsBaseExMarge[i]._x, ptsBaseExMarge[i]._y, ptsBaseExMarge[i]._z);
			glVertex3f(ptsBaseExMarge[i]._x, ptsBaseExMarge[i]._y + _epaisseur, ptsBaseExMarge[i]._z);
		}
		glVertex3f(ptsBaseExMarge[0]._x, ptsBaseExMarge[0]._y, ptsBaseExMarge[0]._z);
		glVertex3f(ptsBaseExMarge[0]._x, ptsBaseExMarge[0]._y + _epaisseur, ptsBaseExMarge[0]._z);
	glEnd();


	// Création des bras
	for(int i=0; i<3; i++)
	{
		glPushMatrix();
			glRotatef(i*120, 0.0, 1.0, 0.0);
			glTranslatef(0.0, 0.0, rCirc);
			_brasMaitre->FastDisplay();
		glPopMatrix();
	}
	mat.Disable();
}