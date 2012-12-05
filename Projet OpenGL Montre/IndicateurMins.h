/**
 * Classe IndicateurMins
 * *********************
 * Construit la pièce triangulaire, posée à droite sur l'entourant Cube, qui indique les minutes sur la pièce courbée à droite dans la montre
 * C'est en fait une pyramide tronquée dont le fond est plat jointe à un parallélepipède rectangle (à gauche) (sommet de la pyramide à droite)
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 */

#ifndef INDICATEURMINS_H
#define INDICATEURMINS_H

#include "Piece.h"

class IndicateurMins : public Piece
{
private:

	// données membres
	double _largSocle; // largeur du socle à gauche (sur z)
	double _epaissSocle; // épaisseur du socle (sur x)
	double _hauteurSocle; // hauteur du socle (sur y)
	double _hauteurPyram; // hauteur de la pyramide tronquée (face couchée sur le plan xz)
	double _largSmt; // largeur du sommet (sur z)
	double _hauteurSmt; // hauteur du sommet (sur y)

public:
	/**
	 * Constructeur de l'indicateur minute
	 * Les paramètres entrants sont les données membres
	 */
	IndicateurMins(double largSocle, double epaissSocle, double hauteurSocle, double hauteurPyram, double largSmt, double hauteurSmt);

	/**
	 * Destructeur
	 */
	virtual ~IndicateurMins(void);

	/**
	 * Charge les composants en mémoire
	 */
	virtual void BuildAndDisplay();
};
#endif
