#include "PieceSeconde.h"

//constructeur de la classe, il initialise les variables membres avec les paramètres reçus
PieceSeconde::PieceSeconde(float rayon, float epaisseur):_rayon(rayon), _epaisseur(epaisseur)
{
}

//destructeur de la classe
PieceSeconde::~PieceSeconde(void)
{
}

//méthode construction et affichage du cylindre seconde ainsi que des 12 tiges
void PieceSeconde::BuildAndDisplay()
{
	//le cylindre*****************************************************
	glPushMatrix();
		glRotatef(-90,1.0,0.0,0.0);
		//la couleur
		Material mat = Material();
		mat.ToGreyReflect();
		mat.Enable();

		glPushMatrix();
			glTranslated(0, 0, this->_epaisseur);
			gluDisk(gluNewQuadric(),0,this->_rayon,100,100);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0, 0, -this->_epaisseur);
			gluDisk(gluNewQuadric(),0,this->_rayon,100,100);
		glPopMatrix();

		glPushMatrix();
			GLfloat cosine, sine;
			glBegin(GL_TRIANGLE_STRIP);
			for(int i=0;i<=100;i++){
				cosine=cos(i*2*PI/100.0)*this->_rayon;
				sine=sin(i*2*PI/100.0)*this->_rayon;

				glVertex3f(cosine,sine,this->_epaisseur);
				glVertex3f(cosine,sine,-this->_epaisseur);
			}
			glEnd();
			glPopMatrix();
		mat.Disable();

		//disque blanc au centre
		Material mat1 = Material();
		mat1.ToWhiteReflect();
		mat1.Enable();
		glPushMatrix();
			glTranslated(0, 0, this->_epaisseur/0.9);
			gluDisk(gluNewQuadric(),0,this->_rayon/4,100,100);
		glPopMatrix();
		mat1.Disable();
	glPopMatrix();
	//*****************************************************************

	//les 12 tiges*****************************************************
	glPushMatrix(); 
	this->Tige();
	for(int i = 0; i < 12; i++)
	{
		glRotatef(30,0.0,1.0,0.0);
		this->Tige();
	}
	glPopMatrix();
	//*****************************************************************
}

//Methode qui dessine la tige
void PieceSeconde::Tige()
{	
	float t = this->_rayon/10;
	float decalageX = this->_rayon-t;
	float decalageY = this->_epaisseur*0.8;
	
	float x, y, z;
	x = t;
	y = this->_epaisseur/2;
	z = this->_epaisseur*1.3;

	//couleur de la tige
	Material mat = Material();
	mat.ToRuby();
	mat.Enable();
		//face
		glBegin(GL_QUADS);
			glVertex3f(-x + decalageX, y + decalageY, z);
			glVertex3f(-x + decalageX, -y + decalageY, z);
			glVertex3f(x + decalageX, -y + decalageY, z);
			glVertex3f(x + decalageX, y + decalageY, z);
		glEnd();

		//derrière
		glBegin(GL_QUADS);
			glVertex3f(-x + decalageX, y + decalageY, -z);
			glVertex3f(-x + decalageX, -y + decalageY, -z);
			glVertex3f(x + decalageX, -y + decalageY, -z);
			glVertex3f(x + decalageX, y + decalageY, -z);
		glEnd();

		//haut
		glBegin(GL_QUADS);
			glVertex3f(-x + decalageX, y + decalageY, z);
			glVertex3f(x + decalageX, y + decalageY, z);
			glVertex3f(x + decalageX, y + decalageY, -z);
			glVertex3f(-x + decalageX, y + decalageY, -z);
		glEnd();

		//bas
		glBegin(GL_QUADS);
			glVertex3f(-x + decalageX, -y + decalageY, z);
			glVertex3f(x + decalageX, -y + decalageY, z);
			glVertex3f(x + decalageX, -y + decalageY, -z);
			glVertex3f(-x + decalageX, -y + decalageY, -z);
		glEnd();

		//droite
		glBegin(GL_QUADS);
			glVertex3f(x + decalageX, -y + decalageY, z);
			glVertex3f(x + decalageX, y + decalageY, z);
			glVertex3f(x + decalageX, y + decalageY, -z);
			glVertex3f(x + decalageX, -y + decalageY, -z);
		glEnd();

		//gauche
		glBegin(GL_QUADS);
			glVertex3f(-x + decalageX, -y + decalageY, z);
			glVertex3f(-x + decalageX, y + decalageY, z);
			glVertex3f(-x + decalageX, y + decalageY, -z);
			glVertex3f(-x + decalageX, -y + decalageY, -z);
		glEnd();
	mat.Disable();
}
