#include "PieceChiffres.h"

PieceChiffres::PieceChiffres(float taille, int chiffre): _taille(taille), _chiffre1(chiffre)
{
	_unChiffre = true;
	_unNombre = false;
}

PieceChiffres::PieceChiffres(float taille, int chiffre1, int chiffre2): _taille(taille), _chiffre1(chiffre1), _chiffre2(chiffre2)
{
	_unChiffre = false;
	_unNombre = true;
}

PieceChiffres::~PieceChiffres(void)
{
}

void PieceChiffres::BuildAndDisplay()
{
	//repere monde
	//this->RepereMonde(1);

	//dessiner un chiffre
	glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Rouge());
	

	//glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Jaune());
	if(_unChiffre)
		this->Chiffre(_chiffre1);

	if(_unNombre)
		this->Nombre(_chiffre1, _chiffre2);

	
}

void PieceChiffres::ChiffreZero()
{
	//gauche
	glPushMatrix();
		glTranslated(0.25,0.0,0.0);
		glScaled(0.2,1.0,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//droite
	glPushMatrix();
		glTranslated(-0.25,0.0,0.0);
		glScaled(0.2,1.0,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//haut
	glPushMatrix();
		glTranslated(0.0,0.6,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//bas
	glPushMatrix();
		glTranslated(0.0,-0.6,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();
}

void PieceChiffres::ChiffreUn()
{
	//centre
	glPushMatrix();
		glTranslated(0.0,0.1,0.0);
		glScaled(0.2,1.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//le petit un
	glPushMatrix();
		//face de devant
		glBegin(GL_QUADS);
			glVertex3f(-0.1,0.7,0.05);
			glVertex3f(-0.1,0.4,0.05);
			glVertex3f(-0.4,0.1,0.05);
			glVertex3f(-0.4,0.4,0.05);
		glEnd();

		//face de deriere
		glBegin(GL_QUADS);
			glVertex3f(-0.1,0.7,-0.05);
			glVertex3f(-0.1,0.4,-0.05);
			glVertex3f(-0.4,0.1,-0.05);
			glVertex3f(-0.4,0.4,-0.05);
		glEnd();

		//face de gauche
		glBegin(GL_QUADS);
			glVertex3f(-0.1,0.5,0.05);
			glVertex3f(-0.1,0.5,-0.05);
			glVertex3f(-0.4,0.1,-0.05);
			glVertex3f(-0.4,0.1,0.05);
		glEnd();

		//face de droite
		glBegin(GL_QUADS);
			glVertex3f(-0.1,0.7,0.05);
			glVertex3f(-0.1,0.7,-0.05);
			glVertex3f(-0.4,0.4,-0.05);
			glVertex3f(-0.4,0.4,0.05);
		glEnd();

		//face de bas
		glBegin(GL_QUADS);
			glVertex3f(-0.4,0.4,0.05);
			glVertex3f(-0.4,0.4,-0.05);
			glVertex3f(-0.4,0.1,-0.05);
			glVertex3f(-0.4,0.1,0.05);
		glEnd();
	glPopMatrix();

	//piec de bas
	glPushMatrix();
		glTranslated(0.0,-0.6,0.0);
		glScaled(0.6,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();
}

void PieceChiffres::ChiffreDeux()
{
	//haut
	glPushMatrix();
		glTranslated(0.0,0.6,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//centre
	glPushMatrix();
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//bas
	glPushMatrix();
		glTranslated(0.0,-0.6,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//gauche
	glPushMatrix();
		glTranslated(0.25,0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//droite
	glPushMatrix();
		glTranslated(-0.25,-0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();
}

void PieceChiffres::ChiffreTrois()
{
	//haut
	glPushMatrix();
		glTranslated(0.0,0.6,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//centre
	glPushMatrix();
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//bas
	glPushMatrix();
		glTranslated(0.0,-0.6,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//gauche haut
	glPushMatrix();
		glTranslated(0.25,0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//guache bas
	glPushMatrix();
		glTranslated(0.25,-0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();
}

void PieceChiffres::ChiffreQuatre()
{
	//centre
	glPushMatrix();
		glTranslated(0.0,-0.1,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//laterale
	glPushMatrix();
		glTranslated(0.15,0.0,0.0);
		glScaled(0.2,1.4,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//diagonale	
	glPushMatrix();
		//face de devant
		glBegin(GL_QUADS);
			glVertex3f(-0.35,-0.0,0.05);
			glVertex3f(-0.15,-0.0,0.05);
			glVertex3f(0.05,0.4,0.05);
			glVertex3f(0.05,0.7,0.05);
		glEnd();

		//face de deriere
		glBegin(GL_QUADS);
			glVertex3f(-0.35,-0.0,-0.05);
			glVertex3f(-0.15,-0.0,-0.05);
			glVertex3f(0.05,0.4,-0.05);
			glVertex3f(0.05,0.7,-0.05);
		glEnd();

		//face de gauche
		glBegin(GL_QUADS);
			glVertex3f(-0.15,-0.0,0.05);
			glVertex3f(-0.15,-0.0,-0.05);
			glVertex3f(0.05,0.4,-0.05);
			glVertex3f(0.05,0.4,0.05);
		glEnd();

		//face de droite
		glBegin(GL_QUADS);
			glVertex3f(-0.35,-0.0,0.05);
			glVertex3f(-0.35,-0.0,-0.05);
			glVertex3f(0.05,0.7,-0.05);
			glVertex3f(0.05,0.7,0.05);
		glEnd();

	glPopMatrix();
}

void PieceChiffres::ChiffreCinq()
{
	//haut
	glPushMatrix();
		glTranslated(0.0,0.6,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//centre
	glPushMatrix();
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//bas
	glPushMatrix();
		glTranslated(0.0,-0.6,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//gauche
	glPushMatrix();
		glTranslated(-0.25,0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//droite
	glPushMatrix();
		glTranslated(0.25,-0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();
}

void PieceChiffres::ChiffreSix()
{
	//haut
	glPushMatrix();
		glTranslated(0.0,0.6,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//centre
	glPushMatrix();
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//bas
	glPushMatrix();
		glTranslated(0.0,-0.6,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//gauche
	glPushMatrix();
		glTranslated(-0.25,0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//bas droite
	glPushMatrix();
		glTranslated(-0.25,-0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//bas gauche
	glPushMatrix();
		glTranslated(0.25,-0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();
}

void PieceChiffres::ChiffreSept()
{
	//haut
	glPushMatrix();
		glTranslated(0.0,0.6,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//laterale
	//face devant
	glPushMatrix();
		glBegin(GL_QUADS);
			glVertex3f(0.15,0.5,0.05);
			glVertex3f(0.35,0.5,0.05);
			glVertex3f(-0.15,-0.7,0.05);
			glVertex3f(-0.35,-0.7,0.05);
		glEnd();
	glPopMatrix();

	
	glPushMatrix();
		//face deriere
		glBegin(GL_QUADS);
			glVertex3f(0.15,0.5,-0.05);
			glVertex3f(0.35,0.5,-0.05);
			glVertex3f(-0.15,-0.7,-0.05);
			glVertex3f(-0.35,-0.7,-0.05);
		glEnd();
	
		//face gauche
		glBegin(GL_QUADS);
			glVertex3f(0.35,0.5,0.05);
			glVertex3f(0.35,0.5,-0.05);
			glVertex3f(-0.15,-0.7,-0.05);
			glVertex3f(-0.15,-0.7,0.05);
		glEnd();

		//face droite
		glBegin(GL_QUADS);
			glVertex3f(0.15,0.5,0.05);
			glVertex3f(0.15,0.5,-0.05);
			glVertex3f(-0.35,-0.7,-0.05);
			glVertex3f(-0.35,-0.7,0.05);
		glEnd();

		//face bas
		glBegin(GL_QUADS);
			glVertex3f(-0.35,-0.7,0.05);
			glVertex3f(-0.35,-0.7,-0.05);
			glVertex3f(-0.15,-0.7,-0.05);
			glVertex3f(-0.15,-0.7,0.05);
		glEnd();
	glPopMatrix();
}

void PieceChiffres::ChiffreHuite()
{
	//haut
	glPushMatrix();
		glTranslated(0.0,0.6,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//centre
	glPushMatrix();
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//bas
	glPushMatrix();
		glTranslated(0.0,-0.6,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//haut gauche
	glPushMatrix();
		glTranslated(0.25,0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//haut droite
	glPushMatrix();
		glTranslated(-0.25,0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//bas droite
	glPushMatrix();
		glTranslated(-0.25,-0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//bas gauche
	glPushMatrix();
		glTranslated(0.25,-0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();
}

void PieceChiffres::ChiffreNeuf()
{
	//haut
	glPushMatrix();
		glTranslated(0.0,0.6,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//centre
	glPushMatrix();
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//bas
	glPushMatrix();
		glTranslated(0.0,-0.6,0.0);
		glScaled(0.7,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//haut gauche
	glPushMatrix();
		glTranslated(0.25,0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//haut droite
	glPushMatrix();
		glTranslated(-0.25,0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//bas gauche
	glPushMatrix();
		glTranslated(0.25,-0.3,0.0);
		glScaled(0.2,0.4,0.1);
		glutSolidCube(1);
	glPopMatrix();
}

//choisir un chiffre
void PieceChiffres::DrawChiffre(int chiffre)
{
	switch(chiffre){
		case 0 : this->ChiffreZero(); break;
		case 1 : this->ChiffreUn(); break;
		case 2 : this->ChiffreDeux(); break;
		case 3 : this->ChiffreTrois(); break;
		case 4 : this->ChiffreQuatre(); break;
		case 5 : this->ChiffreCinq(); break;
		case 6 : this->ChiffreSix(); break;
		case 7 : this->ChiffreSept(); break;
		case 8 : this->ChiffreHuite(); break;
		case 9 : this->ChiffreNeuf(); break;
	}
}

//dessiner un seul chiffre
void PieceChiffres::Chiffre(int chiffre)
{
	glPushMatrix();
		glScaled(this->_taille,this->_taille,this->_taille);
		this->DrawChiffre(chiffre);
	glPopMatrix();
}

//dessiner un nombre
void PieceChiffres::Nombre(int chiffre1, int chiffre2)
{
	glPushMatrix();
		glScaled(this->_taille,this->_taille,this->_taille);
		glPushMatrix();
			glTranslated(-0.425,0,0);
			this->DrawChiffre(chiffre1);
		glPopMatrix();
		glPushMatrix();
			glTranslated(0.425,0,0);
			this->DrawChiffre(chiffre2);
		glPopMatrix();
	glPopMatrix();
}
