#ifndef PIECE_H
#define PIECE_H

#include "Include.h"
#include <map>
#include "PPMImage.h"


/**
 * La classe pi�ce repr�sente un pattern (un moule) de construction pour une piece donn�e
 * L'appel de la m�thode "BuildAndDisplay" construit un nouvel objet aux dimentions donn�es dans le rep�re monde
 * Ainsi pour creer plusieurs objets avec le m�me pattern, "BuildAndDisplay" doit �tre rappel�e
 * Remarque : L'appel de "BuildAndDisplay" peut �tre couteuse en m�moire et en temps de calculs car celle-ci calcule l'ensemble des faces/vertices/points de l'objet
 *            L'appel de "BuildAndSave" peut r�soudre ce probl�me car elle permet de compiler l'objet � construire et de le sauvegarder dans la m�moire de la carte graphique
 *            A chaque r�-affichage, l'objet compil� sera r�-affich�
 *            "BuildAndSave" doit seulement �tre utilis�e quand l'objet ne subit pas de modification sur l'int�grit� des facettes/vertices/points de l'objets
 *			  Dans ce cas, "BuildAndDisplay" devra �tre rappel�
 *            Les rotations, translations, et homoth�tie peuvent par contre �tre utilis�e avec "BuildAndSave" car elles ne modifient pas l'objet
 */
class Piece
{
private:

	/** 
	 * Chaque pattern poss�de un identifiant unique g�n�r� � la construction
	 * Il permet de r�f�rencer les objets compil�s et sauvegard�s par la carte graphique
	 */
	GLint _idPattern;

	/**
	 * Nombre de patterns construits
	 * Il permet de g�n�rer un identifiant de pattern unique lors de la construction d'un pattern 
	 * Remarque : Diff�rent du nombre d'objets construits 
 	 *            (que l'on peut construire avec le pattern)
	 */
	static GLint _nbPatterns;

	/**
	 * Map <Id du pattern, Id de l'objet compil�>
	 * Permet de faire le lien entre le pattern et l'objet compil�
	 */
	static map<GLint, GLint> _idObjectsList;

public:
	Piece(void);

	virtual ~Piece(void);
	
	/**
	 * Permet de construire l'int�gralit� de l'objet (Appel de la fonction BuildAndDisplay) et de le sauvegarder dans la liste d'affichage de la carte graphique
	 * Cela permet de ne pas reconstruire int�gralement la pi�ce � chaque ticks car cela peut �tre une op�ration couteuse
	 */
	virtual void BuildAndSave();

	/**
	 * Permet de construire int�gralement l'objet
	 * Cette op�ration est impl�ment�e dans les classes filles
	 * Elle peut �tre tr�s co�teuse en fonction de l'objet construit (see BuildAndSave)
	 */
	virtual void BuildAndDisplay() = 0;

	void SetMaterial(const GLfloat* ambiant, const GLfloat* diffuse, const GLfloat* specular, const GLfloat shine);

	/**
	 * Permet de mettre � jour certaines informations de la pi�ce
	 */
	virtual void Update();

	virtual void FastDisplay();

	virtual void AddFlagToRebuild();

	void LoadTexture(GLuint* _faceTexture, char** face, int nb);
};
#endif
