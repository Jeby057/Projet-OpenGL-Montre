/**
 * Classe TheRoom
 * *************
 * Cette classe construit la chmabre de musée où va etre placé la montre dans une vitre d'exposition.
 * Le construction de la pièce dessine une chambre au centre de l'univers
 * La chambre contient plusieurs objets : 
 *		- La table et la vitre d'exposition
 *		- La table où sont affichés les commandes et une petit présentation de la montre
 *		- Une horlage classique avec un oiseau qui sort chaque heur et un pondule
 *		- Un luste au plafond qui projet de la lumiere
 *		- Trois cadre.
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
#include "Couleurs.h"

class TheRoom : public Piece
{
	/**
	 * Taille de la chambre
	 * A partir de cette variable, on fait des traitement pour calculer la heuteur, la largeur et la profondeur de la chambre
	 */
	float _taille;

	/**
	 * Objet couleur
	 * cette variable est utiliser pour spécifier les couleurs utiliser dans la chambre, comme par exemple les couleur de lustre
	 */
	//Couleur *couleur;

	/**
	 * Les angles qui controle les eguailles de l'horloge acroché au mur.
	 * _angleSeconde : l'angle de rotation des secondes
	 * _angleMinute : l'angle de rotation des minutes
	 * _angleHeure : l'angle de rotation des heures
	 */
	int _angleSeconde, _angleMinute, _angleHeure;

	/**
	 * les Angles qui controle le pondule
	 * _anglePondule :	angle qui fait rotater le pendule
	 *					le pondule il fait des rotations sur l'axe z entre 20 et -20 dugrés
	 * alpha : le pas de rotation de pendule, il représente la vitesse de rotation
	 */
	int _anglePondule, alpha;

	/**
	 * Variable qui controle le deplacement de oiseau dans l'horloge
	 * c'est cette variable qui le fais sortir/rentrer.
	 * Le oiseau sort chaque heure, en fonction de l'heur il sort autant de fois que l'heur (pour 8h il sort 8 fois)
	 */
	float _zOiseau;

	/**
	 * Variable qui controle le nombre de fois que le oiseau doit sortir
	 * en fonction de l'heur le oiseau doit sortir un nombre de fois bien déterminer
	 * _heurOiseau : c'est le nombre de fois que le oiseau va sortir
	 * _heurOiseauControle : controle est combien de fois le oiseau sort
	 */
	int _heurOiseau, _heurOiseauControle;

	/**
	 * Boolen qui controle quand le oiseau doit sortir
	 * si il est a true le oiseau sortira, si il est flase le oiseau ne sort pas
	 */
	bool _oiseauOk;

	/*
	 * Les vatibale contenant les texture de la chambre
	 * on charge 10 texture : 4 murs, le sole, le plafon, la plaque en bois
	 * elle vont etre charger une seule fois puis réutiliser
	 */
	GLuint	_mur1, _mur2, _mur3, _mur4,
			_plafond, _sole, _plaqueHorloge,_noticeEmploi,
			_porte, _murTunnel;
public:
	/**
	 * Constructeur de la classe
	 * Il initialise la taille de la chambre
	 * Il charge les textures nécessaires pour le chambre
	 * Il demande une paramètre :
	 * @taille : taille de la chambre
	 */
	TheRoom(float taille);

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
	 * elle construit la chambre de musée
	 * elle place quatres mure tout au toure, un sole et un plafond
	 * c'est dans cette chambre qui vont etre placée les diffirent composant ainsi que la montre
	 */
	void TheMuseum();

	/**
	 * Methode VitrineExposition
	 * Elle construit la table et la vitrine où va etre exposée la montre
	 * La vitrine est constituer de 6 galsses construitent par la classe VitreTransparente
	 * elle demande deux paramettres
	 * @largeur : largeur de la table et de la vitre
	 * @hauteur : hauteur de la table et de la titre
	 */
	void VitrineExposition(float largeur, float hauteur);

	
	/**
	 * Methode VitrineTransparente
	 * Elle construit une face tranparante
	 * elle est utiliser par la methode VitreExposition pour contruit la vitre où va etre exposer la montre
	 */
	void VitreTransparente();

	/**
	 * Methode Lustre
	 * Elle construit un lustre et le place au centre de plafon de la chambre
	 * le lustre contien une lampe a qui ont va lui mettre une lumiere par la suite
	 * @largeur : largeur de lustre
	 * @hauteur : hauteur de lustre
	 */
	void Lustre(float largeur, float hauteur);

	/**
	 * Methode CylindreRemplis
	 * Elle construit un cylindre remplis qui contien pas de troue
	 * Le cylindre va etre utiliser beaucoup dans la construction des autres pices
	 */
	void CylindreRemplis();

	/**
	 * Methode CylindreCrue
	 * Elle construit un cylindre crue qui posède un trou au millieur
	 * Le cylindre va etre utiliser beaucoup dans la construction des autres pices
	 * @epaisseur : l'epaisseur de cylindre
	 */
	void CylindreCrue(float epaisseur);

	/**
	 * Methode BuildAndDisplayHorloge
	 * elle contruit l'hologe complete : le cadrant ainsi que le cadre
	 * elle est construit en buile and displaye car elle met a jour l'heur de l'horloge
	 * elle est appelée dans main
	 */
	void BuildAndDisplayHorloge();

	/**
	 * Methode CadreHorloge
	 * elle contruit un cadre d'une horloge ancienne
	 * elle comprend une petit maison, un pendule et un oiseau
	 */
	void CadreHorloge();

	/**
	 * Methode Oiseau
	 * elle contruit une simple oiseau qui va etre implement dans l'horloge
	 * le oiseau sort chaque heure autant de fois que l'heure indiquée
	 */
	void Oiseau();

	/**
	 * Methode Horolge
	 * elle contruit une simple cadrant horloge qui va etre mise dans l'hologe ocmplete
	 * elle est constituer de trois tige : heure, minute et seconde ainsi que des tige tout autours
	 */
	void Horloge();

	/**
	 * Methode TableInformation
	 * elle contruit une table et une vitre incliner où va etre illustré les information relative a la montre et au projet
	 * elle demande un paramettre :
	 * @taille : taille de la table
	 */
	void TableInformation(float taille);

	/**
	 * Methode CubeTexture
	 * elle contruit un cube avec des texture tout autoure
	 * ce cube va etre utiliser par la suite pour construire la table d'exposition et la table des comandes
	 */
	void CubeTexture();

	/**
	 * Methode Update
	 * Elle met a jour l'heur de l'horloge, fait bouger le pendule et fait sortir le oiseau de son trou
	 * elle va etre appelée dans main par la suite
	 */
	void Update();
};

#endif
