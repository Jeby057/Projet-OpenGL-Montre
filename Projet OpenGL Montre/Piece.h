#ifndef PIECE_H
#define PIECE_H

#include "Include.h"

class Piece
{
public:
	Piece(void);
	virtual ~Piece(void);

	virtual void Build() = 0;
};

#endif