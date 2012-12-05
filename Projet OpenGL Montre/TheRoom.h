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
	 * Boolen qui controle quand le oiseau doit sortir
	 * si il est a true le oiseau sortira, si il est flase le oiseau ne sort pas
	 */
	bool _oiseauOk;

	/**
	 * Angle de rotation de la porte
	 * cette variable sert a ouvrir ou fermer la porte
	 * langle varie entre 0 et 90 degré
	 */
	float _anglePorte;

	/**
	 *
	 */
	bool _fermerPorte, _OuvrirPorte;
	int _heurOieau, _heurOiseauControle;


	//les face de cube
	GLuint	_mur1, _mur2, _mur3, _mur4,
			_plafond, _sole, _plaqueHorloge,_noticeEmploi,
			_porte, _murTunnel;
public:
	TheRoom(float taille);
	virtual ~TheRoom(void);
	
	virtual void BuildAndDisplay();

	void TheMuseum();
	void VitrineExposition(float largeur, float hauteur);
	void Lustre(float largeur, float hauteur);

	//fonction partielle
	void VitreTransparante();
	void CylindreRemplis();
	void CylindreCrue(float epaisseur);

	void HorlogeComplete(float taille);
	void CadreHorloge();
	void Oiseau();
	void Horloge();

	void TableComande(float taille);
	void CubeTexture();

	void BuildAndDisplayHorlogePorte();

	//la mis-à-jour de l'horloge
	void Update();
};

#endif
