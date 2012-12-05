/**
 * Classe EntourantCube
 * ********************
 * Construit la pi�ce complexe qui entoure un cube qui indique l'heure
 * Ressemble � un hexagone (�pais) � deux niveaux, on pose la pi�ce triangulaire (fl�che) qui indique les minutes
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 */

#ifndef ENTOUR_CUBE_H
#define ENTOUR_CUBE_H

#include "Piece.h"

class EntourantCube : public Piece
{
private:
	// donn�es membres : param�tres entrants

	double _largeurG; // largeur de la pi�ce � gauche
	double _longCoinG; // longueur des coins � gauche
	double _longHaut; // longueur de la partie haute � gauche
	double _epaissG; // �paisseur de la pi�ce � gauche
	double _epaissD; // �paisseur de la pi�ce � droite
	double _hauteur; // hauteur de la pi�ce (en profondeur)

	double _longNiveau; // longueur du changement de niveau (milieu)
	double _longBas; // longueur de la partie basse (milieu)
	
	double _prcLargPoseTri; // pourcentage pris par la largeur de l'emplacement o� est pos� l'indicateur des minutes

	/// autres donn�es membres

	double _largeurD; // largeur des faces du niveau bas � droite

	double _angleCoinG; // angle du coin de gauche
	double _angleNiveau; // angle du changement de niveau au milieu
	double _angleInvNiveau; // angle du changement de niveau � droite

	double _prctLargD; // pourcentage de la largeur des faces du niveau bas � droite (sur le reste de la largeur apr�s soustraction de la largeur de l'emplacement o� est pos� l'indicateur des minutes

public:
	/**
	 * Construction de l'objet Entourant Cube
	 * Les param�tre entrants indiqu�s dans les donn�es membres
	 */
	EntourantCube(double largeurG, double longCoinG, double longHaut, double epaissG, double epaissD, double longNiveau,
		double longBas, double prcLargPoseTri, double hauteur);

	/**
	 * Destructeur
	 */
	virtual ~EntourantCube(void);

	/**
	 * Charge les composants en m�moire
	 */
	virtual void BuildAndDisplay();
};
#endif
