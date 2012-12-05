/**
 * Classe CacheEngrenage
 * *********************
 *  Le cache engrennage est utilisé en bout des bras maitre.
 *  Il permet de cacher la partie de l'engrenange pour une meilleure lecture des heures
 * 
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 29 novembre 2012
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

	// Nombre de faces pour le diamètre
	int _slices;

	// hauteur de la pièce
	float _height;

	// Angle nescessaire pour le cache
	int _angle;

	// Hauteur de la jupe, laissé de coté de l'engrenage
	float _hjupe;

	// Largeur de la jupe, bordure supplémentaire, par rapport au diamètre
	float _ljupe;

	// Disque partiel permettant la sous pièce du cache
	PartialDisque* partialDisqueInterne;

public:
	/**
	 * Constructeur de CacheEngrenage
	 * diametreInterne : Diametre laissé pour le rotor
	 * diametreExterne : Diametre du cache
	 * slices : nombre de facettes
	 * height : Hauteur du cache
	 * angle : Angle de construction du cache
	 * hjupe : Hauteur de la jupe, en supplément
	 * ljupe : largeur de la jupe en supplément
	 */
	CacheEngrenage(float diametreInterne, float diametreExterne, int slices, float height, int angle, float hjupe, float ljupe);

	virtual ~CacheEngrenage(void);

	virtual void BuildAndDisplay();
};
#endif
