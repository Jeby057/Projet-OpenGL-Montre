/**
 * Classe PPMImage
 * ***********************
 * Permet de charger une image PPM depuis un fichier
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 2 D�cembre 2012
 * Version : 1
 */
#ifndef _PPM_IMAGE_H
#define _PPM_IMAGE_H

#include "Include.h"

class PPMImage
{

	// Taille (Width, Height) de l'image
	int _sizeX, _sizeY;

	// Donn�es (en bytes) de l'images
	GLubyte *_data;

public:
	/**
	 * Constructeur de l'image
	 * fichier : Chemin vers le fichier
	 */
	PPMImage(char *fichier);

	/**
	 * Detruit les donn�es de l'image
	 */
	virtual ~PPMImage(void);

	/**
	 * Charge en m�moire l'image de puis le fichier donn�e en param�tre
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
	 * Retourne les donn�es de l'image
	 */
	GLubyte* GetImage();
};
#endif
