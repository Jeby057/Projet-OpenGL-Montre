#include "piece.h"

GLint Piece::_nbPatterns = 0;
map<GLint, GLint> Piece::_idObjectsList = map<GLint, GLint>();

Piece::Piece(void)
{
	_idPattern = _nbPatterns++;
}


Piece::~Piece(void)
{
	
}

void Piece::Update()
{
	// Rien à faire
}

void Piece::BuildAndSave()
{
	// Récupération de l'id de la liste par l'id de l'objet
	GLint idObject = _idObjectsList[_idPattern];

	// Si l'objet n'existe pas
	if(idObject == 0)
	{
		// Création de la liste
		idObject = glGenLists(1);
		glNewList(idObject, GL_COMPILE);
		BuildAndDisplay();
		glEndList();

		// Référencement
		_idObjectsList[_idPattern] = idObject;
	}
}


void Piece::FastDisplay()
{
	// Récupération de l'id de la liste par l'id de l'objet
	GLint idObject = _idObjectsList[_idPattern];

	// Affichage si il existe
	if(idObject != 0)
		glCallList(idObject);
	else
		BuildAndSave();
}


void SetMaterial(const GLfloat* ambiant, const GLfloat* diffuse, const GLfloat* specular, const GLfloat shine)
{
	// Propriété d'affichage
	glMaterialfv (GL_FRONT, GL_AMBIENT, ambiant);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, specular);
	glMaterialf (GL_FRONT, GL_SHININESS, shine * 128.0);
}


void Piece::LoadTexture(GLuint* faceTexture, char** face, int nb)
{
	glGenTextures(nb, faceTexture);
	for(int i = 0; i <nb; i++)
	{
		char buffer[256];
		strcpy(buffer,"textures/");
		PPMImage* image1 = new PPMImage(strcat(buffer,face[i]));
		glBindTexture(GL_TEXTURE_2D, faceTexture[i]);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image1->GetSizeX(), image1->GetSizeY(),GL_RGB, GL_UNSIGNED_BYTE, image1->GetImage());
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	}

}

void Piece::AddFlagToRebuild()
{
	_idObjectsList[_idPattern] = 0;
}
