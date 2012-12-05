#include "TheRoom.h"


TheRoom::TheRoom(float taille): _taille(taille)
{

	GLuint texturesId[6];

	char* nameFace[6];
	 for(int i=0; i<6; i++)
		nameFace[i] = new char[35];
	 
	 sprintf(nameFace[0],"%s", "the_room/sole.ppm");
	 sprintf(nameFace[1],"%s", "the_room/plafond.ppm");
	 sprintf(nameFace[2],"%s", "the_room/mur1.ppm");
	 sprintf(nameFace[3],"%s", "the_room/mur2.ppm");
	 sprintf(nameFace[4],"%s", "the_room/mur3.ppm");
	 sprintf(nameFace[5],"%s", "the_room/mur4.ppm");
	
	//charger les texutre
	this->LoadTexture(texturesId, nameFace, 6); 
	 
	 for(int i=0; i<6; i++)
		delete nameFace[i];

	 // Copie en attribut
	 _sole = texturesId[0];
	 _plafond = texturesId[1];
	 _mur1 = texturesId[2];
	 _mur2 = texturesId[3];
	 _mur3 = texturesId[4];
	 _mur4 = texturesId[5];
}


TheRoom::~TheRoom(void)
{
}

void TheRoom::BuildAndDisplay()
{
	
	//la chambre de musée
	glEnable(GL_TEXTURE_2D);
	this->TheMuseum();
	glDisable(GL_TEXTURE_2D);
	

	//la table d'exposition
	glPushMatrix();
		glRotated(90,1.0,0.0,0.0);
		this->VitrineExposition(3.0, 2.5);
	glPopMatrix();
	

	//le lustre
	glPushMatrix();
		glTranslated(0.0, 0.0, this->_taille);
		glRotated(180,1.0,0.0,0.0);
		this->Lustre(1.0,1.0);
	glPopMatrix();


}


void TheRoom::TheMuseum()
{
	

	//dessiner la chambre
	glPushMatrix();
	glScaled(1.5*this->_taille, 1.5*this->_taille,this->_taille);
	//dessiner le sole
		glPushMatrix();
			glRotated(-90,0.0,0.0,1.0);
			glBindTexture(GL_TEXTURE_2D, this->_sole);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.0);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.5, -0.5, 0.0);
				glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.0);
			glEnd();
		glPopMatrix();
	
		//dessiner le plafond
		glPushMatrix();
			glTranslated(0.0, 0.0, 1.0);
			glRotated(90,0.0,0.0,1.0);
			glBindTexture(GL_TEXTURE_2D, this->_plafond);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.0);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.5, -0.5, 0.0);
				glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.0);
			glEnd();
		glPopMatrix();

		//dessiner le mur 1 vers x
		glPushMatrix();
			glTranslated(0.5, 0.0, 0.5);
			glRotated(90,0.0,1.0,0.0);
			glBindTexture(GL_TEXTURE_2D, this->_mur1);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.0);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.5, -0.5, 0.0);
				glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.0);
			glEnd();
		glPopMatrix();

		//dessiner le mur 2 vers -x
		glPushMatrix();
			glTranslated(-0.5, 0.0, 0.5);
			glRotated(90,0.0,1.0,0.0);
			glBindTexture(GL_TEXTURE_2D, this->_mur2);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.0);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.5, -0.5, 0.0);
				glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.0);
			glEnd();
		glPopMatrix();
	
		//dessiner le mur 3 vers z
		glPushMatrix();
			glTranslated(0.0, 0.5, 0.5);
			glRotated(90,0.0,1.0,0.0);
			glRotated(90,1.0,0.0,0.0);
			glBindTexture(GL_TEXTURE_2D, this->_mur3);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.0);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.5, -0.5, 0.0);
				glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.0);
			glEnd();
		glPopMatrix();

		//dessiner le mur 4 vers -z
		glPushMatrix();
			glTranslated(0.0, -0.5, 0.5);
			glRotated(90,0.0,1.0,0.0);
			glRotated(90,1.0,0.0,0.0);
			glBindTexture(GL_TEXTURE_2D, this->_mur4);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.0);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.5, -0.5, 0.0);
				glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.0);
			glEnd();
		glPopMatrix();
	glPopMatrix();
}

