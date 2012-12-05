/**
 * Classe PieceCentreMontre
 * ************************
 * Cette classe construit une pi�ce qui sera pos�e au centre de la montre
 * Cette piece sert uniquement � la d�coration, elle ne donne aucune information utile
 * Elle est constitu�e de 3 sous-pi�ces identiques
 * Elle sera repositionn�e par la suite selon l'emplacement souhait�.
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 21 Novembre 2012
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
	 * C'est � partir de cette variable qu'on calcule les dimensions de la pi�ce : largeur et epaisseur
	 */
	float _taille;

	/**
	 * Hauteur de la pi�ce
	 * Cette variable est necessaire pour parametrer la hauteur de la piece
	 */
	float _hauteur;

public:

	/**
	 * Constructeur de la pi�ce
	 * Ce constructeur dessine une pi�ce au centre de la sc�ne
	 * Il initialise les variables de la classe
	 * Il demande deux param�tres : 
	 * @taille : taille de la piece
	 * @hauteur : hauteur de la piece
	 */
	PieceCentreMontre(float taille, float hauteur);

	
	/**
	 * Destruction de la montre
	 * D�sallocation de tous les composants
	 */
	virtual ~PieceCentreMontre(void);

	/**
	 * M�thode surcharg�e de la classe m�re Piece.
	 * Permet d'afficher la pi�ce dans la sc�ne
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * M�thode PiecePartielle
	 * Cette m�thode dessine une piece sp�ciale qui va �tre utilis�e pour dessiner la piece souhait�e
	 * en bouclant 3 fois sur cette pi�ce on construit notre pi�ce finale
	 */
	void PiecePartielle();
};
#endif
