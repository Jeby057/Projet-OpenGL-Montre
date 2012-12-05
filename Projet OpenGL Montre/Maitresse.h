/**
 * Classe Maitresse
 * ****************
 * Pi�ce maitresse en 3 bras de la montre.
 * Permet de maintenir les bras tenant les cubes des heures
 * 
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 29 novembre 2012
 * Version : 1
 */
#ifndef MAITRESSE_H
#define MAITRESSE_H
#include "Piece.h"
#include "BrasMaitre.h"

class Maitresse : public Piece
{
	// Longueur du bras
	float _hBras;

	// Marge entre le bras et l'espace engrenage
	float _hMargeBrasEspace;

	// Marge autour de la pi�ce maitresse
	float _hEspace;

	// Hauteur du paral�pip�de central
	float _hBase;

	// Marge enterieur du paral�pip�de
	float _margeExt;

	// epaisseur de la pi�ce
	float _epaisseur;

	// Longueur du bras
	float _longueurBras;

	// Diametre du disque du bras 
	float _diametreRotBras;

	// Bras maitre
	BrasMaitre *_brasMaitre;

public:
	/**
	 * hbras : Longueur du bras
	 * hMargeBrasEspace : marge entre le bras et l'espace engrenage
	 * hEspace : espace de l'engrenage
	 * hBase : largeur de la base (en partant du point central)
	 * epaisseur : epaisseur de la pi�ce
	 * longueurBras : longueur du bras maitre
	 * diametreRotBras : diametre du disque du bras maitre
	 */
	Maitresse(float hBras, float hMargeBrasEspace, float hEspace, float hBase, float epaisseur, float longueurBras, float diametreRotBras);
	virtual ~Maitresse(void);
	virtual void BuildAndDisplay();
};
#endif
