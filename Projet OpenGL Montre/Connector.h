/**
 * Classe Connector
 * ****************
 * Petite pièce de décoration permettant la connection d'un rotor à une surface
 * 
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 29 novembre 2012
 * Version : 1
 */
#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "piece.h"
class Connector : public Piece
{
	// Base : Largeur de la base du cone
	// Height : Hauteur du cone
	float _base, _height;
public:

	/**
	 * base : Largeur de la base 
	 * height : hauteur du cone
	 */
	Connector(float base, float height);

	virtual void BuildAndDisplay();

	virtual ~Connector(void);
};
#endif

