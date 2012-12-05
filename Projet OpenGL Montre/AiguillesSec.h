/**
 * Classe AiguillesSec
 *********************
 * Construit les aiguilles affichant les secondes de la montre
 * L'objet est composé d'un cylindre troué central auquel on sont attachées 3 aiguilles avec une aiguille plus grande que les 2 deux autres identiques
 * Une aiguille est composée de 2 trapèzes (épais) séparés joints au sommet par une pyramide dont la hauteur peut changer
 * Le constructeur charge tous les composants nécessaires en mémoire
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 */

#ifndef AIGUILLES_SEC_H
#define AIGUILLES_SEC_H

#include "Piece.h"

class AiguillesSec : public Piece
{
private:
	// Longueur de l'aiguille la plus grande
	float _longueur;

	// Rayon du disque central reliant les 3 aiguilles
	float _rayon;

	// Epaisseur du tout (aiguilles)
	float _epaiss;

	// tableaux des points représentant le "morceau" d'aiguille de gauche et de droite
	Point3D * _aiguilleG;
	Point3D * _aiguilleD;

public:

	/**
	 * Constructeur des aiguilles
	 * En paramètres, les variables chargeant les données membres : _longueur, _rayon et _epaiss
	**/
	AiguillesSec(float longueur, float rayon, float epaiss);

	/**
	 * Destruction des aiguilles
	 * Désallocation de tous les composants
	 */
	virtual ~AiguillesSec(void);

	/**
	 * Construit les composants de l'objet AiguillesSec
	**/
	virtual void BuildAndDisplay();

	/**
	 * Construit une aiguille
	 * @aiguille : le tableau de points d'une aiguille
	**/
	void ConstrAig(Point3D * aiguille);

	/**
	 * Construit la pyramide formant le sommet d'une aiguille
	 * @longPic : valeur qui divise "longueur" pour obtenir le hauteur du pic du haut de l'aiguille
	**/
	void ConstrPyram(float longPic);
};
#endif
