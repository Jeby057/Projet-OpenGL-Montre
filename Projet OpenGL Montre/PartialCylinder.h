#ifndef PARTIAL_CYLINDER_H
#define PARTIAL_CYLINDER_H
#include "Include.h"
#include "Piece.h"

class PartialCylinder : public Piece
{
	float _start;
	float _end;
	int _subdiv;
	float _radius;
	float _height;

public:
	PartialCylinder(float start, float end, int subdiv, float radius, float height);
	virtual ~PartialCylinder(void);

	virtual void BuildAndDisplay();
};
#endif
