#ifndef BRAS_MAITRE_H
#define BRAS_MAITRE_H

#include "Include.h"
#include "Piece.h"
#include "PartialDisque.h"
#include "CacheEngrenage.h"

class BrasMaitre : public Piece
{
	float _longueur;
	float _largeur;
	float _hauteur;
	float _diametre;
	int _angle;
	PartialDisque* _disque;
public:
	BrasMaitre(float longueur, float largeur, float hauteur, float diametre);
	~BrasMaitre(void);

	virtual void BuildAndDisplay();
};
#endif
