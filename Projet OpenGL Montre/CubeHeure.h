#ifndef CUBEHEURE_H
#define CUBEHEURE_H

#include "Include.h"
#include "Piece.h"
#include "PPMImage.h"

class CubeHeure : public Piece
{
	float _posX;
	float _posY;
	float _posZ;
	float angleRotation;
	float temps;

	//les face de cube
	GLuint _faceTexture[6];

public:
	CubeHeure(float x, float y, float z);
	virtual ~CubeHeure(void);

	virtual void Build();
	void idle();

	void LoadTexture(char* face[6]);
};

#endif