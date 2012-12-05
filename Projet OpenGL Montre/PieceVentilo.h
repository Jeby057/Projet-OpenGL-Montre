/**
 * Classe PieceVentilo
 * *************
 * Cette classe construit une turbine qui est dessiner par la suite en dessous de la montre
 * Le construction de la classe dessin une turbine avec un sph�re violet transparente
 * Elle est constituer de 9 tiges, un cylendre et une sph�re viollet
 * La turbine est dessiner au centre de la sc�ne avec une taile souhait�
 * Elle sera repositionn�e par la suite selon l'emplacement souhait�.
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 24 D�cembre 2012
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
	 * la sph�re est colori�e par d�faut avec le violet, et elle est transparante
	 */
	Couleur *couluer;

public:
	/**
	 * Constructeur de la turbine
	 * Ce constructeur dessine une turbine au centre de la sc�ne
	 * Il initialise les variable de la classe
	 * Il demande trois paramettres : 
	 * @diametreInterieur : diamettre exterieur de la turbine
	 * @diametreExterieur : diamettre exterieur de la turbine
	 * @hauteur : hauteur de la turbine
	 */
	PieceVentilo(float diametreInterieur, float diametreExterieur, float hauteur);

	/**
	 * Destruction de la montre
	 * D�salocation de tous les composants
	 */
	~PieceVentilo(void);

	/**
	 * M�thode surcharger de la classe m�re Piece.
	 * Permet d'afficher la pi�ce dans la sc�ne
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * M�thode qui dessiner les 9 tiges qui compose la turbine
	 * cette m�thode boucle neuf fois sur la m�thode UneTIge en faisant une rotation sur l'axe y sur chaque itiration.
	 */
	void EnsembleTige();

	/**
	 * M�thode qui dessiner une tige de la turbine
	 * Cette m�thode fabrique une tige particulier qui sera appel� par la suite pour dessiner la turbine
	 */
	void UneTige();

	/**
	 * M�thode qui dessiner le cylendre centre de la trube
	 * Le cylendre est necessaire pour placer par la suite la sph�re violet ainsi que la tige qui va fixer la turbine a l'ensemble de la montre
	 */
	void CylendreCentre();
};
#endif
