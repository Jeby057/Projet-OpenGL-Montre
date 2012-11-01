#ifndef MAITRESSE_H
#define MAITRESSE_H
#include "Piece.h"

class Maitresse : Piece
{
public:
	Maitresse(void);
	virtual ~Maitresse(void);
	virtual void Build();
};

#endif