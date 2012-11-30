#ifndef	PIECECENTREMONTRE_H
#define PIECECENTREMONTRE_H

#include "Include.h"
#include "Piece.h"
class PieceCentreMontre : public Piece
{
	float _taille, _hauteur;
	Couleur *couleur;

public:
	PieceCentreMontre(float taille, float hauteur);
	virtual ~PieceCentreMontre(void);

	virtual void BuildAndDisplay();
	void PiecePartielle();
};

#endif