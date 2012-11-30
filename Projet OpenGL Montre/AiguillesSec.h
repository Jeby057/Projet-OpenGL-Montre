#ifndef AIGUILLES_SEC_H
#define AIGUILLES_SEC_H

#include "Piece.h"
#include "Couleurs.h"

class AiguillesSec : public Piece
{
private:
	float _longueur;
	float _rayon;
	float _epaiss;

	Point3D * _aiguilleG;
	Point3D * _aiguilleD;
	Couleur * couleur;
public:
	AiguillesSec(float longueur, float rayon, float epaiss);
	virtual ~AiguillesSec(void);

	virtual void BuildAndDisplay();

	void ConstrAig(Point3D * aiguille, float longPic);
};

#endif