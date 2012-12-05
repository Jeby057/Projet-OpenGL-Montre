/**
 * Classe AiguillesSec
 *********************
 * Construit les aiguilles affichant les secondes de la montre
 * L'objet est compos� d'un cylindre trou� central auquel on sont attach�es 3 aiguilles avec une aiguille plus grande que les 2 deux autres identiques
 * Une aiguille est compos�e de 2 trap�zes (�pais) s�par�s joints au sommet par une pyramide dont la hauteur peut changer
 * Le constructeur charge tous les composants n�cessaires en m�moire
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

	// tableaux des points repr�sentant le "morceau" d'aiguille de gauche et de droite
	Point3D * _aiguilleG;
	Point3D * _aiguilleD;

public:

	/**
	 * Constructeur des aiguilles
	 * En param�tres, les variables chargeant les donn�es membres : _longueur, _rayon et _epaiss
	**/
	AiguillesSec(float longueur, float rayon, float epaiss);

	/**
	 * Destruction des aiguilles
	 * D�sallocation de tous les composants
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
