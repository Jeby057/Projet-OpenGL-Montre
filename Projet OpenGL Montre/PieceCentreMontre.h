/**
 * Classe PieceCentreMontre
 * *************
 * Cette classe construit une piece qui sera poser au centre de la montre
 * Cette piece est la juste pour le d�cours, elle donne aucune information utile
 * Elle est constituer de 3 sous-piece identique
 * Elle sera repositionn�e par la suite selon l'emplacement souhait�.
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 21 D�cembre 2012
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
	 * C'est � partir de cette variable qu'on calcule les dimension de la piece : largeur et epesseur
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
	 * Ce constructeur dessine une piece au centre de la sc�ne
	 * Il initialise les variable de la classe
	 * Il demande deux paramettres : 
	 * @taille : taille de la piece
	 * @hauteur : hauteur de la piece
	 */
	PieceCentreMontre(float taille, float hauteur);

	
	/**
	 * Destruction de la montre
	 * D�salocation de tous les composants
	 */
	virtual ~PieceCentreMontre(void);

	/**
	 * M�thode surcharger de la classe m�re Piece.
	 * Permet d'afficher la pi�ce dans la sc�ne
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * M�thode PiecePartielle
	 * Cette m�thode dessine une piece sp�cial qui va etre utiliser pour dessiner la piece souhait�
	 * en bouclant 3 fois sur cette piece on construit notre piece
	 */
	void PiecePartielle();
};
#endif
