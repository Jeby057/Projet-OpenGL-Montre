#ifndef PIECE_H
#define PIECE_H

#include "Include.h"
#include <map>
#include "PPMImage.h"


/**
 * La classe pièce représente un pattern (un moule) de construction pour une piece donnée
 * L'appel de la méthode "BuildAndDisplay" construit un nouvel objet aux dimentions données dans le repère monde
 * Ainsi pour creer plusieurs objets avec le même pattern, "BuildAndDisplay" doit être rappelée
 * Remarque : L'appel de "BuildAndDisplay" peut être couteuse en mémoire et en temps de calculs car celle-ci calcule l'ensemble des faces/vertices/points de l'objet
 *            L'appel de "BuildAndSave" peut résoudre ce problème car elle permet de compiler l'objet à construire et de le sauvegarder dans la mémoire de la carte graphique
 *            A chaque ré-affichage, l'objet compilé sera ré-affiché
 *            "BuildAndSave" doit seulement être utilisée quand l'objet ne subit pas de modification sur l'intégrité des facettes/vertices/points de l'objets
 *			  Dans ce cas, "BuildAndDisplay" devra être rappelé
 *            Les rotations, translations, et homothétie peuvent par contre être utilisée avec "BuildAndSave" car elles ne modifient pas l'objet
 */
class Piece
{
private:

	/** 
	 * Chaque pattern possède un identifiant unique généré à la construction
	 * Il permet de référencer les objets compilés et sauvegardés par la carte graphique
	 */
	GLint _idPattern;

	/**
	 * Nombre de patterns construits
	 * Il permet de générer un identifiant de pattern unique lors de la construction d'un pattern 
	 * Remarque : Différent du nombre d'objets construits 
 	 *            (que l'on peut construire avec le pattern)
	 */
	static GLint _nbPatterns;

	/**
	 * Map <Id du pattern, Id de l'objet compilé>
	 * Permet de faire le lien entre le pattern et l'objet compilé
	 */
	static map<GLint, GLint> _idObjectsList;

public:
	Piece(void);

	virtual ~Piece(void);
	
	/**
	 * Permet de construire l'intégralité de l'objet (Appel de la fonction BuildAndDisplay) et de le sauvegarder dans la liste d'affichage de la carte graphique
	 * Cela permet de ne pas reconstruire intégralement la pièce à chaque ticks car cela peut être une opération couteuse
	 */
	virtual void BuildAndSave();

	/**
	 * Permet de construire intégralement l'objet
	 * Cette opération est implémentée dans les classes filles
	 * Elle peut être très coûteuse en fonction de l'objet construit (see BuildAndSave)
	 */
	virtual void BuildAndDisplay() = 0;

	void SetMaterial(const GLfloat* ambiant, const GLfloat* diffuse, const GLfloat* specular, const GLfloat shine);

	/**
	 * Permet de mettre à jour certaines informations de la pièce
	 */
	virtual void Update();

	virtual void FastDisplay();

	virtual void AddFlagToRebuild();

	void LoadTexture(GLuint* _faceTexture, char** face, int nb);
};
#endif
