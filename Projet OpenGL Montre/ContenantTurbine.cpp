#include "ContenantTurbine.h"
//constructeur de la classe, il initialise les variables membres avec les paramètres reçus
ContenantTurbine::ContenantTurbine(float largeur, float epaisseur) : _largeur(largeur), _epaisseur(epaisseur)
{
}

//destructeur de la classe
ContenantTurbine::~ContenantTurbine(void)
{
}

//méthode construction et affichage de ContenantTurbine
void ContenantTurbine::BuildAndDisplay()
{
	this->Glace();
	this->MontureGlace();
}

//méthode qui dessine la vitre (glace)
void ContenantTurbine::Glace()
{
	//couleur de la glace
	Material mat(0.35);
	mat.ToBlueDark();
	mat.Enable();

	//dessiner la glace
	glPushMatrix();
		glShadeModel(GL_SMOOTH);
		gluDisk(gluNewQuadric(),0,this->_largeur/2,50,50);
		glTranslated(0, 0, this->_epaisseur);
		gluDisk(gluNewQuadric(),0,this->_largeur/2,50,50);
	glPopMatrix();
	glPushMatrix();
		glShadeModel(GL_SMOOTH);
		gluCylinder(gluNewQuadric(),this->_largeur/2,this->_largeur/2,this->_epaisseur,50,50); 
	glPopMatrix();

	mat.Disable();
}

//méthode qui dessine la monture de la glace
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
			glTranslated(0, 0, this->_epaisseur*1.1);
			gluDisk(gluNewQuadric(),this->_largeur/2,this->_largeur/1.85,100,100);
		glPopMatrix();
		
		glPushMatrix();
			gluCylinder(gluNewQuadric(),this->_largeur/2,this->_largeur/2,this->_epaisseur*1.1,100,100);
			gluCylinder(gluNewQuadric(),this->_largeur/1.85,this->_largeur/1.85,this->_epaisseur*1.1,100,100); 
		glPopMatrix();
	glPopMatrix();
	mat2.Disable();
}
