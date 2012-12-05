/**
 * Classe PieceChiffres
 * ********************
 * Cette classe construit des chiffres qui vont servir dans la pieceMinute.
 * Le construction de la classe dessine soit un chiffre allant de 0 à 9 ou un nombre allant de 10 à 99
 * Le chiffre (respectivement le nombre) est dessiné au centre de la scène avec une taille souhaitée
 * Il sera repositionné par la suite selon l'emplacement souhaité.
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 2 Décembre 2012
 * Version : 1
 */

#ifndef	PIECECHIFFRES_H
#define PIECECHIFFRES_H

#include "Include.h"
#include "Piece.h"
#include "Couleurs.h"

class PieceChiffres : public Piece
{
	/**
	 * Taille de chiffre
	 * C'est à partir de cette variable qu'on calcule les dimensions de chiffre : hauteur, largeur, epaisseur et espacement entre deux chiffres
	 */
	float _taille;

	/**
	 * Chiffre à dessiner
	 * C'est le chiffre que la classe va dessiner, il peut varier de 0 à 9
	 * selon le besoin, la classe a la capacité de dessiner soit un chiffre entre 0 et 9 soit un nombre entre 10 et 99
	 * ce sont des nombres entiers compris entre 0 et 9
	 */
	int _chiffre1;
	int _chiffre2;

	/**
	 * Variable de contrôle de type de dessin 
	 * Ces deux variables permettent de contrôler ce que la classe va dessiner : un chiffre ou un nombre (un nombre est composé de deux chiffres)
	 * Si on veut dessiner un chiffre, alors on met la variable _unchiffre à true
	 * Si on veut dessiner un nombre, alors on met la variable _unNombre à true
	 */
	bool _unChiffre;
	bool _unNombre;

	/**
	 * La couleur qu'on va attribuer au chiffre (respectivement au nombre) que la classe va dessiner
	 */
	Couleur *couleur;

public:
	/**
	 * Constructeur de chiffre
	 * Ce constructeur permet de dessiner un seul chiffre (de 0 à 9)
	 * Il initialise les variables de la classe
	 * Il demande deux paramètres :
	 * @taille : taille de chiffre
	 * @chiffre : le chiffre à dessiner, nombre entier entre 0 et 9
	 */
	PieceChiffres(float taille, int chiffre);

	/**
	 * Constructeur de Nombre
	 * Ce constructeur permet de dessiner un nombre composé de deux chiffres (de 10 à 99)
	 * Il initialise les variables de la classe
	 * Il demande trois parametres :
	 * @taille : taille de chiffre
	 * @chiffre1 : le premier chiffre à dessiner (chiffre de gauche, les dizaines), nombre entier entre 0 et 9
	 * @chiffre2 : le deuxieme chiffre à dessiner (chiffre de droite, les unités), nombre entier entre 0 et 9
	 */
	PieceChiffres(float taille, int chiffre1, int chiffre2);

	/**
	 * Destruction de la montre
	 * Désallocation de tous les composants
	 */
	virtual ~PieceChiffres(void);

	/**
	 * Méthode surchargée de la classe mère Piece.
	 * Permet d'afficher la pièce dans la scène
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * Methode qui dessine un chiffre
	 * Cette méthode dessine un seul chiffre entre 0 et 9 passé en paramètre comme un entier
	 * Elle fait appel a la methode DrawChiffre pour le dessiner
	 * @chiffre : chiffre a dessiner, nombre entier entre 0 et 9
	 */
	void Chiffre(int chiffre);

	/**
	 * Methode qui dessine un nombre
	 * Cette méthode dessine un nombre entre 0 et 9 passé en paramètre comme deux entiers
	 * Elle fait appel a la methode DrawChiffre pour dessiner chacun des deux chiffres un par un
	 * @chiffre1 : chiffre de gauche a dessiner, nombre entier entre 0 et 9
	 * @chiffre2 : chiffre de droite a dessiner, nombre entier entre 0 et 9
	 */
	void Nombre(int chiffre1, int chiffre2);

	/**
	 * Methode qui dessine un seul chiffre à la fois
	 * Cette méthode dessine un nombre entre 0 et 9 passé en paramètre comme un entier
	 * Selon le chiffre passé en paramètre, elle fait appel aux méthodes ChiffreZero, ChiffreUn, ChiffreDeux, ChiffreTrois, ChiffreQuatre, ChiffreCinq, ChiffreSix, ChiffreSept, ChiffreHuit ou ChiffreNeuf pour le dessiner
	 * @chiffre : chiffre a dessiner, nombre entier entre 0 et 9
	 */
	void DrawChiffre(int chiffre);

	/**
	 * Methodes qui dessine des chiffres spéciaux
	 * Chacune d'elle est spécialisée pour dessiner un chiffre, ChiffreZero dessiner "0", ChiffreUn dessine le "1", ...
	 * Elle sont appelées uniquement par la méthode DrawChiffre
	 */
	void ChiffreZero();
	void ChiffreUn();
	void ChiffreDeux();
	void ChiffreTrois();
	void ChiffreQuatre();
	void ChiffreCinq();
	void ChiffreSix();
	void ChiffreSept();
	void ChiffreHuit();
	void ChiffreNeuf();
};
#endif

