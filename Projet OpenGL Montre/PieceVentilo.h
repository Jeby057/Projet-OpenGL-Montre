/**
 * Classe PieceVentilo
 * *************
 * Cette classe construit une turbine qui est dessiner par la suite en dessous de la montre
 * Le construction de la classe dessin une turbine avec un sphère violet transparente
 * Elle est constituer de 9 tiges, un cylendre et une sphère viollet
 * La turbine est dessiner au centre de la scène avec une taile souhaité
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
	 * Diamettre interieur de la turbine
	 * cette variable est necessaire pour dessiner le cylendre centrale de la turbine
	 */
	float _diametreInterieur;

	/**
	 * Diamettre exterieur de la turbine
	 * cette variable est necessaire pour dessiner les tiges
	 * elle reprisent leur langueur maximal
	 */
	float _diametreExterieur;

	/**
	 * Hauteur de la turbine
	 * cette variable est necessaire pour parametrer l'hauteur de la turbine
	 */
	float _hauteur;

	/**
	 * Couleur de la turbine
	 * ce parametre colorie la turbine : le cylendre et les tiges
	 * la sphère est coloriée par défaut avec le violet, et elle est transparante
	 */
	Couleur *couluer;

public:
	/**
	 * Constructeur de la turbine
	 * Ce constructeur dessine une turbine au centre de la scène
	 * Il initialise les variable de la classe
	 * Il demande trois paramettres : 
	 * @diametreInterieur : diamettre exterieur de la turbine
	 * @diametreExterieur : diamettre exterieur de la turbine
	 * @hauteur : hauteur de la turbine
	 */
	PieceVentilo(float diametreInterieur, float diametreExterieur, float hauteur);

	/**
	 * Destruction de la montre
	 * Désalocation de tous les composants
	 */
	~PieceVentilo(void);

	/**
	 * Méthode surcharger de la classe mère Piece.
	 * Permet d'afficher la pièce dans la scène
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * Méthode qui dessiner les 9 tiges qui compose la turbine
	 * cette méthode boucle neuf fois sur la méthode UneTIge en faisant une rotation sur l'axe y sur chaque itiration.
	 */
	void EnsembleTige();

	/**
	 * Méthode qui dessiner une tige de la turbine
	 * Cette méthode fabrique une tige particulier qui sera appelé par la suite pour dessiner la turbine
	 */
	void UneTige();

	/**
	 * Méthode qui dessiner le cylendre centre de la trube
	 * Le cylendre est necessaire pour placer par la suite la sphère violet ainsi que la tige qui va fixer la turbine a l'ensemble de la montre
	 */
	void CylendreCentre();
};
#endif
