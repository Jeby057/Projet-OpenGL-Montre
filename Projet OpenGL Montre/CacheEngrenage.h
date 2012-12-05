#ifndef CACHE_ENGRENAGE_H
#define CACHE_ENGRENAGE_H

#include "Include.h"
#include "Piece.h"
#include "PartialDisque.h"

class CacheEngrenage : public Piece
{
	float _diametreInterne;
	float _diametreExterne;
	int _slices;
	float _height;
	int _angle;
	float _hjupe;
	float _ljupe;

	PartialDisque* partialDisqueInterne;

public:
	CacheEngrenage(float diametreInterne, float diametreExterne, int slices, float height, int angle, float hjupe, float ljupe);
	virtual ~CacheEngrenage(void);
	virtual void BuildAndDisplay();
};
#endif
