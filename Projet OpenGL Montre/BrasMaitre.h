#ifndef BRAS_MAITRE_H
#define BRAS_MAITRE_H

#include "Include.h"
#include "Piece.h"
#include "Disque.h"

class BrasMaitre : public Piece
{
	float _longueur;
	float _largeur;
	float _hauteur;
	float _diametre;

	Disque* _disque;
public:
	BrasMaitre(float longueur, float largeur, float hauteur, float diametre);
	~BrasMaitre(void);

	virtual void BuildAndDisplay();
};

#endif