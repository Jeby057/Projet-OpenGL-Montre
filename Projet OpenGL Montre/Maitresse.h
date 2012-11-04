#ifndef MAITRESSE_H
#define MAITRESSE_H
#include "Piece.h"
#include "BrasMaitre.h"

class Maitresse : public Piece
{
	float _hBras;
	float _hMargeBrasEspace;
	float _hEspace;
	float _hBase;
	float _margeExt;
	float _epaisseur;
	float _longueurBras;
	float _diametreRotBras;
	BrasMaitre *_brasMaitre;

public:
	Maitresse(float hBras, float hMargeBrasEspace, float hEspace, float hBase, float epaisseur, float longueurBras, float diametreRotBras);
	virtual ~Maitresse(void);
	virtual void BuildAndDisplay();
};

#endif