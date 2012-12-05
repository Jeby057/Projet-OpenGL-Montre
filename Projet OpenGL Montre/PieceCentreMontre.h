/**
 * Classe PieceCentreMontre
 * ************************
 * Cette classe construit une pièce qui sera posée au centre de la montre
 * Cette piece sert uniquement à la décoration, elle ne donne aucune information utile
 * Elle est constituée de 3 sous-pièces identiques
 * Elle sera repositionnée par la suite selon l'emplacement souhaité.
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 21 Novembre 2012
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
	 * C'est à partir de cette variable qu'on calcule les dimensions de la pièce : largeur et epaisseur
	 */
	float _taille;

	/**
	 * Hauteur de la pièce
	 * Cette variable est necessaire pour parametrer la hauteur de la piece
	 */
	float _hauteur;

public:

	/**
	 * Constructeur de la pièce
	 * Ce constructeur dessine une pièce au centre de la scène
	 * Il initialise les variables de la classe
	 * Il demande deux paramètres : 
	 * @taille : taille de la piece
	 * @hauteur : hauteur de la piece
	 */
	PieceCentreMontre(float taille, float hauteur);

	
	/**
	 * Destruction de la montre
	 * Désallocation de tous les composants
	 */
	virtual ~PieceCentreMontre(void);

	/**
	 * Méthode surchargée de la classe mère Piece.
	 * Permet d'afficher la pièce dans la scène
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * Méthode PiecePartielle
	 * Cette méthode dessine une piece spéciale qui va être utilisée pour dessiner la piece souhaitée
	 * en bouclant 3 fois sur cette pièce on construit notre pièce finale
	 */
	void PiecePartielle();
};
#endif
