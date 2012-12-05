/**
 * Classe PieceVentilo
 * *******************
 * Cette classe construit une turbine qui est dessinée par la suite en dessous de la montre
 * Le construction de la classe dessine une turbine avec une sphère violette transparente
 * Elle est constituée de 9 tiges, un cylindre et une sphère violette
 * La turbine est dessinée au centre de la scène avec une taille souhaité
 * Elle sera repositionnée par la suite selon l'emplacement souhaité.
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 24 Décembre 2012
 * Version : 1
 */

#ifndef	PIECEVENTILO_H
#define PIECEVENTILO_H

#include "Include.h"
#include "Piece.h"

class PieceVentilo : public Piece
{
	/**
	 * Diamètre interieur de la turbine
	 * cette variable est nécessaire pour dessiner le cylindre central de la turbine
	 */
	float _diametreInterieur;

	/**
	 * Diamètre exterieur de la turbine
	 * cette variable est nécessaire pour dessiner les tiges
	 * elle représente leur longueur maximale
	 */
	float _diametreExterieur;

	/**
	 * Hauteur de la turbine
	 * cette variable est nécessaire pour parametrer la hauteur de la turbine
	 */
	float _hauteur;

	/**
	 * Couleur de la turbine
	 * ce paramètre colorie la turbine : le cylindre et les tiges
	 * la sphère est coloriée par défaut avec le violet, et elle est transparante
	 */
	Couleur *couleur;

public:
	/**
	 * Constructeur de la turbine
	 * Ce constructeur dessine une turbine au centre de la scène
	 * Il initialise les variables de la classe
	 * Il demande trois paramètres : 
	 * @diamètreInterieur : diamètre exterieur de la turbine
	 * @diamètreExterieur : diamètre exterieur de la turbine
	 * @hauteur : hauteur de la turbine
	 */
	PieceVentilo(float diametreInterieur, float diametreExterieur, float hauteur);

	/**
	 * Destruction de la montre
	 * Désallocation de tous les composants
	 */
	~PieceVentilo(void);

	/**
	 * Méthode surchargée de la classe mère Piece.
	 * Permet d'afficher la pièce dans la scène
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * Méthode qui dessine les 9 tiges qui composent la turbine
	 * cette méthode boucle neuf fois sur la méthode UneTige en faisant une rotation sur l'axe y sur chaque itération.
	 */
	void EnsembleTige();

	/**
	 * Méthode qui dessine une tige de la turbine
	 * Cette méthode fabrique une tige particulière qui sera appelée par la suite pour dessiner la turbine
	 */
	void UneTige();

	/**
	 * Méthode qui dessiner le cylindre centre de la turbine
	 * Le cylindre est necessaire pour placer par la suite la sphère violette ainsi que la tige qui va fixer la turbine à l'ensemble de la montre
	 */
	void CylindreCentre();
};
#endif
