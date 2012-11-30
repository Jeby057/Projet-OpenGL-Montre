#include "PlaqueSeparation.h"


PlaqueSeparation::PlaqueSeparation(float hauteur, float largeur, float longueur, float txReduction, char** texture, int nbTextures):
_hauteur(hauteur), _largeur(largeur), _longueur(longueur), _txReduction(txReduction)
{
	_texture = 0;
	_faceTexture = new GLuint[2];
	LoadTexture(_faceTexture, texture, nbTextures);
}


PlaqueSeparation::~PlaqueSeparation(void)
{
	delete _faceTexture;
}


void PlaqueSeparation::BuildAndDisplay()
{
	BuildPattern(_hauteur);
	BuildPattern(-_hauteur);
}


void PlaqueSeparation::BuildPattern(float h)
{
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 1.0);		
		glVertex3f(-_longueur/2.0, h/2.0, _largeur/2.0);

		glTexCoord2f(0.0, 0.0);		
		glVertex3f(-_longueur/2.0, h/2.0, -_largeur/2.0);

		glTexCoord2f(1.0, 0.0);		
		glVertex3f(_longueur/2.0 * _txReduction, h/2.0, -_largeur/2.0);

		glTexCoord2f(1.0, 1.0);		
		glVertex3f(_longueur/2.0 * _txReduction, h/2.0, _largeur/2.0);
	glEnd();
	glBegin(GL_QUADS);	
		glVertex3f(_longueur/2.0 * _txReduction, h/2.0, -_largeur/2.0);
		glVertex3f(_longueur/2.0, h/2.0, -_largeur/2.0 * _txReduction);
		glVertex3f(_longueur/2.0, h/2.0, _largeur/2.0 * _txReduction);
		glVertex3f(_longueur/2.0 * _txReduction, h/2.0, _largeur/2.0);
	glEnd();
}

void PlaqueSeparation::SetTexture(int id){
	_texture = id;
}


void PlaqueSeparation::FastDisplay()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->_faceTexture[_texture]);
	
	Material mat = Material();
	mat.ToWhiteReflect();
	mat.Enable();

	Piece::FastDisplay();

	mat.Disable();
	glDisable(GL_TEXTURE_2D);

}