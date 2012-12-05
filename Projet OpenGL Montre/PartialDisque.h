#ifndef DISQUE_H
#define DISQUE_H
#include "Include.h"
#include "Piece.h"
#include "PartialCylinder.h"

class PartialDisque : public Piece
{

	float _diametreInterieur, _diametreExterieur;
	float _height;
	int _slices;
	float _angle;

	PartialCylinder* _cylExtPartiel;

public:
	PartialDisque(float diametreInterieur, float diametreExterieur, float height, int slices, float angle);
	virtual ~PartialDisque(void);

	void BuildAndDisplay();
};
#endif
