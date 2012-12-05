/**
 * Classe Disque partiel
 * ***********************
 *  Permet de construire un disque partiel
 *  La piece correspond à un cylindre partielle, avec les faces de haut et bas
 *  Permet aussi de spécifier un rayon intérieur pour trouer la piece
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 29 novembre 2012
 * Version : 1
 */
#ifndef DISQUE_H
#define DISQUE_H
#include "Include.h"
#include "Piece.h"
#include "PartialCylinder.h"

class PartialDisque : public Piece
{
	// Diametre interieur et exterieur
	float _diametreInterieur, _diametreExterieur;

	// Hauteur de disque
	float _height;

	// Nombre de facettes
	int _slices;

	// Angle laissé par la coupure
	float _angle;

	// Cylindre partielle
	PartialCylinder* _cylExtPartiel;

public:
	/**
	 * Constructeur d'un disque partiel
	 * diametreInterieur : Diametre intérieur laissé pour trouer la piece (0 pour aucun trou)
	 * diametreExterieur : Diametre exeterieur
	 * height : Hauteur du disque
	 * slices : Nombre de facettes
	 * angle : Angle de coupure (en degré)
	 */
	PartialDisque(float diametreInterieur, float diametreExterieur, float height, int slices, float angle);

	virtual ~PartialDisque(void);

	void BuildAndDisplay();
};
#endif
