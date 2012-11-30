#include "ContenantTurbine.h"

ContenantTurbine::ContenantTurbine(float largeur, float hauteur) : _largeur(largeur), _hauteur(hauteur)
{
}


ContenantTurbine::~ContenantTurbine(void)
{
}

void ContenantTurbine::BuildAndDisplay()
{
	//this->RepereMonde(1);

	this->Glace();
	this->MontureGlace();
}

void ContenantTurbine::Glace()
{

	Material mat(0.35);
	mat.ToBlueDark();
	mat.Enable();

	glPushMatrix();
		glShadeModel(GL_SMOOTH);
		gluDisk(gluNewQuadric(),0,this->_largeur/2,50,50);
		glTranslated(0, 0, this->_hauteur);
		gluDisk(gluNewQuadric(),0,this->_largeur/2,50,50);
	glPopMatrix();

	mat.Disable();

	Material mat2(1.0);
	mat2.ToGreyReflect();
	mat2.Enable();

	glPushMatrix();
		glShadeModel(GL_SMOOTH);
		gluCylinder(gluNewQuadric(),this->_largeur/2,this->_largeur/2,this->_hauteur,50,50); 
	glPopMatrix();

}

void ContenantTurbine::MontureGlace()
{
	glPushMatrix();
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Gris(1,1));

		glPushMatrix();
			glShadeModel(GL_SMOOTH);
			gluDisk(gluNewQuadric(),this->_largeur/2,this->_largeur/1.85,100,100);
			glTranslated(0, 0, this->_hauteur*1.1);
			gluDisk(gluNewQuadric(),this->_largeur/2,this->_largeur/1.85,100,100);
		glPopMatrix();
		
		glPushMatrix();
			glShadeModel(GL_SMOOTH);
			gluCylinder(gluNewQuadric(),this->_largeur/2,this->_largeur/2,this->_hauteur*1.1,100,100);
			gluCylinder(gluNewQuadric(),this->_largeur/1.85,this->_largeur/1.85,this->_hauteur*1.1,100,100); 
		glPopMatrix();
		
	glPopMatrix();
}