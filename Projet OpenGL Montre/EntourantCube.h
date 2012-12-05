#ifndef ENTOUR_CUBE_H
#define ENTOUR_CUBE_H

#include "Piece.h"

class EntourantCube : public Piece
{
private:
	//////////// paramètres entrants

	double _largeurG; // largeur de la pièce à gauche
	double _longCoinG; // longueur des coins à gauche
	double _longHaut; // longueur de la partie haute à gauche
	double _epaissG; // épaisseur de la pièce à gauche
	double _epaissD; // épaisseur de la pièce à droite
	double _hauteur; // hauteur de la pièce (en profondeur)

	double _longNiveau; // longueur du changement de niveau (milieu)
	double _longBas; // longueur de la partie basse (milieu)
	
	double _prcLargPoseTri; // pourcentage pris par la largeur de l'emplacement où est posé l'indicateur des minutes

	//////////// autres variables locales

	double _largeurD; // largeur des faces du niveau bas à droite

	double _angleCoinG; // angle du coin de gauche
	double _angleNiveau; // angle du changement de niveau au milieu
	double _angleInvNiveau; // angle du changement de niveau à droite

	double _prctLargD; // pourcentage de la largeur des faces du niveau bas à droite (sur le reste de la largeur après soustraction de la largeur de l'emplacement où est posé l'indicateur des minutes

public:
	EntourantCube(double largeurG, double longCoinG, double longHaut, double epaissG, double epaissD, double longNiveau,
		double longBas, double prcLargPoseTri, double hauteur);
	virtual ~EntourantCube(void);

	virtual void BuildAndDisplay();
};
#endif
