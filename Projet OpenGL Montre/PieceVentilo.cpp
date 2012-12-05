#include "PieceVentilo.h"

//constructeur de la classe, il initialise les variable membre avec les parametre recu
PieceVentilo::PieceVentilo(float diametreInterieur, float diametreExterieur, float hauteur):_diametreInterieur(diametreInterieur),_diametreExterieur(diametreExterieur),_hauteur(hauteur)
{
}

//destructeur de la classe
PieceVentilo::~PieceVentilo(void)
{
}

//méthode contstruction et affichage de la turbine
void PieceVentilo::BuildAndDisplay()
{
	//le ventilo
	glMaterialfv(GL_FRONT,GL_DIFFUSE,couluer->Gris(1,1));
	this->EnsembleTige();
	
	glMaterialfv(GL_FRONT,GL_DIFFUSE,couluer->Gris(1,1));
	this->CylendreCentre();
}

//methode qui dessine les 9 tiges
void PieceVentilo::EnsembleTige()
{
	glPushMatrix(); 	
	for(int i = 0; i < 9; i++)
	{
		this->UneTige();
		glRotatef(40,0.0,1.0,0.0);
	}
	glPopMatrix();
	
	glPushMatrix();
	glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		float magenta[] = { 1.0F,0.0F,1.0F,0.4F };
		glMaterialfv(GL_FRONT,GL_DIFFUSE,magenta);
		glScaled(1, this->_hauteur*1.4, 1);
		glutSolidSphere(this->_diametreInterieur,100,100);
	glDisable(GL_BLEND); 
	glPopMatrix();
}

//Methode qui dessine une seul tige
void PieceVentilo::UneTige()
{	
	float taille = _diametreExterieur;
	float x, y, z;
	x =  this->_diametreInterieur;
	y = 40*this->_hauteur/100;
	z = taille/60;
	float decalageX = this->_diametreInterieur + 10*this->_diametreExterieur/100;
	
	glPushMatrix();
		//tige 1************************************************
		glBegin(GL_QUADS);
			glVertex3f(0 + decalageX, y, z);
			glVertex3f(0 + decalageX, -y, z);
			glVertex3f(x + decalageX-15*taille/100, -y, z);
			glVertex3f(x + decalageX-15*taille/100, y, z);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(0 + decalageX, y, -z);
			glVertex3f(0 + decalageX, -y, -z);
			glVertex3f(x + decalageX, -y, -z);
			glVertex3f(x + decalageX, y, -z);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(0+ decalageX, -y, z);
			glVertex3f(0 + decalageX, -y, -z);
			glVertex3f(x + decalageX, -y, -z);
			glVertex3f(x + decalageX-15*taille/100, -y, z);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(0 + decalageX, y, z);
			glVertex3f(0 + decalageX, y, -z);
			glVertex3f(x + decalageX, y, -z);
			glVertex3f(x + decalageX-15*taille/100, y, z);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(0 + decalageX, -y, z);
			glVertex3f(0 + decalageX, y, z);
			glVertex3f(0 + decalageX, y, -z);
			glVertex3f(0 + decalageX, -y, -z);
		glEnd();
		//fin tige 1********************************************
		
		//tige 2********************************************
		glBegin(GL_QUADS);
			glVertex3f(x + decalageX, y, -z);
			glVertex3f(x + decalageX, -y, -z);
			glVertex3f(x + decalageX+20*taille/100, -y, z+30*taille/100);
			glVertex3f(x + decalageX+20*taille/100, y, z+30*taille/100);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(x + decalageX-15*taille/100, y, z);
			glVertex3f(x + decalageX-15*taille/100, -y, z);
			glVertex3f(x + decalageX+20*taille/100, -y, z+30*taille/100);
			glVertex3f(x + decalageX+20*taille/100, y, z+30*taille/100);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(x + decalageX-15*taille/100, y, z);
			glVertex3f(x + decalageX+20*taille/100, y, z+30*taille/100);
			glVertex3f(x + decalageX+20*taille/100, y, z+30*taille/100);
			glVertex3f(x + decalageX, y, -z);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(x + decalageX-15*taille/100, -y, z);
			glVertex3f(x + decalageX+20*taille/100, -y, z+30*taille/100);
			glVertex3f(x + decalageX+20*taille/100, -y, z+30*taille/100);
			glVertex3f(x + decalageX, -y, -z);
		glEnd();
		//fin tige 1********************************************
		
	glPopMatrix();
}

//Methode qui dessine un cylendre
void PieceVentilo::CylendreCentre()
{
	glPushMatrix();
		float PourcentageEpesseur = 1.2;
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couluer->Gris(1,1));
		glRotated(-90,1.0,0.0,0.0);

		glPushMatrix();
			glTranslated(0, 0, this->_hauteur/2);
			gluDisk(gluNewQuadric(),this->_diametreInterieur,this->_diametreInterieur*PourcentageEpesseur,100,100);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0, 0, -this->_hauteur/2);
			gluDisk(gluNewQuadric(),this->_diametreInterieur,this->_diametreInterieur*PourcentageEpesseur,100,100);
		glPopMatrix();

		
		glPushMatrix();
			glTranslated(0, 0, -this->_hauteur/2);
			glShadeModel(GL_SMOOTH);
			gluCylinder(gluNewQuadric(),this->_diametreInterieur,this->_diametreInterieur,this->_hauteur,100,100);
			gluCylinder(gluNewQuadric(),this->_diametreInterieur*PourcentageEpesseur,this->_diametreInterieur*PourcentageEpesseur,this->_hauteur,100,100); 
		glPopMatrix();
		
	glPopMatrix();
}
