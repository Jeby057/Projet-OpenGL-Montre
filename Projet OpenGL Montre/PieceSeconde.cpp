#include "PieceSeconde.h"

PieceSeconde::PieceSeconde(float rayon, float epaisseur):_rayon(rayon), _epaisseur(epaisseur)
{
}


PieceSeconde::~PieceSeconde(void)
{

}

//construire la piece
void PieceSeconde::BuildAndDisplay()
{

    GLfloat cosine, sine;

	glPushMatrix();
		glRotatef(-90,1.0,0.0,0.0);
		
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

		glBegin(GL_TRIANGLE_STRIP);
		for(int i=0;i<=100;i++){
			cosine=cos(i*2*PI/100.0)*this->_rayon;
			sine=sin(i*2*PI/100.0)*this->_rayon;

			glVertex3f(cosine,sine,this->_epaisseur);
			glVertex3f(cosine,sine,-this->_epaisseur);
		}
		glEnd();
		glPopMatrix();

		mat.ToWhiteReflect();
		mat.Enable();

		glPushMatrix();
			glTranslated(0, 0, this->_epaisseur/0.9);
			gluDisk(gluNewQuadric(),0,this->_rayon/4,100,100);
		glPopMatrix();
	glPopMatrix();

	//les tiges
	glPushMatrix(); 
	this->Cube();
	for(int i = 0; i < 12; i++)
	{
		glRotatef(30,0.0,1.0,0.0);
		this->Cube();
	}
	glPopMatrix();
}

//dessiner un cube
void PieceSeconde::Cube()
{	
	
	float t = this->_rayon/10;
	float decalageX = this->_rayon-t;
	float decalageY = this->_epaisseur*0.8;
	
	float x, y, z;
	x = t;
	y = this->_epaisseur/2;
	z = this->_epaisseur*1.3;

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

		//derière
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
}
