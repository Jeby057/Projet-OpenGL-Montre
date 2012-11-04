#ifndef DISQUE_H
#define DISQUE_H
#include "Include.h"
#include "Piece.h"
#include "PartialCylinder.h"

class Disque : public Piece
{

	float _diametreInterieur, _diametreExterieur;
	float _height;
	int _slices;
	float _angle;

	PartialCylinder* _cylExtPartiel;

public:
	Disque(float diametreInterieur, float diametreExterieur, float height, int slices, float angle);
	virtual ~Disque(void);

	void BuildAndDisplay();
};

#endif

