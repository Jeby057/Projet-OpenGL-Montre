/**
 * Classe PieceSeconde
 * *******************
 * Cette classe construit le cadran des secondes
 * Elle est constitu�e d'un cylindre ainsi que de 12 tiges tout au tour
 * Cette piece permet d'indiquer les secondes de la montre
 * Elle sera repositionn�e par la suite selon l'emplacement souhait�.
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 25 D�cembre 2012
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
	 * Ce constructeur dessine le cylindre et les tiges au centre de la sc�ne
	 * Il initialise les variables de la classe
	 * Il demande deux param�tres :
	 * @rayon : le rayon de la piece
	 * @epaisseur : l'epaisseur de la piece
	 */
	PieceSeconde(float rayon, float epaisseur);

	/**
	 * Destruction de la montre
	 * D�sallocation de tous les composants
	 */
	virtual ~PieceSeconde(void);

	/**
	 * M�thode surcharg�e de la classe m�re Piece.
	 * Permet d'afficher la pi�ce dans la sc�ne
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * M�thode Tige
	 * Cette m�thode dessine une tige, par la suite elle va etre utilis�e pour dessiner les 12 autres tout au tour du cylindre
	 */
	void Tige();
};
#endif