void TheRoom::VitreTransparante()
{
	glPushMatrix();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->BleuCiel(0.1));
		
		//**********************les faces**********************************************
		//face deriere
		glBegin(GL_QUADS);
			glVertex3f(-0.5, 0.5,0.0);
			glVertex3f(0.5, 0.5,0.0);
			glVertex3f(0.5, -0.5,0.0);
			glVertex3f(-0.5, -0.5,0.0);
		glEnd();

		//face devnat
		glBegin(GL_QUADS);
			glVertex3f(-0.475, -0.475,0.025);
			glVertex3f(0.475, -0.475,0.025);
			glVertex3f(0.475, 0.475,0.025);
			glVertex3f(-0.475, 0.475,0.025);
		glEnd();

		//face de haut
		glBegin(GL_QUADS);
			glVertex3f(-0.5, 0.5,0.0);
			glVertex3f(0.5, 0.5,0.0);
			glVertex3f(0.475, 0.475,0.025);
			glVertex3f(-0.475, 0.475,0.025);
		glEnd();

		//face de bas
		glBegin(GL_QUADS);
			glVertex3f(-0.475, -0.475,0.025);
			glVertex3f(0.475, -0.475,0.025);
			glVertex3f(0.5, -0.5,0.0);
			glVertex3f(-0.5, -0.5,0.0);
		glEnd();

		//face de gauche
		glBegin(GL_QUADS);
			glVertex3f(-0.5, 0.5,0.0);
			glVertex3f(0.475, 0.475,0.025);
			glVertex3f(0.475, -0.475,0.025);
			glVertex3f(-0.5, -0.5,0.0);
		glEnd();

		//face de droite
		glBegin(GL_QUADS);
			glVertex3f(-0.475, -0.475,0.025);
			glVertex3f(0.5, -0.5,0.0);
			glVertex3f(0.5, 0.5,0.0);
			glVertex3f(-0.475, 0.475,0.025);
		glEnd();
		//************************fin des face****************************************/

		glDisable(GL_BLEND); 
	glPopMatrix();
}

void TheRoom::VitrineExposition(float largeur, float hauteur)
{
	glPushMatrix();
	glScaled(largeur, hauteur, largeur);
		//******************les pieds********************************/
		float couleurTable[] = { 0.35F,0.176F,0.0F,1.0F };
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleurTable);
		//pied gauche bas
		glPushMatrix();
			glTranslated(0.5, 0.1, 0.5);
			glScaled(1.0,2.0,1.0);
			glutSolidCube(0.1);
		glPopMatrix();

		//pide droite bas
		glPushMatrix();
			glTranslated(-0.5, 0.1, 0.5);
			glScaled(1.0,2.0,1.0);
			glutSolidCube(0.1);
		glPopMatrix();

		//pied gauche haut
		glPushMatrix();
			glTranslated(0.5, 0.1, -0.5);
			glScaled(1.0,2.0,1.0);
			glutSolidCube(0.1);
		glPopMatrix();

		//pide droite haut
		glPushMatrix();
			glTranslated(-0.5, 0.1, -0.5);
			glScaled(1.0,2.0,1.0);
			glutSolidCube(0.1);
		glPopMatrix();
		//*************************fin des pieds***************************/

		//***************************les plaque laterale********************/
		//plaque gauche
		glPushMatrix();
			glTranslated(0.5, 0.1+0.25+0.05, 0.0);
			glScaled(0.1,0.5,1.1);
			glutSolidCube(1.0);
		glPopMatrix();

		//plaque droite
		glPushMatrix();
			glTranslated(-0.5, 0.1+0.25+0.05, 0.0);
			glScaled(0.1,0.5,1.1);
			glutSolidCube(1.0);
		glPopMatrix();

		//plaque de devant
		glPushMatrix();
			glTranslated(0.0, 0.1+0.25+0.05, 0.5);
			glScaled(1.1,0.25,0.1);
			glutSolidCube(1.0);
		glPopMatrix();

		//plaque deriere
		glPushMatrix();
			glTranslated(0.0, 0.1+0.25+0.05, -0.5);
			glScaled(1.1,0.25,0.1);
			glutSolidCube(1.0);
		glPopMatrix();

		//plaque haut
		glPushMatrix();
			glTranslated(0.0, 0.1+0.25+0.05+0.25, 0.0);
			glScaled(1.1,0.1,1.1);
			glutSolidCube(1.0);
		glPopMatrix();
		//************************fin des plaques laterale******************/

		//***************************vert de la table***********************/
		glPushMatrix();
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->BleuCiel(0.4));
			glTranslated(0.0, 0.1+0.25+0.05+0.25+0.05, 0.0);
			glScaled(1.1,0.025,1.1);
			glutSolidCube(1.0);
			glDisable(GL_BLEND); 
		glPopMatrix();
		//*********************fin vert de la table*************************/

		//***********************vitre d'exposition************************/
		glPushMatrix();
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->BleuCiel(0.3));
			glTranslated(0.0, 0.1+0.25+0.05+0.25+0.05+0.025+0.5, 0.0);
			glScaled(1.0,1.0,1.0);
			glPushMatrix();
				glPushMatrix();
				for(int i = 0; i <4; i++)
				{
					glPushMatrix();
						glTranslated(0.0,0.0,-0.5);
						VitreTransparante();
					glPopMatrix();
					glRotated(90,0.0,1.0, 0.0);
				}
				glPopMatrix();

				glPushMatrix();
				for(int i = 0; i <2; i++)
				{
					glPushMatrix();
						glTranslated(0.0,0.5,0.0);
						glRotated(90,1.0,0.0, 0.0);
						VitreTransparante();
					glPopMatrix();
					glRotated(180,0.0,0.0, 1.0);
				}
				glPopMatrix();
			glPopMatrix();
			glDisable(GL_BLEND); 
		glPopMatrix();
		//********************fin exposition********************************/
	glPopMatrix();
}

