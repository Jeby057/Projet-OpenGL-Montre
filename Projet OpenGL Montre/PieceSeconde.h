/**
 * Classe PieceSeconde
 * *******************
 * Cette classe construit le cadran des secondes
 * Elle est constituée d'un cylindre ainsi que de 12 tiges tout au tour
 * Cette piece permet d'indiquer les secondes de la montre
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
	 * Le rayon du cylindre des secondes
	 */
	float _rayon;

	/**
	 * L'epaisseur du cylindre ainsi que des tiges qui contituent les secondes
	 */
	float _epaisseur;

public:

	/**
	 * Constructeur de la piece seconde
	 * Ce constructeur dessine le cylindre et les tiges au centre de la scène
	 * Il initialise les variables de la classe
	 * Il demande deux paramètres :
	 * @rayon : le rayon de la piece
	 * @epaisseur : l'epaisseur de la piece
	 */
	PieceSeconde(float rayon, float epaisseur);

	/**
	 * Destruction de la montre
	 * Désallocation de tous les composants
	 */
	virtual ~PieceSeconde(void);

	/**
	 * Méthode surchargée de la classe mère Piece.
	 * Permet d'afficher la pièce dans la scène
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * Méthode Tige
	 * Cette méthode dessine une tige, par la suite elle va etre utilisée pour dessiner les 12 autres tout au tour du cylindre
	 */
	void Tige();
};
#endif
