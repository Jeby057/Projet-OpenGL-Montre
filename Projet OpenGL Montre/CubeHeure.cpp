#include "CubeHeure.h"


CubeHeure::CubeHeure(float taille, char* namFace[6])
{
	this->_taille = taille;

	this->angleRotation = 360;
	this->temps = 0;

	this->LoadTexture(namFace);
}


CubeHeure::~CubeHeure(void)
{
}


void CubeHeure::BuildAndDisplay()
{
	//glRotatef(angleRotation,1.0F,0.0F,0.0F); 
	//décalage
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float tCalculer = _taille/6; 

	for(int i = 0; i <4 ; i++)
	{
		
		glRotatef(90,1.0F,0.0F,0.0F);

		
		/**********************************************************************************************/
		//face chiffre devant
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[i]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-_taille*1.5, _taille-tCalculer, _taille);
		glTexCoord2f(0.0, 1.0); glVertex3f(-_taille*1.5, -_taille+tCalculer, _taille);
		glTexCoord2f(1.0, 1.0); glVertex3f(_taille*1.5, -_taille+tCalculer, _taille);
		glTexCoord2f(1.0, 0.0); glVertex3f(_taille*1.5, _taille-tCalculer, _taille);
		glEnd();

		//face chiffre derriere
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[4]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-_taille*1.5, _taille-tCalculer, _taille-tCalculer);
		glTexCoord2f(0.0, 1.0); glVertex3f(-_taille*1.5, -_taille+tCalculer, _taille-tCalculer);
		glTexCoord2f(1.0, 1.0); glVertex3f(_taille*1.5, -_taille+tCalculer, _taille-tCalculer);
		glTexCoord2f(1.0, 0.0); glVertex3f(_taille*1.5, _taille-tCalculer, _taille-tCalculer);
		glEnd();
		
		
		/**********************************************************************************************/


		/**********************************************************************************************/
		//face chiffre entre face gauche
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[4]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-_taille*1.5, _taille-tCalculer, _taille);
		glTexCoord2f(0.0, 1.0); glVertex3f(-_taille*1.5, -_taille+tCalculer, _taille);
		glTexCoord2f(1.0, 1.0); glVertex3f(-_taille*1.5, -_taille+tCalculer, _taille-tCalculer);
		glTexCoord2f(1.0, 0.0); glVertex3f(-_taille*1.5, _taille-tCalculer, _taille-tCalculer);
		glEnd();

		//face chiffre entre face droite
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[4]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(_taille*1.5, _taille-tCalculer, _taille);
		glTexCoord2f(0.0, 1.0); glVertex3f(_taille*1.5, -_taille+tCalculer, _taille);
		glTexCoord2f(1.0, 1.0); glVertex3f(_taille*1.5, -_taille+tCalculer, _taille-tCalculer);
		glTexCoord2f(1.0, 0.0); glVertex3f(_taille*1.5, _taille-tCalculer, _taille-tCalculer);
		glEnd();

		
		//face latérale chiffre 1 et 2
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[5]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-_taille*1.5, -_taille, _taille-tCalculer);
		glTexCoord2f(0.0, 1.0); glVertex3f(-_taille*1.5, -_taille+tCalculer, _taille);
		glTexCoord2f(1.0, 1.0); glVertex3f(_taille*1.5, -_taille+tCalculer, _taille);
		glTexCoord2f(1.0, 0.0); glVertex3f(_taille*1.5, -_taille, _taille-tCalculer);
		glEnd();

		//face latérale triangle gauche
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[5]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(_taille*1.5, -_taille, _taille-tCalculer);
		glTexCoord2f(0.0, 1.0); glVertex3f(_taille*1.5, -_taille+tCalculer, _taille);
		glTexCoord2f(1.0, 1.0); glVertex3f(_taille*1.5, -_taille+tCalculer, _taille-tCalculer);
		glTexCoord2f(1.0, 0.0); glVertex3f(_taille*1.5, -_taille, _taille-tCalculer);
		glEnd();

		//face latérale triangle droite
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[5]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-_taille*1.5, -_taille, _taille-tCalculer);
		glTexCoord2f(0.0, 1.0); glVertex3f(-_taille*1.5, -_taille+tCalculer, _taille);
		glTexCoord2f(1.0, 1.0); glVertex3f(-_taille*1.5, -_taille+tCalculer, _taille-tCalculer);
		glTexCoord2f(1.0, 0.0); glVertex3f(-_taille*1.5, -_taille, _taille-tCalculer);
		glEnd();
		
		/**************************************************************************************************/
		
		
		/**********************************************************************************************/
		//face de face de 1.1
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[5]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(_taille*1.5, _taille/2, _taille);
		glTexCoord2f(0.0, 1.0); glVertex3f(_taille*1.5, -_taille/2, _taille);
		glTexCoord2f(1.0, 1.0); glVertex3f(_taille*1.5+3*tCalculer, -_taille/3, _taille/2);
		glTexCoord2f(1.0, 0.0); glVertex3f(_taille*1.5+3*tCalculer, _taille/3, _taille/2);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[5]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(_taille*1.5+3*tCalculer, _taille/3, _taille/2);
		glTexCoord2f(0.0, 1.0); glVertex3f(_taille*1.5+3*tCalculer, -_taille/3, _taille/2);
		glTexCoord2f(1.0, 1.0); glVertex3f(_taille*1.5+3*tCalculer, -_taille/3, _taille/2.5);
		glTexCoord2f(1.0, 0.0); glVertex3f(_taille*1.5+3*tCalculer, _taille/3, _taille/2.5);
		glEnd();

		//face de face de 1.2 face
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[5]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(_taille*1.5, _taille/2, _taille-tCalculer);
		glTexCoord2f(0.0, 1.0); glVertex3f(_taille*1.5, -_taille/2, _taille-tCalculer);
		glTexCoord2f(1.0, 1.0); glVertex3f(_taille*1.5+3*tCalculer, -_taille/3, _taille/2.5);
		glTexCoord2f(1.0, 0.0); glVertex3f(_taille*1.5+3*tCalculer, _taille/3, _taille/2.5);
		glEnd();

		//face de face de 1.2 gauche
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[5]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(_taille*1.5, _taille/2, _taille);
		glTexCoord2f(0.0, 1.0); glVertex3f(_taille*1.5, _taille/2, _taille-tCalculer);
		glTexCoord2f(1.0, 1.0); glVertex3f(_taille*1.5+3*tCalculer, _taille/3, _taille/2.5);
		glTexCoord2f(1.0, 0.0);  glVertex3f(_taille*1.5+3*tCalculer, _taille/3, _taille/2);
		glEnd();
		
		//face de face de 1.2 droite
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[5]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(_taille*1.5, -_taille/2, _taille);
		glTexCoord2f(0.0, 1.0); glVertex3f(_taille*1.5, -_taille/2, _taille-tCalculer);
		glTexCoord2f(1.0, 1.0); glVertex3f(_taille*1.5+3*tCalculer, -_taille/3, _taille/2.5);
		glTexCoord2f(1.0, 0.0); glVertex3f(_taille*1.5+3*tCalculer, -_taille/3, _taille/2);
		glEnd();

		/**********************************************************************************************/
		
	}
	

}

void CubeHeure::idle()
{
	this->temps++;
	if(this->temps == 10)
	{
		this->angleRotation -=1;
		this->temps = 0;
		if(this->angleRotation == 0)
			this->angleRotation = 360;
	}
}


void CubeHeure::LoadTexture(char* face[6])
{
	glGenTextures(6, this->_faceTexture);
	for(int i = 0; i <6; i++)
	{
		char buffer[256];
		strcpy(buffer,"textures/");
		PPMImage* image1 = new PPMImage(strcat(buffer,face[i]));
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[i]);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image1->GetSizeX(), image1->GetSizeY(),GL_RGB, GL_UNSIGNED_BYTE, image1->GetImage());
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	}

}