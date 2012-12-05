/**
 * Classe CubeHeur
 * *************
 * Cette classe construit les cubes qui indique l'heur dans la montre (que l'heur par les minutes et les secondes) .
 * Le construction de la pièce dessine un cube au centre du monde.
 * Le cube est constitué de 4 faces, sur chaque face il y a un chiffre allons de 1 à 12.
 * Elle sera repositionnée par la suite selon l'emplacement souhaité.
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 14 novembre 2012
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
	 * Les textures charger sont des image de type PPM, c-à-d : 24 bits.
	 */
	GLuint _faceTexture[6];

public:
	/**
	 * Constructeur de la classe
	 * Il initialise la taille du cube
	 * Il charge les textures necessaire pour le cube
	 * Il demande deux parametres :
	 * @taille : taille du cube
	 * @namFace : un tableau de chaine de caractaire portant les nom des texture a chargé
	 */
	CubeHeure(float taille, char* namFace[6]);

	/**
	 * Destruction de la montre
	 * Désalocation de tous les composants
	 */
	virtual ~CubeHeure(void);

	/**
	 * Méthode surcharger de la classe mère Piece.
	 * Permet d'afficher la pièce dans la scène
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();
};
#endif
