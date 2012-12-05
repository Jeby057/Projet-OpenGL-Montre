/**
 * Classe ContenantTurbine
 * ***********************
 * Cette classe construit la vitre qui est mise au-dessus des deux turbines
 * Elle est constituée d'une vitre ronde et d'une monture
 * Elle sera repositionnée par la suite selon l'emplacement souhaité.
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 25 Novembre 2012
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
	 * Elle représente 2 fois le rayon du rond
	 */
	float _largeur;

	/**
	 * Epaisseur de la piece
	 * il est interessant de contrôler l'epaisseur de la piece, pour nous permettre de la parametrer par la suite selon nos besoins
	 */
	float _epaisseur;

public:

	/**
	 * Constructeur de la pièce
	 * Ce constructeur dessine le contenant turbine au centre de la scène
	 * Il initialise les variable de la classe
	 * Il demande deux paramètres : 
	 * @largeur : largeur de la pièce
	 * @epaisseur : l'epaisseur de la pièce
	 */
	ContenantTurbine(float largeur, float epaisseur);

	/**
	 * Destruction de la montre
	 * Désallocation de tous les composants
	 */
	~ContenantTurbine(void);

	/**
	 * Méthode surchargée de la classe mère Piece.
	 * Permet d'afficher la pièce dans la scène
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * Méthode Glace
	 * Permet de dessiner une vitre (glace) ronde de rayon : _largeur/2 et d'une epaisseur : _epaisseur
	 */
	void Glace();

	/**
	 * Méthode MontureGlace
	 * Cette methode dessine une monture qui entoure la vitre (glace) avec une epaisseur _epaisseur et d'un rayon : _largeur/2 +  epaisseur
	 */
	void MontureGlace();
};
#endif
