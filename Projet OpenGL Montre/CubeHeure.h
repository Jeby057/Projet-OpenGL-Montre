#ifndef CUBEHEURE_H
#define CUBEHEURE_H

#include "Include.h"
#include "Piece.h"
class CubeHeure : public Piece
{
	float _taille;

	float angleRotation;
	float temps;

	//les face de cube
	GLuint _faceTexture[6];

public:
	CubeHeure(float taille, char* namFace[6]);
	virtual ~CubeHeure(void);

	virtual void BuildAndDisplay();
	void idle();

};

#endif