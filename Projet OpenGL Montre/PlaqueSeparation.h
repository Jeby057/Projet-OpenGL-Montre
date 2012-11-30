#pragma once
#include "piece.h"
class PlaqueSeparation :
	public Piece
{
	float _hauteur, _largeur, _longueur, _txReduction;
	GLuint *_faceTexture, _texture;
public:
	PlaqueSeparation(float hauteur, float largeur, float longueur, float txReduction, char** texture, int nbTextures);
	virtual ~PlaqueSeparation();

	virtual void BuildAndDisplay();
	virtual void FastDisplay();
	void SetTexture(int id);

private:
	void BuildPattern(float h);
};

