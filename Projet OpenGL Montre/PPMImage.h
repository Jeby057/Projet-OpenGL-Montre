/**
 * Classe PPMImage
 * ***********************
 * Permet de charger une image PPM depuis un fichier
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 2 Décembre 2012
 * Version : 1
 */
#ifndef _PPM_IMAGE_H
#define _PPM_IMAGE_H

#include "Include.h"

class PPMImage
{

	// Taille (Width, Height) de l'image
	int _sizeX, _sizeY;

	// Données (en bytes) de l'images
	GLubyte *_data;

public:
	/**
	 * Constructeur de l'image
	 * fichier : Chemin vers le fichier
	 */
	PPMImage(char *fichier);

	/**
	 * Detruit les données de l'image
	 */
	virtual ~PPMImage(void);

	/**
	 * Charge en mémoire l'image de puis le fichier donnée en paramètre
	 * fichier : Chemin vers le fichier
	 */
	virtual void Load(char *fichier);

	/** 
	 * Retourne la largeur de l'image
	 */
	int GetSizeX();

	/** 
	 * Retourne la longueur de l'image
	 */
	int GetSizeY();

	/** 
	 * Retourne les données de l'image
	 */
	GLubyte* GetImage();
};
#endif
