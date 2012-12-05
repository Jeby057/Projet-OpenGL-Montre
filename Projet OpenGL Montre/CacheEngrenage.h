/**
 * Classe CacheEngrenage
 * *********************
 *  Le cache engrennage est utilis� en bout des bras maitre.
 *  Il permet de cacher la partie de l'engrenange pour une meilleure lecture des heures
 * 
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 29 novembre 2012
 * Version : 1
 */
#ifndef CACHE_ENGRENAGE_H
#define CACHE_ENGRENAGE_H

#include "Include.h"
#include "Piece.h"
#include "PartialDisque.h"

class CacheEngrenage : public Piece
{
	// Diametre du rotor
	float _diametreInterne;

	// Diametre du disque
	float _diametreExterne;

	// Nombre de faces pour le diam�tre
	int _slices;

	// hauteur de la pi�ce
	float _height;

	// Angle nescessaire pour le cache
	int _angle;

	// Hauteur de la jupe, laiss� de cot� de l'engrenage
	float _hjupe;

	// Largeur de la jupe, bordure suppl�mentaire, par rapport au diam�tre
	float _ljupe;

	// Disque partiel permettant la sous pi�ce du cache
	PartialDisque* partialDisqueInterne;

public:
	/**
	 * Constructeur de CacheEngrenage
	 * diametreInterne : Diametre laiss� pour le rotor
	 * diametreExterne : Diametre du cache
	 * slices : nombre de facettes
	 * height : Hauteur du cache
	 * angle : Angle de construction du cache
	 * hjupe : Hauteur de la jupe, en suppl�ment
	 * ljupe : largeur de la jupe en suppl�ment
	 */
	CacheEngrenage(float diametreInterne, float diametreExterne, int slices, float height, int angle, float hjupe, float ljupe);

	virtual ~CacheEngrenage(void);

	virtual void BuildAndDisplay();
};
#endif
