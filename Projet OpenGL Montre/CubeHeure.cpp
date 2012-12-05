#include "CubeHeure.h"


CubeHeure::CubeHeure(float taille, char* namFace[6])
{
	this->_taille = taille;

	this->angleRotation = 360;
	this->temps = 0;

	this->LoadTexture(_faceTexture, namFace, 6);
}


CubeHeure::~CubeHeure(void)
{
}


void CubeHeure::BuildAndDisplay()
{
	
	Material mat = Material();
	mat.ToChrome();
	mat.Enable();

	glEnable(GL_TEXTURE_2D);
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
	glDisable(GL_TEXTURE_2D);

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
