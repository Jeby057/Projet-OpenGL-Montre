/**
 * Classe CubeHeure
 * ****************
 * Cette classe construit les cubes qui indique l'heure dans la montre (que l'heure par les minutes et les secondes) .
 * Le construction de la pi�ce dessine un cube au centre du monde.
 * Le cube est constitu� de 4 faces, sur chaque face il y a un chiffre allant de 1 � 12 en 3 fois car 3 cubes � la fin (4 x 3 : 1-4-7-10, 2-5-8-11, 3-6-9-12).
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
	 * Taille de la pi�ce
	 * A partir de cette variable, on fait des traitements pour calculer la heuteur, la largeur et l'epaisseur de la piece
	 */
	float _taille;

	/**
	 * Tableau des textures des faces de cube
	 * Le cube affiche 4 chiffres, donc il a besoin de 4 textures, les deux autres sont necessaires pour dessiner l'interieur de cube et ces bordures
	 * Les textures charg�es sont des images de type PPM, c-�-d : 24 bits.
	 */
	GLuint _faceTexture[6];

public:
	/**
	 * Constructeur de la classe
	 * Il initialise la taille du cube
	 * Il charge les textures n�cessaires pour le cube
	 * Il demande deux param�tres :
	 * @taille : taille du cube
	 * @namFace : un tableau de cha�ne de caract�res portant les noms des texture � charger
	 */
	CubeHeure(float taille, char* namFace[6]);

	/**
	 * Destruction de la montre
	 * D�sallocation de tous les composants
	 */
	virtual ~CubeHeure(void);

	/**
	 * M�thode surcharg�e de la classe m�re Piece.
	 * Permet d'afficher la pi�ce dans la sc�ne
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();
};
#endif
