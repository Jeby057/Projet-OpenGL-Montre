#include "PieceCentreMontre.h"

//constructeur de la classe, il initialise les variable membre avec les parametre recu
PieceCentreMontre::PieceCentreMontre(float taille, float hauteur):_taille(taille), _hauteur(hauteur)
{
}

//destructeur de la classe
PieceCentreMontre::~PieceCentreMontre(void)
{
}

//méthode contstruction et affichage de la piece
void PieceCentreMontre::BuildAndDisplay()
{
	//dessiner les trois face
	for(int i = 0; i <3; i++)
	{
		this->PiecePartielle();
		glRotatef(120,0.0,0.0,1.0);
	}
}

//méthode qui dessine la pice spéciale
void PieceCentreMontre::PiecePartielle()
{
	//Couleur de la piece
	Material mat = Material();
	mat.ToChrome();
	mat.Enable();

	float x, y, z;
	float decalageY = 20*this->_taille/100;
	float decalageZ = this->_hauteur;
	x = this->_taille;
	y = this->_taille;
	z = 5*this->_taille/100;

	glPushMatrix();
		//***************************Piece en haut****************************************************
	
		//face de devant
		glBegin(GL_QUADS);
			glVertex3f(-20*x/100, y/2 +decalageY, z + decalageZ);
			glVertex3f(20*x/100, y/2 +decalageY, z + decalageZ);
			glVertex3f(25*x/100, 20*y/100 +decalageY, z + decalageZ);
			glVertex3f(-25*x/100, 20*y/100 +decalageY, z + decalageZ);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(-25*x/100, 20*y/100 +decalageY, z + decalageZ);
			glVertex3f(25*x/100, 20*y/100 +decalageY, z + decalageZ);
			glVertex3f(35*x/100, 0 +decalageY, z + decalageZ);
			glVertex3f(-35*x/100, 0 +decalageY, z + decalageZ);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(-35*x/100, 0 +decalageY, z + decalageZ);
			glVertex3f(35*x/100, 0 +decalageY, z + decalageZ);
			glVertex3f(0, 0, z + decalageZ);
			glVertex3f(0, 0, z + decalageZ);
		glEnd();

		//face de deriere
		glBegin(GL_QUADS);
			glVertex3f(-20*x/100, 1.15*y/2 +decalageY, -z + decalageZ);
			glVertex3f(x*20*x/100, 1.15*y/2 +decalageY, -z + decalageZ);
			glVertex3f(x*25*x/100, 20*y/100 +decalageY, -z + decalageZ);
			glVertex3f(-x*25*x/100, 20*y/100 +decalageY, -z + decalageZ);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(-25*x/100, 20*y/100 +decalageY, -z + decalageZ);
			glVertex3f(25*x/100, 20*y/100 +decalageY, -z + decalageZ);
			glVertex3f(35*x/100, 0 +decalageY, -z + decalageZ);
			glVertex3f(-35*x/100, 0 +decalageY, -z + decalageZ);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(-35*x/100, 0 +decalageY, -z + decalageZ);
			glVertex3f(35*x/100, 0 +decalageY, -z + decalageZ);
			glVertex3f(0, 0, -z + decalageZ);
			glVertex3f(0, 0, -z + decalageZ);
		glEnd();

		//les cotés
		glBegin(GL_QUADS);
			glVertex3f(-20*x/100, y/2 +decalageY, z + decalageZ);
			glVertex3f(20*x/100, y/2 +decalageY, z + decalageZ);
			glVertex3f(20*x/100, 1.15*y/2 +decalageY, -z + decalageZ);
			glVertex3f(-20*x/100, 1.15*y/2 +decalageY, -z + decalageZ);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(20*x/100, y/2 +decalageY, z + decalageZ);
			glVertex3f(20*x/100, 1.15*y/2 +decalageY, -z + decalageZ);
			glVertex3f(25*x/100, 20*y/100 +decalageY, -z + decalageZ);
			glVertex3f(25*x/100, 20*y/100 +decalageY, z + decalageZ);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(-20*x/100, y/2 +decalageY, z + decalageZ);
			glVertex3f(-20*x/100, 1.15*y/2 +decalageY, -z + decalageZ);
			glVertex3f(-25*x/100, 20*y/100 +decalageY, -z + decalageZ);
			glVertex3f(-25*x/100, 20*y/100 +decalageY, z + decalageZ);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(25*x/100, 20*y/100 +decalageY, z + decalageZ);
			glVertex3f(25*x/100, 20*y/100 +decalageY, -z + decalageZ);
			glVertex3f(35*x/100, 0 +decalageY, -z + decalageZ);
			glVertex3f(35*x/100, 0 +decalageY, z + decalageZ);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(-25*x/100, 20*y/100 +decalageY, z + decalageZ);
			glVertex3f(-25*x/100, 20*y/100 +decalageY, -z + decalageZ);
			glVertex3f(-35*x/100, 0 +decalageY, -z + decalageZ);
			glVertex3f(-35*x/100, 0 +decalageY, z + decalageZ);
		glEnd();
		
		//*************************** fin Piece en haut************************************************
		
		//***************************Piece Laterale****************************************************
		glBegin(GL_QUADS);
			glVertex3f(-20*x/100, 0.7*y/2 +decalageY, decalageZ);
			glVertex3f(20*x/100, 0.7*y/2 +decalageY, decalageZ);
			glVertex3f(20*x/100, 0.7*y/2 +decalageY, -decalageZ);
			glVertex3f(-20*x/100, 0.7*y/2 +decalageY, -decalageZ);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(-20*x/100, 0.6*y/2 +decalageY, decalageZ);
			glVertex3f(20*x/100, 0.6*y/2 +decalageY, decalageZ);
			glVertex3f(20*x/100, 0.6*y/2 +decalageY, -1.1*decalageZ);
			glVertex3f(-20*x/100, 0.6*y/2 +decalageY, -1.1*decalageZ);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(-20*x/100, 0.7*y/2 +decalageY, decalageZ);
			glVertex3f(20*x/100, 0.7*y/2 +decalageY, decalageZ);
			glVertex3f(20*x/100, 0.6*y/2 +decalageY, decalageZ);
			glVertex3f(-20*x/100, 0.6*y/2 +decalageY, decalageZ);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(20*x/100, 0.7*y/2 +decalageY, decalageZ);
			glVertex3f(20*x/100, 0.6*y/2 +decalageY, decalageZ);
			glVertex3f(20*x/100, 0.6*y/2 +decalageY, -1.1*decalageZ);
			glVertex3f(20*x/100, 0.7*y/2 +decalageY, -decalageZ);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(-20*x/100, 0.7*y/2 +decalageY, decalageZ);
			glVertex3f(-20*x/100, 0.6*y/2 +decalageY, decalageZ);
			glVertex3f(-20*x/100, 0.6*y/2 +decalageY, -1.1*decalageZ);
			glVertex3f(-20*x/100, 0.7*y/2 +decalageY, -decalageZ);
		glEnd();
		//***************************fine Piece laterale****************************************************
		
		//***************************Piece de bas****************************************************
		//face de devant
		glBegin(GL_QUADS);
			glVertex3f(-20*x/100, 0.6*y/2 +decalageY, -decalageZ-z/2);
			glVertex3f(20*x/100, 0.6*y/2 +decalageY, -decalageZ-z/2);
			glVertex3f(20*x/100, 1.1*y/2 +decalageY, -decalageZ-z/2);
			glVertex3f(-20*x/100, 1.1*y/2 +decalageY, -decalageZ-z/2);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(-20*x/100, 0.6*y/2 +decalageY, -decalageZ+z);
			glVertex3f(20*x/100, 0.6*y/2 +decalageY, -decalageZ+z);
			glVertex3f(20*x/100, y/2 +decalageY, -decalageZ+z/2);
			glVertex3f(-20*x/100, y/2 +decalageY, -decalageZ+z/2);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(-20*x/100, 1.1*y/2 +decalageY, -decalageZ-z/2);
			glVertex3f(20*x/100, 1.1*y/2 +decalageY, -decalageZ-z/2);
			glVertex3f(20*x/100, y/2 +decalageY, -decalageZ+z/2);
			glVertex3f(-20*x/100, y/2 +decalageY, -decalageZ+z/2);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(20*x/100, 0.6*y/2 +decalageY, -decalageZ-z/2);
			glVertex3f(20*x/100, 1.1*y/2 +decalageY, -decalageZ-z/2);
			glVertex3f(20*x/100, y/2 +decalageY, -decalageZ+z/2);
			glVertex3f(20*x/100, 0.6*y/2 +decalageY, -decalageZ+z);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(-20*x/100, 0.6*y/2 +decalageY, -decalageZ-z/2);
			glVertex3f(-20*x/100, 1.1*y/2 +decalageY, -decalageZ-z/2);
			glVertex3f(-20*x/100, y/2 +decalageY, -decalageZ+z/2);
			glVertex3f(-20*x/100, 0.6*y/2 +decalageY, -decalageZ+z);
		glEnd();
		//***************************fin Piece de bas****************************************************
	glPopMatrix();
	mat.Disable();
}
