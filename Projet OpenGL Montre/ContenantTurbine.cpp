#include "ContenantTurbine.h"
//constructeur de la classe, il initialise les variable membre avec les parametre recu
ContenantTurbine::ContenantTurbine(float largeur, float epesseur) : _largeur(largeur), _epesseur(epesseur)
{
}

//destructeur de la classe
ContenantTurbine::~ContenantTurbine(void)
{
}

//méthode contstruction et affichage de la ContenanteTurbine
void ContenantTurbine::BuildAndDisplay()
{
	this->Glace();
	this->MontureGlace();
}

//méthode qui dessiner la glace
void ContenantTurbine::Glace()
{
	//couleur de la glace
	Material mat(0.35);
	mat.ToBlueDark();
	mat.Enable();

	//dessiner la galce
	glPushMatrix();
		glShadeModel(GL_SMOOTH);
		gluDisk(gluNewQuadric(),0,this->_largeur/2,50,50);
		glTranslated(0, 0, this->_epesseur);
		gluDisk(gluNewQuadric(),0,this->_largeur/2,50,50);
	glPopMatrix();
	glPushMatrix();
		glShadeModel(GL_SMOOTH);
		gluCylinder(gluNewQuadric(),this->_largeur/2,this->_largeur/2,this->_epesseur,50,50); 
	glPopMatrix();

	mat.Disable();
}

//méthode qui dessiner la monteur de la glace
void ContenantTurbine::MontureGlace()
{
	//couleur de cache
	Material mat2(1.0);
	mat2.ToGreyReflect();
	mat2.Enable();

	//dessiner le cache
	glPushMatrix();
		glShadeModel(GL_SMOOTH);
		glPushMatrix();
			gluDisk(gluNewQuadric(),this->_largeur/2,this->_largeur/1.85,100,100);
			glTranslated(0, 0, this->_epesseur*1.1);
			gluDisk(gluNewQuadric(),this->_largeur/2,this->_largeur/1.85,100,100);
		glPopMatrix();
		
		glPushMatrix();
			gluCylinder(gluNewQuadric(),this->_largeur/2,this->_largeur/2,this->_epesseur*1.1,100,100);
			gluCylinder(gluNewQuadric(),this->_largeur/1.85,this->_largeur/1.85,this->_epesseur*1.1,100,100); 
		glPopMatrix();
	glPopMatrix();
	mat2.Disable();
}
