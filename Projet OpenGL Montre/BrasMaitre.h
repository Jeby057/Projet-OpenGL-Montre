/**
 * Classe BrasMaitre
 * *****************
 *  Le bras maitre correspond � une sous pi�ce de la pi�ce maitresse
 *  Cette pi�ce correspond aux 3 bras donnant sur les cubes heures
 * 
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 29 novembre 2012
 * Version : 1
 */
#ifndef BRAS_MAITRE_H
#define BRAS_MAITRE_H

#include "Include.h"
#include "Piece.h"
#include "PartialDisque.h"
#include "CacheEngrenage.h"

class BrasMaitre : public Piece
{
	// Longueur du bras
	float _longueur;

	// Largeur du bras
	float _largeur;

	// Hauteur du bras
	float _hauteur;

	// Diam�tre du bras
	float _diametre;
	
	// Correspond � l'angle donn�e au disque de support du bras
	// Le disque est tronqu�, pour pouvoir laisser pass� cube de l'heure
	int _angle;

	// Disque partielle d'angle "_angle", permettant le support du cube heure
	PartialDisque* _disque;
public:

	/**
	 * Constructeur BrasMaitre
	 * longueur : longueur du bras
	 * largeur : largeur du bras
	 * hauteur : hauteur du bras
	 * diametre : diametre du bras
	 */
	BrasMaitre(float longueur, float largeur, float hauteur, float diametre);

	~BrasMaitre(void);

	virtual void BuildAndDisplay();
};
#endif
