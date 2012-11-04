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
}
