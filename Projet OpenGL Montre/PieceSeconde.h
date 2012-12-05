#ifndef	PIECESECONDE_H
#define PIECESECONDE_H

#include "Include.h"
#include "Piece.h"
#include "PPMImage.h"
#include "Couleurs.h"

class PieceSeconde : public Piece
{
	float _rayon;
	float _epaisseur;

public:
	PieceSeconde(float rayon, float epaisseur);
	virtual ~PieceSeconde(void);

	virtual void BuildAndDisplay();
	void Cube();
};
#endif
