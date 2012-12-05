/**
 * Classe ContenantTurbine
 * ***********************
 * Cette classe construit la vitre qui est mise au-dessus des deux turbines
 * Elle est constitu�e d'une vitre ronde et d'une monture
 * Elle sera repositionn�e par la suite selon l'emplacement souhait�.
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 25 Novembre 2012
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
	 * Elle repr�sente 2 fois le rayon du rond
	 */
	float _largeur;

	/**
	 * Epaisseur de la piece
	 * il est interessant de contr�ler l'epaisseur de la piece, pour nous permettre de la parametrer par la suite selon nos besoins
	 */
	float _epaisseur;

public:

	/**
	 * Constructeur de la pi�ce
	 * Ce constructeur dessine le contenant turbine au centre de la sc�ne
	 * Il initialise les variable de la classe
	 * Il demande deux param�tres : 
	 * @largeur : largeur de la pi�ce
	 * @epaisseur : l'epaisseur de la pi�ce
	 */
	ContenantTurbine(float largeur, float epaisseur);

	/**
	 * Destruction de la montre
	 * D�sallocation de tous les composants
	 */
	~ContenantTurbine(void);

	/**
	 * M�thode surcharg�e de la classe m�re Piece.
	 * Permet d'afficher la pi�ce dans la sc�ne
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * M�thode Glace
	 * Permet de dessiner une vitre (glace) ronde de rayon : _largeur/2 et d'une epaisseur : _epaisseur
	 */
	void Glace();

	/**
	 * M�thode MontureGlace
	 * Cette methode dessine une monture qui entoure la vitre (glace) avec une epaisseur _epaisseur et d'un rayon : _largeur/2 +  epaisseur
	 */
	void MontureGlace();
};
#endif
