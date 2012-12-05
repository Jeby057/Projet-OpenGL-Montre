/**
 * Classe PieceCentreMontre
 * *************
 * Cette classe construit une piece qui sera poser au centre de la montre
 * Cette piece est la juste pour le décours, elle donne aucune information utile
 * Elle est constituer de 3 sous-piece identique
 * Elle sera repositionnée par la suite selon l'emplacement souhaité.
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 21 Décembre 2012
 * Version : 1
 */

#ifndef	PIECECENTREMONTRE_H
#define PIECECENTREMONTRE_H

#include "Include.h"
#include "Piece.h"
class PieceCentreMontre : public Piece
{
	/**
	 * Taille de la piece
	 * C'est à partir de cette variable qu'on calcule les dimension de la piece : largeur et epesseur
	 */
	float _taille;

	/**
	 * Hauteur de la piece
	 * cette variable est necessaire pour parametrer l'hauteur de la piece
	 */
	float _hauteur;

public:

	/**
	 * Constructeur de la piece
	 * Ce constructeur dessine une piece au centre de la scène
	 * Il initialise les variable de la classe
	 * Il demande deux paramettres : 
	 * @taille : taille de la piece
	 * @hauteur : hauteur de la piece
	 */
	PieceCentreMontre(float taille, float hauteur);

	
	/**
	 * Destruction de la montre
	 * Désalocation de tous les composants
	 */
	virtual ~PieceCentreMontre(void);

	/**
	 * Méthode surcharger de la classe mère Piece.
	 * Permet d'afficher la pièce dans la scène
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * Méthode PiecePartielle
	 * Cette méthode dessine une piece spécial qui va etre utiliser pour dessiner la piece souhaité
	 * en bouclant 3 fois sur cette piece on construit notre piece
	 */
	void PiecePartielle();
};
#endif
