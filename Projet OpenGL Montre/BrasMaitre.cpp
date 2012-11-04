#include "BrasMaitre.h"


BrasMaitre::BrasMaitre(float longueur, float largeur, float hauteur, float diametre):
	_longueur(longueur),
	_largeur(largeur),
	_hauteur(hauteur),
	_diametre(diametre)
{
	_disque = new Disque(_diametre/3, _diametre, _hauteur, 50, 30);
	_disque->BuildAndSave();
}


BrasMaitre::~BrasMaitre(void)
{
	delete _disque;
}

void BrasMaitre::BuildAndDisplay(){
	float h = _hauteur/4*3;
	float hMin = _hauteur/6;
	glBegin(GL_QUADS);

		// Gauche
		glVertex3d(-_largeur/2,h,0);
		glVertex3d(-_largeur/2,h,_longueur);
		glVertex3d(-_largeur/2,hMin,_longueur);
		glVertex3d(-_largeur/2,hMin,0);

		// Droit
		glVertex3d(_largeur/2,hMin,0);
		glVertex3d(_largeur/2,hMin,_longueur);
		glVertex3d(_largeur/2,h,_longueur);
		glVertex3d(_largeur/2,h,0);

		// Haut
		glVertex3d(_largeur/2,h,0);
		glVertex3d(_largeur/2,h,_longueur);
		glVertex3d(-_largeur/2,h,_longueur);
		glVertex3d(-_largeur/2,h,0);
		
		// Bas
		glVertex3d(_largeur/2,hMin,0);
		glVertex3d(-_largeur/2,hMin,0);
		glVertex3d(-_largeur/2,hMin,_longueur);
		glVertex3d(_largeur/2,hMin,_longueur);
		
    glEnd();
	
	glPushMatrix();
		glTranslatef(0.0, 0.0, _longueur);
		glRotatef(-90, 1.0, 0.0, 0.0);
		_disque->FastDisplay();
	glPopMatrix();
}