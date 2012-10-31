#ifndef ENGRENAGE_H
#define ENGRENAGE_H

#include "Piece.h"

class Engrenage : public Piece
{
	double _module;
	double _diametreTravail;
	double _longueur;
	double _coteCarre;
	int _nbDents;

public:
	Engrenage(double module, double diametreTravail, double longueur, double coteCarre);
	virtual ~Engrenage(void);

	virtual void Build(); 
};

#endif