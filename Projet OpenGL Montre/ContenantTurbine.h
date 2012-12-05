/**
 * Classe ContenantTurbine
 * *************
 * Cette classe construit glace qui servera comme cache vitre aux deux turbine
 * Elle est constituer d'une galce ronde et une monture
 * Elle sera repositionn�e par la suite selon l'emplacement souhait�.
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 25 D�cembre 2012
 * Version : 1
 */

#ifndef CONTENANT_TURBINE_H
#define CONTENANT_TURBINE_H

#include "Include.h"
#include "Piece.h"
#include "Couleurs.h"

class ContenantTurbine : public Piece
{
	/**
	 * Largeur de la piece
	 * Elle repr�sente 2 fois le rayon de rond
	 */
	float _largeur;

	/**
	 * Epesseur de la piece
	 * il est interessant de controler l'epesseur de la piece, pour nous permetre de la parametrer par la suite selon nos besoin
	 */
	float _epesseur;

public:

	/**
	 * Constructeur de la piece
	 * Ce constructeur dessine le contenant turbine au centre de la sc�ne
	 * Il initialise les variable de la classe
	 * Il demande deux paramettres : 
	 * @largeur : largeur de la piece
	 * @epesseur : l'epesseur de la piece
	 */
	ContenantTurbine(float largeur, float epesseur);

	/**
	 * Destruction de la montre
	 * D�salocation de tous les composants
	 */
	~ContenantTurbine(void);

	/**
	 * M�thode surcharger de la classe m�re Piece.
	 * Permet d'afficher la pi�ce dans la sc�ne
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * M�thode Glace
	 * Permet de dessiner une glace ronde de rayon : _largeur/2 et d'une epesseur : _epesseur
	 */
	void Glace();

	/**
	 * M�thode MontureGlace
	 * Cette methode dessine une monture qui entoure la galce avec une epesseur _epesseur et d'un rayon : _largeur/2 +  epesseur
	 */
	void MontureGlace();
};
#endif
