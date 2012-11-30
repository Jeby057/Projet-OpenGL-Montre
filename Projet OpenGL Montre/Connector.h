#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "piece.h"
class Connector : public Piece
{
	float _base, _height;
public:
	Connector(float base, float height);
	virtual void BuildAndDisplay();
	virtual ~Connector(void);
};

#endif
