#include "PieceMinute.h"


PieceMinute::PieceMinute(float taille):_taille(taille)
{
	this->LoadTexture();
}


PieceMinute::~PieceMinute(void)
{
}

void PieceMinute::BuildAndDisplay()
{
	//repere de monde
	this->RepereMonde(1);

	glPushMatrix();
	glRotatef(52,0.0,1.0,0.0);
	glRotatef(-90,1.0,0.0,0.0);
	glTranslatef(this->_taille/2.5,0.0,0.0);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,couluer->Gris(1,0));
	this->PlaqueMinute();
	glPopMatrix();

	//les tiges
	glPushMatrix(); 
	for(int i = 0; i < 61; i++)
	{
		if((i%5) == 0) 
		{
			if(i==30)
			{
				glMaterialfv(GL_FRONT,GL_DIFFUSE,couluer->Noir());
				this->Tiges(this->_taille/30);
			}
			else if(i == 0)
			{
				
				glMaterialfv(GL_FRONT,GL_DIFFUSE,couluer->RougeFonce());
				this->Tiges(this->_taille/40);
			}
			else
			{
				glMaterialfv(GL_FRONT,GL_DIFFUSE,couluer->Noir());
				this->Tiges(this->_taille/50);
			}
		}
		else
		{
			glMaterialfv(GL_FRONT,GL_DIFFUSE,couluer->Noir());
			this->Tiges(0);
		}
		glRotatef(1.8,0.0,1.0,0.0);
	}
	glPopMatrix();
	
}


void PieceMinute::LoadTexture()
{
}

//dessiner un cube
void PieceMinute::Tiges(float l)
{	
	
	float t = this->_taille/50;
	float decalageX;
	if(l != this->_taille/50 && l !=0)
	{
		decalageX = this->_taille-t+this->_taille/50;
	}
	else
	{
		decalageX = this->_taille-(t-l);
	}
	float decalageY = this->_taille/15;
	
	float x, y, z;
	x = t + l;
	y = t/4;
	z = t/2;

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
	glPopMatrix();
}

