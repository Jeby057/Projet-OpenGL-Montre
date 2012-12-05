/**
 * Classe CubeHeure
 * ****************
 * Cette classe construit les cubes qui indique l'heure dans la montre (que l'heure par les minutes et les secondes) .
 * Le construction de la pièce dessine un cube au centre du monde.
 * Le cube est constitué de 4 faces, sur chaque face il y a un chiffre allant de 1 à 12 en 3 fois car 3 cubes à la fin (4 x 3 : 1-4-7-10, 2-5-8-11, 3-6-9-12).
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
	 * Taille de la pièce
	 * A partir de cette variable, on fait des traitements pour calculer la heuteur, la largeur et l'epaisseur de la piece
	 */
	float _taille;

	/**
	 * Tableau des textures des faces de cube
	 * Le cube affiche 4 chiffres, donc il a besoin de 4 textures, les deux autres sont necessaires pour dessiner l'interieur de cube et ces bordures
	 * Les textures chargées sont des images de type PPM, c-à-d : 24 bits.
	 */
	GLuint _faceTexture[6];

public:
	/**
	 * Constructeur de la classe
	 * Il initialise la taille du cube
	 * Il charge les textures nécessaires pour le cube
	 * Il demande deux paramètres :
	 * @taille : taille du cube
	 * @namFace : un tableau de chaîne de caractères portant les noms des texture à charger
	 */
	CubeHeure(float taille, char* namFace[6]);

	/**
	 * Destruction de la montre
	 * Désallocation de tous les composants
	 */
	virtual ~CubeHeure(void);

	/**
	 * Méthode surchargée de la classe mère Piece.
	 * Permet d'afficher la pièce dans la scène
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();
};
#endif
