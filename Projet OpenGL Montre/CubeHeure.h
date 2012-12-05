/**
 * Classe CubeHeur
 * *************
 * Cette classe construit les cubes qui indique l'heur dans la montre (que l'heur par les minutes et les secondes) .
 * Le construction de la pi�ce dessine un cube au centre du monde.
 * Le cube est constitu� de 4 faces, sur chaque face il y a un chiffre allons de 1 � 12.
 * Elle sera repositionn�e par la suite selon l'emplacement souhait�.
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 14 novembre 2012
 * Version : 1
 */

#ifndef CUBEHEURE_H
#define CUBEHEURE_H

#include "Include.h"
#include "Piece.h"

class CubeHeure : public Piece
{
	/**
	 * Taille de la pice
	 * A partir de cette variable, on fait des traitement pour calculer la heuteur, la largeur et l'epesseur de la piece
	 */
	float _taille;

	/**
	 * Tableau des texture des faces de cube
	 * Le cube affiche 4 chiffres, donc il a besoin de 4 textures, les deux autres sont necessaire pour dessiner l'interieur de cube et ces bordeurs
	 * Les textures charger sont des image de type PPM, c-�-d : 24 bits.
	 */
	GLuint _faceTexture[6];

public:
	/**
	 * Constructeur de la classe
	 * Il initialise la taille du cube
	 * Il charge les textures necessaire pour le cube
	 * Il demande deux parametres :
	 * @taille : taille du cube
	 * @namFace : un tableau de chaine de caractaire portant les nom des texture a charg�
	 */
	CubeHeure(float taille, char* namFace[6]);

	/**
	 * Destruction de la montre
	 * D�salocation de tous les composants
	 */
	virtual ~CubeHeure(void);

	/**
	 * M�thode surcharger de la classe m�re Piece.
	 * Permet d'afficher la pi�ce dans la sc�ne
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();
};
#endif