void PieceMinute::PlaqueMinute()
{
	
	float x, y, z;

	x = this->_taille;
	y = this->_taille*1.05; 
	z = this->_taille/15;

	glPushMatrix();
	//face de devant
	glBegin(GL_QUADS);
			glVertex3f(0, 95*y/100, z);
			glVertex3f(40*x/100, y, z);
			glVertex3f(80*x/100, 95*y/100, z);
			glVertex3f(16*x/100, 70*y/100, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(16*x/100, 70*y/100, z);
			glVertex3f(80*x/100, 95*y/100, z);
			glVertex3f(x, 20*y/100, z);
			glVertex3f(40*x/100, 15*y/100, z);
			
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(40*x/100, 15*y/100, z);
			glVertex3f(x, 20*y/100, z);
			glVertex3f(x, -20*y/100, z);
			glVertex3f(40*x/100, -15*y/100, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(40*x/100, -15*y/100, z);
			glVertex3f(x, -20*y/100, z);
			glVertex3f(80*x/100, -95*y/100, z);
			glVertex3f(16*x/100, -70*y/100, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(16*x/100, -70*y/100, z);
			glVertex3f(80*x/100, -95*y/100, z);
			glVertex3f(40*x/100, -y, z);
			glVertex3f(0, -95*y/100, z);
	glEnd();
	
	//face de deriere
	glBegin(GL_QUADS);
			glVertex3f(0, 95*y/100, -z);
			glVertex3f(40*x/100, y, -z);
			glVertex3f(80*x/100, 95*y/100, -z);
			glVertex3f(16*x/100, 70*y/100, -z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(16*x/100, 70*y/100, -z);
			glVertex3f(80*x/100, 95*y/100, -z);
			glVertex3f(x, 20*y/100, -z);
			glVertex3f(40*x/100, 15*y/100, -z);
			
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(40*x/100, 15*y/100, -z);
			glVertex3f(x, 20*y/100, -z);
			glVertex3f(x, -20*y/100, -z);
			glVertex3f(40*x/100, -15*y/100, -z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(40*x/100, -15*y/100, -z);
			glVertex3f(x, -20*y/100, -z);
			glVertex3f(80*x/100, -95*y/100, -z);
			glVertex3f(16*x/100, -70*y/100, -z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(16*x/100, -70*y/100, -z);
			glVertex3f(80*x/100, -95*y/100, -z);
			glVertex3f(40*x/100, -y, -z);
			glVertex3f(0, -95*y/100, -z);
	glEnd();

	//face de cotes
	glBegin(GL_QUADS);
			glVertex3f(0, -95*y/100, z);
			glVertex3f(0, -95*y/100, -z);
			glVertex3f(16*x/100, -70*y/100, -z);
			glVertex3f(16*x/100, -70*y/100, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(40*x/100, -15*y/100, z);
			glVertex3f(40*x/100, -15*y/100, -z);
			glVertex3f(16*x/100, -70*y/100, -z);
			glVertex3f(16*x/100, -70*y/100, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(40*x/100, 15*y/100, z);
			glVertex3f(40*x/100, 15*y/100, -z);
			glVertex3f(40*x/100, -15*y/100, -z);
			glVertex3f(40*x/100, -15*y/100, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(40*x/100, 15*y/100, z);
			glVertex3f(40*x/100, 15*y/100, -z);
			glVertex3f(16*x/100, 70*y/100, -z);
			glVertex3f(16*x/100, 70*y/100, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(0, 95*y/100, z);
			glVertex3f(0, 95*y/100, -z);
			glVertex3f(16*x/100, 70*y/100, -z);
			glVertex3f(16*x/100, 70*y/100, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(0, 95*y/100, z);
			glVertex3f(0, 95*y/100, -z);
			glVertex3f(40*x/100, y, -z);
			glVertex3f(40*x/100, y, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(40*x/100, y, z);
			glVertex3f(40*x/100, y, -z);
			glVertex3f(80*x/100, 95*y/100, -z);
			glVertex3f(80*x/100, 95*y/100, z);
	glEnd();


	glBegin(GL_QUADS);
			glVertex3f(80*x/100, 95*y/100, z);
			glVertex3f(80*x/100, 95*y/100, -z);
			glVertex3f(x, 20*y/100, -z);
			glVertex3f(x, 20*y/100, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(x, 20*y/100, z);
			glVertex3f(x, 20*y/100, -z);
			glVertex3f(x, -20*y/100, -z);
			glVertex3f(x,-20*y/100, z);
	glEnd();
	
	glBegin(GL_QUADS);
			glVertex3f(80*x/100, -95*y/100, z);
			glVertex3f(80*x/100, -95*y/100, -z);
			glVertex3f(x, -20*y/100, -z);
			glVertex3f(x, -20*y/100, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(40*x/100, -y, z);
			glVertex3f(40*x/100, -y, -z);
			glVertex3f(80*x/100, -95*y/100, -z);
			glVertex3f(80*x/100, -95*y/100, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(0, -95*y/100, z);
			glVertex3f(0, -95*y/100, -z);
			glVertex3f(40*x/100, -y, -z);
			glVertex3f(40*x/100, -y, z);
	glEnd();
	glPopMatrix();
}

/*
void PieceMinute::Surface()
{
	
	float x, y, z;

	x = 1;
	y = 1; 
	z =0.1;

	//face de devant
	glBegin(GL_QUADS);
			glVertex3f(0, 95*y/100, z);
			glVertex3f(40*x/100, y, z);
			glVertex3f(80*x/100, 95*y/100, z);
			glVertex3f(20*x/100, 70*y/100, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(20*x/100, 70*y/100, z);
			glVertex3f(80*x/100, 95*y/100, z);
			glVertex3f(x, 20*y/100, z);
			glVertex3f(40*x/100, 15*y/100, z);
			
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(40*x/100, 15*y/100, z);
			glVertex3f(x, 20*y/100, z);
			glVertex3f(x, -20*y/100, z);
			glVertex3f(40*x/100, -15*y/100, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(40*x/100, -15*y/100, z);
			glVertex3f(x, -20*y/100, z);
			glVertex3f(80*x/100, -95*y/100, z);
			glVertex3f(20*x/100, -70*y/100, z);
	glEnd();

		glBegin(GL_QUADS);
			glVertex3f(20*x/100, -70*y/100, z);
			glVertex3f(80*x/100, -95*y/100, z);
			glVertex3f(40*x/100, -y, z);
			glVertex3f(0, -95*y/100, z);
	glEnd();

	//face de deriere
	z = -0.1;
	glBegin(GL_QUADS);
			glVertex3f(0, 95*y/100, z);
			glVertex3f(40*x/100, y, z);
			glVertex3f(80*x/100, 95*y/100, z);
			glVertex3f(20*x/100, 70*y/100, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(20*x/100, 70*y/100, z);
			glVertex3f(80*x/100, 95*y/100, z);
			glVertex3f(x, 20*y/100, z);
			glVertex3f(40*x/100, 15*y/100, z);
			
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(40*x/100, 15*y/100, z);
			glVertex3f(x, 20*y/100, z);
			glVertex3f(x, -20*y/100, z);
			glVertex3f(40*x/100, -15*y/100, z);
	glEnd();

	glBegin(GL_QUADS);
			glVertex3f(40*x/100, -15*y/100, z);
			glVertex3f(x, -20*y/100, z);
			glVertex3f(80*x/100, -95*y/100, z);
			glVertex3f(20*x/100, -70*y/100, z);
	glEnd();

		glBegin(GL_QUADS);
			glVertex3f(20*x/100, -70*y/100, z);
			glVertex3f(80*x/100, -95*y/100, z);
			glVertex3f(40*x/100, -y, z);
			glVertex3f(0, -95*y/100, z);
	glEnd();
}
























/*
void PieceMinute::BuildAndDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float x = _taille/2.5;
	float y = _taille;
	float z = 0;
	/*
	//face chiffre devant
	glRotated(90.0, 1.0,0.0,0.0);
	for(int i = 0; i < 1; i ++)
	{
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[0]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(-x, -y, 0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-x, y, 0);
			glTexCoord2f(1.0, 1.0); glVertex3f(x, y, z);
			glTexCoord2f(1.0, 0.0); glVertex3f(x, -y, z);
		glEnd();
		z+=0.0001;
	}
	*/


	
	/*
	glBegin(GL_QUADS);
		glVertex3f(0.0, 0.8, 0.0);
		glVertex3f(0.4, 1.0, 0.0);
		glVertex3f(0.4, 0.8, 0.0);
		glVertex3f(0.2, 0.7, 0.0);

		glVertex3f(0.2, 0.7, 0.0);
		glVertex3f(0.4, 0.8, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(0.2, 0.5, 0.0);
	glEnd();
	*/
	/*
	glRotatef(90,0.0F,1.0F,0.0F);
	GLint i;
    GLfloat cosine, sine;
	glBegin(GL_TRIANGLE_STRIP);
		
		glVertex3f(1.05,0.2,0.1);
		for(i=0;i<=49;i++){
				cosine=cos(i*2*PI/100.0);
				sine=sin(i*2*PI/100.0);
				glVertex3f(cosine,sine,0.1);
		}
		glVertex3f(-1.05,0.2,0.1);
		glVertex3f(-1.05,0.8,0.1);
		glVertex3f(1.05,0.8,0.1);
		glVertex3f(1.05,0.2,0.1);
	glEnd();
	*/
	/*
}
*/
/*
void PieceMinute::LoadTexture()
{
	glGenTextures(1, this->_faceTexture);
	PPMImage* image1 = new PPMImage("textures/minute.ppm");
	glBindTexture(GL_TEXTURE_2D, this->_faceTexture[0]);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image1->GetSizeX(), image1->GetSizeY(),GL_RGB, GL_UNSIGNED_BYTE, image1->GetImage());
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

}
*/