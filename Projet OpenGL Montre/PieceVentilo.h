#ifndef	PIECEVENTILO_H
#define PIECEVENTILO_H

#include "Include.h"
#include "Piece.h"

class PieceVentilo : public Piece
{
	float _diametreInterieur;
	float _diametreExterieur;
	float _hauteur;
	float _taille;
	Couleur *couluer;
public:
	PieceVentilo(float diametreInterieur, float diametreExterieur, float hauteur);
	~PieceVentilo(void);

	virtual void BuildAndDisplay();

	void PiecePartielle();
	void Cube(float x, float y, float z, float decalageX);
	void Tige();
	void Cuve();
};

#endif
