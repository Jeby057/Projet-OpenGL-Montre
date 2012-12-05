/**
 * Classe PieceVentilo
 * *******************
 * Cette classe construit une turbine qui est dessin�e par la suite en dessous de la montre
 * Le construction de la classe dessine une turbine avec une sph�re violette transparente
 * Elle est constitu�e de 9 tiges, un cylindre et une sph�re violette
 * La turbine est dessin�e au centre de la sc�ne avec une taille souhait�
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
	 * Diam�tre interieur de la turbine
	 * cette variable est n�cessaire pour dessiner le cylindre central de la turbine
	 */
	float _diametreInterieur;

	/**
	 * Diam�tre exterieur de la turbine
	 * cette variable est n�cessaire pour dessiner les tiges
	 * elle repr�sente leur longueur maximale
	 */
	float _diametreExterieur;

	/**
	 * Hauteur de la turbine
	 * cette variable est n�cessaire pour parametrer la hauteur de la turbine
	 */
	float _hauteur;

	/**
	 * Couleur de la turbine
	 * ce param�tre colorie la turbine : le cylindre et les tiges
	 * la sph�re est colori�e par d�faut avec le violet, et elle est transparante
	 */
	Couleur *couleur;

public:
	/**
	 * Constructeur de la turbine
	 * Ce constructeur dessine une turbine au centre de la sc�ne
	 * Il initialise les variables de la classe
	 * Il demande trois param�tres : 
	 * @diam�treInterieur : diam�tre exterieur de la turbine
	 * @diam�treExterieur : diam�tre exterieur de la turbine
	 * @hauteur : hauteur de la turbine
	 */
	PieceVentilo(float diametreInterieur, float diametreExterieur, float hauteur);

	/**
	 * Destruction de la montre
	 * D�sallocation de tous les composants
	 */
	~PieceVentilo(void);

	/**
	 * M�thode surcharg�e de la classe m�re Piece.
	 * Permet d'afficher la pi�ce dans la sc�ne
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * M�thode qui dessine les 9 tiges qui composent la turbine
	 * cette m�thode boucle neuf fois sur la m�thode UneTige en faisant une rotation sur l'axe y sur chaque it�ration.
	 */
	void EnsembleTige();

	/**
	 * M�thode qui dessine une tige de la turbine
	 * Cette m�thode fabrique une tige particuli�re qui sera appel�e par la suite pour dessiner la turbine
	 */
	void UneTige();

	/**
	 * M�thode qui dessiner le cylindre centre de la turbine
	 * Le cylindre est necessaire pour placer par la suite la sph�re violette ainsi que la tige qui va fixer la turbine � l'ensemble de la montre
	 */
	void CylindreCentre();
};
#endif
