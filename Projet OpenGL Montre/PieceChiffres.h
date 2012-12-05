#ifndef	PIECECHIFFRES_H
#define PIECECHIFFRES_H

#include "Include.h"
#include "Piece.h"
#include "Couleurs.h"

class PieceChiffres : public Piece
{
	float _taille;
	int _chiffre1;
	int _chiffre2;
	bool _unChiffre;
	bool _unNombre;
	Couleur *couleur;

public:
	PieceChiffres(float taille, int chiffre);
	PieceChiffres(float taille, int chiffre1, int chiffre2);
	virtual ~PieceChiffres(void);

	virtual void BuildAndDisplay();
	void DrawChiffre(int chiffre);

	void ChiffreZero();
	void ChiffreUn();
	void ChiffreDeux();
	void ChiffreTrois();
	void ChiffreQuatre();
	void ChiffreCinq();
	void ChiffreSix();
	void ChiffreSept();
	void ChiffreHuite();
	void ChiffreNeuf();

	void Chiffre(int chiffre);
	void Nombre(int chiffre1, int chiffre2);

};
#endif
