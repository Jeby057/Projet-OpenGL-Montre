/**
 * Classe Engrenage
 * ****************
 * Permet de construire une pièce en forme d'engrenage
 * L'engrenage respecte la construction standard
 * 
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 29 novembre 2012
 * Version : 1
 */
#ifndef ENGRENAGE_H
#define ENGRENAGE_H

#include "Piece.h"
#include "Utilitaire.h"
#include "PPMImage.h"

class Engrenage : public Piece
{
	// Module de l'engrenage
	double _module;

	// Diametre de travail de l'engrenage
	double _diametreTravail;

	// longueur d'une dent de l'engrenage
	double _longueur;

	// Coté d'un carré de l'engrenage (deprecated)
	double _coteCarre;

	// Nombre de dents de l'engrenage
	// Auto calculé en fonction du module et du diametre
	int _nbDents;

public:
	/**
	 * Constructeur d'un engrenage
	 * module : Module de l'engrenage
	 * diametreTravail : Diamtre de travail
	 * longueur : Longueur d'une dent
	 * coteCarre : coté d'une dent (deprecated)
	 */
	Engrenage(double module, double diametreTravail, double longueur, double coteCarre);

	virtual ~Engrenage(void);

	virtual void BuildAndDisplay(); 
};
#endif
