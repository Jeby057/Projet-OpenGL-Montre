/**
 * Classe Armature
 *********************
 * Construit l'armature (la coque) contenant les mécanismes de la montre
 * L'objet est complexe et ressemble à un octogone
 * L'objet possède une épaisseur et contient un trou fermé au fond pour y placer les autres composants à l'intérieur
 * Il existe une légère surélévation de l'extérieur vers l'intérieur (trou) sur le dessus
 * Construit également une vitre transparente placée sur le dessus de l'armature dans le trou
 * Le constructeur charge tous les composants nécessaires en mémoire
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 */

#ifndef ARMATURE_H
#define ARMATURE_H

#include "Piece.h"

class Armature : public Piece
{
private:
	// Longueur de l'armature
	float _longueur;

	// Largeur de l'armature
	float _largeur;

	// Epaisseur de l'armature
	float _epaisseur;

public:

	/**
	 * Constructeur de l'armature
	 * en paramètres, les variables chargeant les données membres
	**/
	Armature(float longueur, float largeur, float epaisseur);

	/**
	* Destructeur
	**/
	virtual ~Armature(void);

	/**
	 * Construit les composants de l'objet AiguillesSec
	**/
	virtual void BuildAndDisplay();

	/**
	 * Simple affichage des éléments déjà chargés
	**/
	virtual void FastDisplay();
};
#endif
