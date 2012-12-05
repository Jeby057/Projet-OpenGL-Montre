/**
 * Classe PlaqueSeparation
 * ***********************
 * Pi�ce permettant de s�par� la partie sup�rieure et la partie inf�rieure de la montre
 * Permet aussi d'appliquer un fond avec une texture
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 2 D�cembre 2012
 * Version : 1
 */
#ifndef	PL_SEPARATION_H
#define PL_SEPARATION_H

#include "piece.h"
class PlaqueSeparation :
	public Piece
{
	// _hauteur : Hauteur de la plaque
	// _largeur : Largeur de la plaque
	// _longueur : Longueur de la plaque
	// _txReduction : Permet de r�duire le rectangle d'un certain taux le cot� de droite 
	float _hauteur, _largeur, _longueur, _txReduction;

	// Diff�rents fond d'�cran utilisables
	GLuint *_faceTexture;

	// Texture courante
	GLuint _texture;
public:

	/**
	 * Constructeur PlaqueSeparation
	 * hauteur : Hauteur de la plaque
	 * largeur : Largeur de la plaque
	 * txReduction : Taux de largeur pour d�marrer la coupe
	 * texture : Tableau des textures
	 * nbTextures : Nombre de textures
	 */
	PlaqueSeparation(float hauteur, float largeur, float longueur, float txReduction, char** texture, int nbTextures);

	virtual ~PlaqueSeparation();

	/**
	 * Construit l'objet
	 */
	virtual void BuildAndDisplay();

	/**
	 * Surcharg� pour modifier la texture
	 */
	virtual void FastDisplay();

	/**
	 * Modifie la texture courante
	 * id : L'identifiant de la nouvelle texture
	 */
	void SetTexture(int id);

private:
	/**
	 * Permet de construire une face de la plaque
	 * h : hauteur de position
	 */
	void BuildPattern(float h);
};
#endif
