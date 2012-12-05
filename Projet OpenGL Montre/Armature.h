/**
 * Classe Armature
 *********************
 * Construit l'armature (la coque) contenant les m�canismes de la montre
 * L'objet est complexe et ressemble � un octogone
 * L'objet poss�de une �paisseur et contient un trou ferm� au fond pour y placer les autres composants � l'int�rieur
 * Il existe une l�g�re sur�l�vation de l'ext�rieur vers l'int�rieur (trou) sur le dessus
 * Construit �galement une vitre transparente plac�e sur le dessus de l'armature dans le trou
 * Le constructeur charge tous les composants n�cessaires en m�moire
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
	 * en param�tres, les variables chargeant les donn�es membres
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
	 * Simple affichage des �l�ments d�j� charg�s
	**/
	virtual void FastDisplay();
};
#endif
