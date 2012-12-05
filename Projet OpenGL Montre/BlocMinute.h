/**
 * Classe BlocMinute
 * *****************
 *  Cette pièce permet d'afficher la pièce en forme d'arc de cercle pour afficher les minutes
 *  Elle se construit sur 120 degré autour du rayon donné
 * 
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 29 novembre 2012
 * Version : 1
 */
#ifndef BLOC_MINUTE_H
#define BLOC_MINUTE_H

#include "Include.h"
#include "Piece.h"

class BlocMinute :public Piece
{
	/**
	 * Rayon : Rayon de construction
	 * LargBase / LongBase : La base correspond à la grande partie de gauche (largeur / longueur)
	 * LargBras / LongBras : Les bras sont les décrauchements haut et bas de la pièce
	 * hauteur : Epaisseur de la pièce
	 */
	float _rayon, _largBase, _longBase, _largBras, _longBras, _hauteur;

public:
	/**
	 * Constructeur de BlocMinute
	 * rayon : Rayon de construction
	 * largbase : Largeur de la base
	 * longbase : Longueur de la base
	 * largBras : largeur de la base
	 * LongBras : Longueur du bras
	 * hauteur : Epaisseur max de la pièce
	 */
	BlocMinute(float rayon, float largBase, float longBase, float largBras, float longBras, float hauteur);


	virtual ~BlocMinute(void);
	virtual void BuildAndDisplay();
};
#endif
