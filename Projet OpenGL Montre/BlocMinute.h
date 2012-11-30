#pragma once
#include "Include.h"
#include "Piece.h"

class BlocMinute :public Piece
{
	float _rayon, _largBase, _longBase, _largBras, _longBras, _hauteur;

public:
	BlocMinute(float rayon, float largBase, float longBase, float largBras, float longBras, float hauteur);
	virtual ~BlocMinute(void);
	virtual void BuildAndDisplay();
};

