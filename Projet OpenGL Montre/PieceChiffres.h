/**
 * Classe PieceChiffre
 * *************
 * Cette classe construit des chiffres qui vont servire dans la pieceMinute.
 * Le construction de la classe dessin soit un chiffre allons de 0 à 9 ou un nombre allons de 10 à 99
 * Le chiffre (respectivment le nombre) est dessiner au centre de la scène avec une taile souhaité
 * Il sera repositionnée par la suite selon l'emplacement souhaité.
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
	 * C'est à partir de cette variable qu'on calcule les dimension de chiffre : hauteur, largeur, epesseur et espacement entre deux chiffre
	 */
	float _taille;

	/*
	 * Chiffre a dessiner
	 * C'est le chiffre que la classe va dessiner, il peut varier de 0 à 9
	 * celon le besoin, la classe a la capacitée de dessiner soit un chiffre entre 0 et 9 soit un nombre entre 10 et 99
	 * ce sont des nombre entier compris entre 0 et 9
	 */
	int _chiffre1;
	int _chiffre2;

	/**
	 * Variable de controle de teype de dessin 
	 * Ces deux variable permettent de controler qu'est ce que la classe va dessiner : un chiffre ou un nombre (un nombre est composser de deux chiffre)
	 * Si on veut dessiner un chiffre, alors on met la variable _unchiffre à true
	 * Si on veut dessiner un nombre, alors on met la variable _un Nombre à true
	 */
	bool _unChiffre;
	bool _unNombre;

	/**
	 * La couleur qu'on va attribuer au chiffre (respectivement) que la classe va dessiner
	 */
	Couleur *couleur;

public:
	/**
	 * Constructeur de chiffre
	 * Ce constructeur permet de dessiner un seul chiffre (de 0 à 9)
	 * Il initialise les variable de la classe
	 * Il demande deux paramettres :
	 * @taille : taille de chiffre
	 * @chiffre : le chiffre a dessiner, nombre entier entre 0 et 9
	 */
	PieceChiffres(float taille, int chiffre);

	/**
	 * Constructeur de Nombre
	 * Ce constructeur permet de dessiner un nombre composer de deux chiffre (de 10 à 99)
	 * Il initialise les variable de la classe
	 * Il demande trois paramettres :
	 * @taille : taille de chiffre
	 * @chiffre1 : le premier chiffre a dessiner (chiffre de gauche, les dizaines), nombre entier entre 0 et 9
	 * @chiffre1 : le deuxieme chiffre a dessiner (chiffre de droite, les unités), nombre entier entre 0 et 9
	 */
	PieceChiffres(float taille, int chiffre1, int chiffre2);

	/**
	 * Destruction de la montre
	 * Désalocation de tous les composants
	 */
	virtual ~PieceChiffres(void);

	/**
	 * Méthode surcharger de la classe mère Piece.
	 * Permet d'afficher la pièce dans la scène
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * Methode qui dessine un chiffre
	 * Cette méthode dessine un seul chiffre entre 0 et 9 passer en paramettre comme un entier
	 * Elle fait appel a la methode DrawChiffre pour le dessiner
	 * @chiffre : chiffre a dessiner, nombre entier entre 0 et 9
	 */
	void Chiffre(int chiffre);

	/**
	 * Methode qui dessine un nombre
	 * Cette méthode dessine un nombre entre 0 et 9 passer en paramettre comme deux entier
	 * Elle fait appel a la methode DrawChiffre pour dessiner chaqu'un des deux chiffre un par un
	 * @chiffre1 : chiffre de gauche a dessiner, nombre entier entre 0 et 9
	 * @chiffre : chiffre de droite a dessiner, nombre entier entre 0 et 9
	 */
	void Nombre(int chiffre1, int chiffre2);

	/**
	 * Methode qui dessine un seul chiffre a la fois
	 * Cette méthode dessine un nombre entre 0 et 9 passer en paramettre comme in entier
	 * Selon le chiffre passer en paramettre, elle fait appelle aux méthodes ChiffreZero, ChiffreUn, ChiffreDeux, ChiffreTrois, ChiffreQuatre, ChiffreCinq, ChiffreSix, ChiffreSept, ChiffreHuite ou ChiffreNeuf pour le dessiner
	 * @chiffre : chiffre a dessiner, nombre entier entre 0 et 9
	 */
	void DrawChiffre(int chiffre);

	/**
	 * Methodes qui dessiner des chiffre spéciale
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
	void ChiffreHuite();
	void ChiffreNeuf();
};
#endif

