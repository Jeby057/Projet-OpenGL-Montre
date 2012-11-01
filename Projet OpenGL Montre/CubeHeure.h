#ifndef CUBEHEURE_H
#define CUBEHEURE_H

#include "Include.h"
#include "Piece.h"

class CubeHeure : public Piece
{
	float _posX;
	float _posY;
	float _posZ;
	float angleRotation;
	float temps;

public:
	CubeHeure(float x, float y, float z);
	virtual ~CubeHeure(void);

	virtual void Build();
	void idle();
};

#endif