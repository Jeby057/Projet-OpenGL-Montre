#include "CubeHeure.h"

//Constructeur de la pièce
CubeHeure::CubeHeure(float taille, char* namFace[6]) : _taille(taille)
{
	/**
	 * Chargement des textures necessaires pour afficher le cube
	 */
	this->LoadTexture(_faceTexture, namFace, 6);
}

//destructeur de la pièce
CubeHeure::~CubeHeure(void)
{
}

//méthode construction et affichage des composants
void CubeHeure::BuildAndDisplay()
{
	/**
	* définir la couleur de cube
	*/
	Material mat = Material();
	mat.ToChrome();
	mat.Enable();

	//accepter l'affichage des textures
	glEnable(GL_TEXTURE_2D);

	//calculer le décalage des points
	float tCalculer = _taille/6; 

	//boucler 4 fois sur chaque face pour construire un cube
	for(int i = 0; i <4 ; i++)
	{
		glRotatef(90,1.0F,0.0F,0.0F);

		/**********************************************************************************************/
		//face cube exterieur, face de chiffre
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[i]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-_taille*1.5, _taille-tCalculer, _taille);
		glTexCoord2f(0.0, 1.0); glVertex3f(-_taille*1.5, -_taille+tCalculer, _taille);
		glTexCoord2f(1.0, 1.0); glVertex3f(_taille*1.5, -_taille+tCalculer, _taille);
		glTexCoord2f(1.0, 0.0); glVertex3f(_taille*1.5, _taille-tCalculer, _taille);
		glEnd();

		//face cube Interieur
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[4]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-_taille*1.5, _taille-tCalculer, _taille-tCalculer);
		glTexCoord2f(0.0, 1.0); glVertex3f(-_taille*1.5, -_taille+tCalculer, _taille-tCalculer);
		glTexCoord2f(1.0, 1.0); glVertex3f(_taille*1.5, -_taille+tCalculer, _taille-tCalculer);
		glTexCoord2f(1.0, 0.0); glVertex3f(_taille*1.5, _taille-tCalculer, _taille-tCalculer);
		glEnd();
		
		/**********************************************************************************************/

		/**********************************************************************************************/
		//face cube entre face gauche
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[4]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-_taille*1.5, _taille-tCalculer, _taille);
		glTexCoord2f(0.0, 1.0); glVertex3f(-_taille*1.5, -_taille+tCalculer, _taille);
		glTexCoord2f(1.0, 1.0); glVertex3f(-_taille*1.5, -_taille+tCalculer, _taille-tCalculer);
		glTexCoord2f(1.0, 0.0); glVertex3f(-_taille*1.5, _taille-tCalculer, _taille-tCalculer);
		glEnd();

		//face cube entre face droite
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[4]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(_taille*1.5, _taille-tCalculer, _taille);
		glTexCoord2f(0.0, 1.0); glVertex3f(_taille*1.5, -_taille+tCalculer, _taille);
		glTexCoord2f(1.0, 1.0); glVertex3f(_taille*1.5, -_taille+tCalculer, _taille-tCalculer);
		glTexCoord2f(1.0, 0.0); glVertex3f(_taille*1.5, _taille-tCalculer, _taille-tCalculer);
		glEnd();

		
		//face cube latérale 1 et 2
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[5]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-_taille*1.5, -_taille, _taille-tCalculer);
		glTexCoord2f(0.0, 1.0); glVertex3f(-_taille*1.5, -_taille+tCalculer, _taille);
		glTexCoord2f(1.0, 1.0); glVertex3f(_taille*1.5, -_taille+tCalculer, _taille);
		glTexCoord2f(1.0, 0.0); glVertex3f(_taille*1.5, -_taille, _taille-tCalculer);
		glEnd();

		//face cube latérale triangle gauche
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[5]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(_taille*1.5, -_taille, _taille-tCalculer);
		glTexCoord2f(0.0, 1.0); glVertex3f(_taille*1.5, -_taille+tCalculer, _taille);
		glTexCoord2f(1.0, 1.0); glVertex3f(_taille*1.5, -_taille+tCalculer, _taille-tCalculer);
		glTexCoord2f(1.0, 0.0); glVertex3f(_taille*1.5, -_taille, _taille-tCalculer);
		glEnd();

		//face cube latérale triangle droite
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

	//une fois terminé, désactiver l'affichage des textures
	glDisable(GL_TEXTURE_2D);
	mat.Disable();
}
