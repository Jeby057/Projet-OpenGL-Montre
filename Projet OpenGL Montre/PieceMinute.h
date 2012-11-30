#ifndef	PIECEMINUTE_H
#define PIECEMINUTE_H

#include "Include.h"
#include "Piece.h"
#include "PartialCylinder.h"
#include "PPMImage.h"

class PieceMinute : public Piece
{
	float _taille;
	Couleur *couluer;
	GLuint _faceTexture[1];
public:
	PieceMinute(float taille);
	virtual ~PieceMinute(void);

	virtual void BuildAndDisplay();
	void LoadTexture();

	void PlaqueMinute();
	void Tiges(float l);
};

#endif
