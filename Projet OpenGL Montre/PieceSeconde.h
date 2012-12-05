/**
 * Classe PieceSeconde
 * *************
 * Cette classe construit le cadrant des seconde
 * Elle est constituer d'une cylendre ainsi que de 12 tiges tout au tours
 * Cette piece permet d'indiquer les seconde de la montre
 * Elle sera repositionnée par la suite selon l'emplacement souhaité.
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 25 Décembre 2012
 * Version : 1
 */

#ifndef	PIECESECONDE_H
#define PIECESECONDE_H

#include "Include.h"
#include "Piece.h"
#include "PPMImage.h"
#include "Couleurs.h"

class PieceSeconde : public Piece
{
	/**
	 * Le rayon de cylendre des seconde
	 */
	float _rayon;

	/**
	 * L'epaisseur de cylendre ainsi que des tige qui contitue les secondes
	 */
	float _epaisseur;

public:

	
	/**
	 * Constructeur de la piece seconde
	 * Ce constructeur dessine le cylendre et les tiges au centre de la scène
	 * Il initialise les variable de la classe
	 * Il demande deux paramettres : 
	 * @rayon : le rayon de la piece
	 * @epesseur : l'epesseur de la piece
	 */
	PieceSeconde(float rayon, float epaisseur);

	/**
	 * Destruction de la montre
	 * Désalocation de tous les composants
	 */
	virtual ~PieceSeconde(void);

	/**
	 * Méthode surcharger de la classe mère Piece.
	 * Permet d'afficher la pièce dans la scène
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * Méthode Tige
	 * cette mithode dessine une tige, par la suite elle va etre utilser pour dessiner les 12 autre tout au tour de cylendre
	 */
	void Tige();
};
#endif
