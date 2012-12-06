/**
 * Classe TheRoom
 * *************
 * Cette classe construit la chambre de musée où va être placée la montre dans une vitre d'exposition.
 * Le construction de la pièce dessine une chambre au centre de l'univers
 * La chambre contient plusieurs objets : 
 *		- La table et la vitre d'exposition
 *		- La table où sont affichées les commandes et une petite présentation de la montre
 *		- Une horloge classique avec un oiseau qui sort chaque heure et un pondule
 *		- Un lustre au plafond qui projette de la lumiere
 *		- Trois cadres.
 * La chambre sera repositionnée par la suite selon l'emplacement souhaité.
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 2 novembre 2012
 * Version : 1
 */

#ifndef	THEROOM_H
#define THEROOM_H

#include "Include.h"
#include "Piece.h"
#include "PPMImage.h"
#include "Time.h"

class TheRoom : public Piece
{
	/**
	 * Taille de la chambre
	 * A partir de cette variable, on fait des traitements pour calculer la heuteur, la largeur et la profondeur de la chambre
	 */
	float _taille;

	/**
	 * Les angles qui contrôlent les aiguilles de l'horloge acrochée au mur.
	 * _angleSeconde : l'angle de rotation des secondes
	 * _angleMinute : l'angle de rotation des minutes
	 * _angleHeure : l'angle de rotation des heures
	 */
	double _angleSeconde, _angleMinute, _angleHeure;

	/**
	 * les Angles qui contrôlent le pendule
	 * _anglePondule :	angle qui fait tourner le pendule
	 *					le pendule fait des rotations sur l'axe z entre 20 et -20 degrés
	 * alpha : le pas de rotation du pendule, il représente la vitesse de rotation
	 */
	int _anglePondule, alpha;

	/**
	 * Variable qui controle le déplacement de oiseau dans l'horloge
	 * c'est cette variable qui le fait sortir/rentrer.
	 * Le oiseau sort chaque heure, il sort un nombre x de fois correspondant à l'heure (pour 8h il sort 8 fois)
	 */
	float _zOiseau;

	/**
	 * Variable qui controle le nombre de fois que l'oiseau doit sortir
	 * en fonction de l'heure l'oiseau doit sortir un nombre de fois bien déterminé
	 * _heurOiseau : c'est le nombre de fois que l'oiseau va sortir
	 * _heurOiseauControle : controle représente le nombre de fois que l'oiseau sort
	 */
	int _heurOiseau, _heurOiseauControle;

	/**
	 * Booléen qui controle quand l'oiseau doit sortir
	 * s'il est à true l'oiseau sortira, s'il est à false l'oiseau ne sort pas
	 */
	bool _oiseauOk;

	/*
	 * Les variables contenant les textures de la chambre
	 * on charge 10 textures : 4 murs, le sol, le plafon, la plaque en bois
	 * elle vont être chargées une seule fois puis réutilisées
	 */
	GLuint	_mur1, _mur2, _mur3, _mur4,
			_plafond, _sole, _plaqueHorloge,_noticeEmploi,
			_porte, _murTunnel;

	// Timer
	Time* _time;

public:
	/**
	 * Constructeur de la classe
	 * Il initialise la taille de la chambre
	 * Il charge les textures nécessaires pour le chambre
	 * Il demande un paramètre :
	 * @taille : taille de la chambre
	 */
	TheRoom(float taille, Time* time);

	/**
	 * Destruction de la montre
	 * Désallocation de tous les composants
	 */
	virtual ~TheRoom(void);
	
	/**
	 * Méthode surchargée de la classe mère Piece.
	 * Permet d'afficher la pièce dans la scène
	 * On peut par la suite effectuer des transformations : Translation, Rotation, Transformation
	 */
	virtual void BuildAndDisplay();

	/**
	 * Methode TheMuseum
	 * elle construit la chambre du musée
	 * elle place quatre murs tout au tour, un sol et un plafond
	 * c'est dans cette chambre que vont etre placés les differents composants ainsi que la montre
	 */
	void TheMuseum();

	/**
	 * Methode VitrineExposition
	 * Elle construit la table et la vitrine où va etre exposée la montre
	 * La vitrine est constituée de 6 vitress construites par la classe VitreTransparente
	 * elle demande deux parametres
	 * @largeur : largeur de la table et de la vitre
	 * @hauteur : hauteur de la table et de la titre
	 */
	void VitrineExposition(float largeur, float hauteur);

	
	/**
	 * Methode VitrineTransparente
	 * Elle construit une face transparente
	 * elle est utilisée par la methode VitreExposition pour construit la vitre où va etre exposée la montre
	 */
	void VitreTransparente();

	/**
	 * Methode Lustre
	 * Elle construit un lustre et le place au centre du plafond de la chambre
	 * le lustre contient une lampe qui va contenir une lumiere par la suite
	 * @largeur : largeur de lustre
	 * @hauteur : hauteur de lustre
	 */
	void Lustre(float largeur, float hauteur);

	/**
	 * Methode CylindreRemplis
	 * Elle construit un cylindre rempli qui ne contient pas de trou
	 * Le cylindre va etre utilisé beaucoup dans la construction des autres pièces
	 */
	void CylindreRemplis();

	/**
	 * Methode CylindreCrue
	 * Elle construit un cylindre crue qui possède un trou au milieu
	 * Le cylindre va etre utilisé beaucoup dans la construction des autres pièces
	 * @epaisseur : l'epaisseur de cylindre
	 */
	void CylindreCrue(float epaisseur);

	/**
	 * Methode BuildAndDisplayHorloge
	 * elle contruit l'horloge complete : le cadran ainsi que le cadre
	 * elle est construit en buildAndDisplay car elle met a jour l'heure de l'horloge
	 * elle est appelée dans main
	 */
	void BuildAndDisplayHorloge();

	/**
	 * Methode CadreHorloge
	 * elle construit un cadre d'une horloge ancienne
	 * elle comprend une petit maison, un pendule et un oiseau
	 */
	void CadreHorloge();

	/**
	 * Methode Oiseau
	 * elle construit un simple oiseau qui va etre implementé dans l'horloge
	 * l'oiseau sort chaque heure autant de fois que l'heure indiquée
	 */
	void Oiseau();

	/**
	 * Methode Horloge
	 * elle contruit un simple cadran horloge qui va etre mis dans l'horloge complète
	 * elle est constituée de trois tiges : heure, minute et seconde ainsi que des tiges tout autour
	 */
	void Horloge();

	/**
	 * Methode TableInformation
	 * elle contruit une table et une vitre inclinée où vont être illustré les informations relatives à la montre et au projet
	 * elle demande un paramètre :
	 * @taille : taille de la table
	 */
	void TableInformation(float taille);

	/**
	 * Methode CubeTexture
	 * elle contruit un cube avec des textures tout autour
	 * ce cube va etre utilisé par la suite pour construire la table d'exposition et la table des commandes
	 */
	void CubeTexture();

	/**
	 * Methode Update
	 * Elle met a jour l'heure de l'horloge, fait bouger le pendule et fait sortir l'oiseau de son trou
	 * elle va être appelée dans main par la suite
	 */
	void Update();

	// Met à l'heure
	void SetHeure(int seconde, int minute, int heure);
};

#endif
