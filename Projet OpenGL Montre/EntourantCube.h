#ifndef ENTOUR_CUBE_H
#define ENTOUR_CUBE_H

#include "Piece.h"

class EntourantCube : public Piece
{
private:
	//////////// param�tres entrants

	double _largeurG; // largeur de la pi�ce � gauche
	double _longCoinG; // longueur des coins � gauche
	double _longHaut; // longueur de la partie haute � gauche
	double _epaissG; // �paisseur de la pi�ce � gauche
	double _epaissD; // �paisseur de la pi�ce � droite
	double _hauteur; // hauteur de la pi�ce (en profondeur)

	double _longNiveau; // longueur du changement de niveau (milieu)
	double _longBas; // longueur de la partie basse (milieu)
	
	double _prcLargPoseTri; // pourcentage pris par la largeur de l'emplacement o� est pos� l'indicateur des minutes

	//////////// autres variables locales

	double _largeurD; // largeur des faces du niveau bas � droite

	double _angleCoinG; // angle du coin de gauche
	double _angleNiveau; // angle du changement de niveau au milieu
	double _angleInvNiveau; // angle du changement de niveau � droite

	double _prctLargD; // pourcentage de la largeur des faces du niveau bas � droite (sur le reste de la largeur apr�s soustraction de la largeur de l'emplacement o� est pos� l'indicateur des minutes

public:
	EntourantCube(double largeurG, double longCoinG, double longHaut, double epaissG, double epaissD, double longNiveau,
		double longBas, double prcLargPoseTri, double hauteur);
	virtual ~EntourantCube(void);

	virtual void BuildAndDisplay();
};
#endif
