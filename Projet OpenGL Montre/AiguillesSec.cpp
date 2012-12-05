#include "AiguillesSec.h"

AiguillesSec::AiguillesSec(float longueur, float rayon, float epaiss) : _longueur(longueur), _rayon(rayon), _epaiss(epaiss)
{
}

AiguillesSec::~AiguillesSec()
{
	delete _aiguilleG;
	delete _aiguilleD;
}

void AiguillesSec::BuildAndDisplay()
{
	Material mat = Material();
	mat.ToBlackReflect();
	mat.Enable();

	// Param�tres pour cr�er un quadrique
	GLUquadric * params = gluNewQuadric();

	// Construction de la pi�ce ronde centrale reliant les 3 aiguilles
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		gluCylinder(params, _rayon, _rayon, _epaiss, 100, 1);
		glTranslatef(0.0, 0.0, _epaiss);
		gluDisk(params, _rayon/6, _rayon, 100, 1);
		glTranslatef(0.0, 0.0, -_epaiss);
		glRotatef(180.0, 1.0, 0.0, 0.0);
		gluDisk(params, _rayon/6, _rayon, 100, 1);
	glPopMatrix();

	// longueur du sommet du trap�ze
	float largAig = _rayon/3;

	// tableau des points d�crivant le trap�ze de gauche
	_aiguilleG = new Point3D[4];

	// tableau des points d�crivant le trap�ze de droite
	_aiguilleD = new Point3D[4];

	// position du trap�ze en bas, c'est-�-dire � partir du cylindre central
	// _rayon/10 ajout� pour inclure un peu les trap�zes � l'int�rieur du cylindre
	float posAig = -_rayon + _rayon/10;

	// 1.5*largAig pour la longueur du bas du trap�ze (plus grand, sinon on obtiendrait un rectangle)
	// largAig/4 pour �carter le trap�ze par rapport au centre, cr�ant ainsi le trou entre les deux trap�zes
	_aiguilleG[0] = Point3D(-1.5*largAig, 0, posAig);
	_aiguilleG[1] = Point3D(-largAig/4, 0, posAig);
	_aiguilleG[2] = Point3D(-largAig/4, 0, posAig - _longueur);
	_aiguilleG[3] = Point3D(-largAig, 0, posAig - _longueur);

	_aiguilleD[0] = Point3D(largAig/4, 0, posAig);
	_aiguilleD[1] = Point3D(1.5*largAig, 0, posAig);
	_aiguilleD[2] = Point3D(largAig, 0, posAig - _longueur);
	_aiguilleD[3] = Point3D(largAig/4, 0, posAig - _longueur);

	// On contruit la premi�re aiguille, la plus grande (celle qui indiquera effectivement les secondes)
	// on va diviser _longueur par 20 pour obtenir la hauteur de la pyramide � mettre au sommet des deux trap�zes
	ConstrAig(_aiguilleG);
	ConstrAig(_aiguilleD);

	// On construit la pyramide � poser au sommet des trap�zes
	ConstrPyram(20);

	// Facteur de diminution pour les deux autres aiguilles car elles sont plus petites que celle qui indique les secondes
	float diminuAig = 0.35;

	_aiguilleG[2]._z += _longueur * diminuAig;
	_aiguilleG[3]._z += _longueur * diminuAig;

	_aiguilleD[2]._z += _longueur * diminuAig;
	_aiguilleD[3]._z += _longueur * diminuAig;
	
	// On effectue une rotation de 120 degr�s pour cr�er l'aiguille suivante, deux fois (3*120� = 360�)
	glPushMatrix();
		glRotatef(120, 0, 1, 0);
		ConstrAig(_aiguilleG);
		ConstrAig(_aiguilleD);
		ConstrPyram(20);
		
		glRotatef(120, 0, 1, 0);
		ConstrAig(_aiguilleG);
		ConstrAig(_aiguilleD);
		ConstrPyram(20);
	glPopMatrix();
}

void AiguillesSec::ConstrAig(Point3D * aiguille)
{
	// Face du dessus du trap�ze
	glBegin(GL_QUADS);
		for(int i = 0; i < 4; i++)
			glVertex3f(aiguille[i]._x, aiguille[i]._y, aiguille[i]._z);
	glEnd();
	
	// Face du dessous
	glBegin(GL_QUADS);
		for(int i = 3; i > -1; i--)
			glVertex3f(aiguille[i]._x, aiguille[i]._y - _epaiss, aiguille[i]._z);
	glEnd();

	// Faces qui font le tour (cr�e "l'�paisseur")
	glBegin(GL_QUAD_STRIP);
		for(int i = 1; i < 4; i++)
		{
			glVertex3f(aiguille[i]._x, aiguille[i]._y, aiguille[i]._z);
			glVertex3f(aiguille[i]._x, aiguille[i]._y -_epaiss, aiguille[i]._z);
		}
		glVertex3f(aiguille[0]._x, aiguille[0]._y, aiguille[0]._z);
		glVertex3f(aiguille[0]._x, aiguille[0]._y - _epaiss, aiguille[0]._z);
	glEnd();
}

void AiguillesSec::ConstrPyram(float longPic)
{
	// Faces de la pyramide
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0, -_epaiss / 2, _aiguilleG[3]._z - _longueur / longPic);
		glVertex3f(_aiguilleG[3]._x, _aiguilleG[3]._y, _aiguilleG[3]._z);
		glVertex3f(_aiguilleD[2]._x, _aiguilleD[2]._y, _aiguilleD[2]._z);
		glVertex3f(_aiguilleD[2]._x, _aiguilleD[2]._y - _epaiss, _aiguilleD[2]._z);
		glVertex3f(_aiguilleG[3]._x, _aiguilleG[3]._y - _epaiss, _aiguilleG[3]._z);
		glVertex3f(_aiguilleG[3]._x, _aiguilleG[3]._y, _aiguilleG[3]._z);
	glEnd();
}
