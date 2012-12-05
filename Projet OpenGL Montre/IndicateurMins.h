/**
 * Classe IndicateurMins
 * *********************
 * Construit la pi�ce triangulaire, pos�e � droite sur l'entourant Cube, qui indique les minutes sur la pi�ce courb�e � droite dans la montre
 * C'est en fait une pyramide tronqu�e dont le fond est plat jointe � un parall�lepip�de rectangle (� gauche) (sommet de la pyramide � droite)
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 */

#ifndef INDICATEURMINS_H
#define INDICATEURMINS_H

#include "Piece.h"

class IndicateurMins : public Piece
{
private:

	// donn�es membres
	double _largSocle; // largeur du socle � gauche (sur z)
	double _epaissSocle; // �paisseur du socle (sur x)
	double _hauteurSocle; // hauteur du socle (sur y)
	double _hauteurPyram; // hauteur de la pyramide tronqu�e (face couch�e sur le plan xz)
	double _largSmt; // largeur du sommet (sur z)
	double _hauteurSmt; // hauteur du sommet (sur y)

public:
	/**
	 * Constructeur de l'indicateur minute
	 * Les param�tres entrants sont les donn�es membres
	 */
	IndicateurMins(double largSocle, double epaissSocle, double hauteurSocle, double hauteurPyram, double largSmt, double hauteurSmt);

	/**
	 * Destructeur
	 */
	virtual ~IndicateurMins(void);

	/**
	 * Charge les composants en m�moire
	 */
	virtual void BuildAndDisplay();
};
#endif