void TheRoom::Lustre(float largeur, float hauteur)
{
	glPushMatrix();
	glScaled(largeur, hauteur, largeur);
		glPushMatrix();
			glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Brun());
			//cache lustre
			glPushMatrix();
				glScaled(0.5,0.5,1.0);
				this->CylindreRemplis();
			glPopMatrix();

			//Le fil
			glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Blanc());
			glPushMatrix();
				glTranslated(0.0,0.0,0.5);
				glScaled(0.05,0.05,2.0);
				this->CylindreRemplis();
			glPopMatrix();

			//les tigre de lustre
			//tige 1
			glPushMatrix();
				glTranslated(0.0,0.4975,0.5+1.0);
				glRotated(90,1.0,0.0,0.0);
				glScaled(0.05,0.05,1.95);
				this->CylindreRemplis();
			glPopMatrix();

			//tige 2
			glPushMatrix();
				glTranslated(-0.4975,0.0,0.5+1.0);
				glRotated(90,0.0,1.0,0.0);
				glScaled(0.05,0.05,1.95);
				this->CylindreRemplis();
			glPopMatrix();

			//lampe
			glPushMatrix();
				glTranslated(0.0,0.0,0.5+1.0+0.05-0.05);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Noir());
				glPushMatrix();
					glScaled(0.2,0.2,0.3);
					this->CylindreRemplis();
				glPopMatrix();
				glPushMatrix();
					glEnable(GL_BLEND);
					glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->BleuCiel(0.4));
					glTranslated(0.0,0.0,0.25);
					glScaled(0.6,0.6,1.2);
					glutSolidSphere(0.2,25,25);
					glDisable(GL_BLEND); 
				glPopMatrix();
			glPopMatrix();

			//le cache lampe
			glPushMatrix();
				glTranslated(0.0,0.0,0.5+1.0-0.05);
				glPushMatrix();
					glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Rouge());
					glScaled(1.0,1.0,0.2);
					this->CylindreCrue(0.04);
				glPopMatrix();
				glPushMatrix();
					glEnable(GL_BLEND);
					glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Rouge(0.6));
					glScaled(1.0,1.0,1.51);
					this->CylindreCrue(0.01);
					glDisable(GL_BLEND); 
				glPopMatrix();
			glPopMatrix();
			glPushMatrix();
			glTranslated(0.0,0.0,0.5+1.0+0.75-0.05);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Rouge());
				glScaled(1.0,1.0,0.1);
				this->CylindreCrue(0.04);
			glPopMatrix();
		
		glPopMatrix();
	glPopMatrix();
}

void TheRoom::CylindreRemplis()
{
		glPushMatrix();
			gluDisk(gluNewQuadric(),0,0.5,50,50);
			glTranslated(0, 0, 0.5);
			gluDisk(gluNewQuadric(),0,0.5,100,100);
		glPopMatrix();

		
		glPushMatrix();
			gluCylinder(gluNewQuadric(),0.5,0.5,0.5,100,100); 
			gluCylinder(gluNewQuadric(),0.5,0.5,0.5,100,100); 
		glPopMatrix();
}

void TheRoom::CylindreCrue(float epaisseur)
{
		glPushMatrix();
			gluDisk(gluNewQuadric(),0.5-epaisseur,0.5,50,50);
			glTranslated(0, 0, 0.5);
			gluDisk(gluNewQuadric(),0.5-epaisseur,0.5,100,100);
		glPopMatrix();

		
		glPushMatrix();
			gluCylinder(gluNewQuadric(),0.5,0.5,0.5,100,100);
			gluCylinder(gluNewQuadric(),0.5-epaisseur,0.5-epaisseur,0.5,100,100); 
		glPopMatrix();
}
