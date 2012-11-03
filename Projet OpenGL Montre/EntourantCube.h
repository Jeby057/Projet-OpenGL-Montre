#ifndef ENTOUR_CUBE_H
#define ENTOUR_CUBE_H

#include "Piece.h"

class EntourantCube : public Piece
{
private:
	double _largeurG;
	double _longCoinG;
	double _longHaut;
	double _epaissG;
	double _epaissD;
	double _hauteur;

	double _longNiveau;
	double _longBas;
	
	double _prcLargPoseTri;
	double _largeurD;

	double _angleCoinG;
	double _angleNiveau;
	double _angleInvNiveau;

	double _prctLargD;

public:
	EntourantCube(double largeurG, double longCoinG, double longHaut, double epaissG, double epaissD, double longNiveau,
		double longBas, double prcLargPoseTri, double hauteur);
	virtual ~EntourantCube(void);

	virtual void Build();
};

#endif