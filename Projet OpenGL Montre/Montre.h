/**
 * Classe Montre
 * *************
 *  La construction de la pièce ordonne et positionne toutes les sous-pices de la montre
 *  L'appel de BuildAndDisplay est identique à l'appel de FastDisplay, car aucune construction suplémentaire d'objets est nescessaire
 *  L'appel de BuildAndSave est donc inutile ici.
 *  Tous les composants de la montre sont créé et chargé en mémoire de la carte graphique à l'appel du constructeur
 *  FastDisplay doit ensuite être appelé pour afficher les éléments chargés et afin de mettre à jour leurs positions, rotations
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 29 novembre 2012
 * Version : 1
 */

#ifndef MONTRE_H
#define MONTRE_H

#include "Include.h"
#include "Piece.h"
#include "Engrenage.h"
#include "Maitresse.h"
#include "EntourantCube.h"
#include "IndicateurMins.h"
#include "CubeHeure.h"
#include "PlaqueSeparation.h"
#include "PieceCentreMontre.h"
#include "AiguillesSec.h"
#include "PieceVentilo.h"
#include "PieceSeconde.h"
#include "Connector.h"
#include "Armature.h"
#include "ContenantTurbine.h"
#include "BlocMinute.h"
#include "PieceChiffres.h"
#include "windows.h"
#include "Time.h"

// Définition des angles de rotations pour chaque période horaire
#define DELTA_HEURE 120.0
#define DELTA_MINUTE DELTA_HEURE/60.0
#define DELTA_SECONDE DELTA_MINUTE/60.0
#define DELTA_MILLISECONDE DELTA_SECONDE/1000.0

class Montre : public Piece
{
	// Rotation de l'engrenage principale
	// Une rotation complète de l'engrenage engendre 3h
	// Seule cette donnée est utilisé pour faire fonctionner l'ensemble de la montre
	float _rotation;

	// Permet de savoir dans quel sens tourne la turbine
	// Ceux sont les turbines qui font normalement avancer les engranages (montre mécanique)
	// Ici, elles n'ont qu'un rôle figuratif
	// Vrai, quand la turbine tourne de gauche à droite, Faux inversement
	// Cycliquement (Toutes les 2 secondes), le sens change
	// Il y a 2 cycle (2 secondes) dans un sens
	bool _sensTurbine;

	// Angle de rotation de la turbine pendant un cycle
	// Tous les 2 cycles, la rotation s'inverse
	float _rotationTurbine;

	// Création des engrenages
	// Mxpxx représente le module x,xx
	// _xpxx représente le diamètre xpxx
	Engrenage* _engrenage_M0p01_0p255;	// Grand engrenage étage inférieur (3h)
	Engrenage* _engrenage_M0p01_0p85;	// Grand engrenage étage supérieur (3h)
	Engrenage* _engrenage_M0p01_0p25;	// Engrenage de réduction (1h)
	Engrenage* _engrenage_M0p01_0p75;	// Engrenages intermédiaires vers bras mécanique & turbines
	Engrenage* _engrenage_M0p01_0p15;   // Engrenage de réduction (12h)
	Engrenage*_engrenage_M0p01_0p15G;	// Engrenage (Grande hauteur) de réduction (12h)
	Engrenage* _engrenage_M0p01_0p60;	// Engrenage intermédiaires vers les secondes
	Engrenage *_engrenage_M0p01_0p5;	// Petit engrenage des secondes

	// Création de la piece maitresse
	// Pièce à 3 bras où sont placé les cubes des heures et les pointeurs de mintutes
	Maitresse* _maitresse;

	// Cache engrenage
	// Permet de cacher une partie de l'engrenage pour une 
	// meilleur lisibilité de l'heure
	CacheEngrenage* _cacheEngrenage;

	// Cadre horraire
	// Décoration autour du cube des heures
	EntourantCube* _pointeurHorraire;

	// Triangle des indicateur des minutes
	IndicateurMins* _indicateurMin;

	// Rotors utilisés dans la montre
	PartialDisque *_rotorEngrenageFinal;				// Rotor entre le bras mécanique et le cube des heures
	PartialDisque *_rotorCubeHeure;						// Rotor permettant la rotation des cubes heures
	PartialDisque *_rotorPieceMaitresse;				// Grand rotor permettant la rotation de toute la pièce maitresse
	PartialDisque *_rotorEngrenageSecondes;				// Rotor de l'engrenage et de l'aiguille des secondes
	PartialDisque *_rotorEngrenageReductionHeureMin;	// Rotor intermédiaire entre la réduction des 3h vers les secondes
	PartialDisque *_rotorInferieur;						// Pilier permettant le maintien de la structure supérieur

	// Cube des heures
	// Chaque cube représente 4 heures (3cubes * 4heures = 12h)
	CubeHeure *_cubeHeure[3];

	// Plaque de séparation partie supérieur (visible) et la partie interne (machinerie)
	PlaqueSeparation *_plaqueSeparation;

	// Sur-Rotor central de la montre
	// Permet de cacher le rotor principal de la structure maitresse
	PieceCentreMontre* _surCentralRotor;
	
	// Aiguille des secondes
	AiguillesSec *_aiguillesSecondes;

	// Disque permettant d'afficher les indicateurs secondes à l'aiguille
	PieceSeconde* _disqueSecondes;

	// Turbine permettant de faire avancer les engrenages (fictif)
	PieceVentilo* _turbine;

	// Connecteur permettant de connecter les rotors des cubes heures (décoration)
	Connector* _connectorCubeHeure;

	// L'armature représente le boitier de la montre 
	Armature* _armature;

	// Représente un cylindre conctenant la turbine permettant de faire une opération
	// booleenne avec l'armature afin de la perser
	ContenantTurbine* _contenantTurbine;

	// Bloc permettant d'afficher l'ensemble des minutes
	BlocMinute* _blocMinute;

	// Piècse représentants les chiffres des minutes
	PieceChiffres* _chiffre0, *_chiffre15, *_chiffre30, *_chiffre45, *_chiffre60;

	// Temps actuel
	Time* _time;

	// Permet de savoir si l'utilisateur effectue une modification sur l'horraire
	// Arret donc des secondes
	bool _inUserChanging;

	// Vrai si seul le mécanisme doit être affiché
	// Sinon, toute la montre est affiché
	bool _displayMecanismeOnly;
	int _displayMecanismeOnlyProcessing;

	// Timer permettant la rotation des turbines
	Time _turbineTime;

	// Fractal permet de décomposer la montre
	// C'est le facteur de décomposition
	// A 1, la montre n'est pas décomposé
	float _fractal;


public:
	/**
	 * Constructeur de la montre
	 * Construit et sauvegarde tous les composants de la montre dans la carte graphique
	 */
	Montre(Time*);

	/**
	 * Destruction de la montre
	 * Désalocation de tous les composants
	 */
	virtual ~Montre(void);

	/**
	 * Ici, BuildAndDisplay est identique à FastDisplay
	 * Il n'y a pas de construction d'objet, seulement de l'affichage et quelques modifications
	 * (Position, rotation, transformation)
	 */
	virtual void BuildAndDisplay();

	/**
	 * Ici, BuildAndSave est inutile
	 * Il n'y pas de construction suplémentaire d'objets
	 * Ainsi, aucune sauvegarde de pattern dans la carte graphique n'est nescessaire
	 */
	virtual void BuildAndSave();
	
	/**
	 * Permet d'afficher en mode rapide la pièce
	 * Aucun pièce n'est reconstruite. Elles sont toutes restaurées de la mémoire de la carte graphique
	 * Seules les transformations suivantes sont appliqué : Translation, Rotation, Transformation
	 */
	virtual void FastDisplay();

	/**
	 * Permet de mettre à jour les pièces de la montre :
	 * - Met à jour l'heure en fonction du temps écoulé (Mise à jour de la rotation de l'engrenage central)
	 * - Met à jour la rotation des turbines (1 passe = 2 secondes)
	 */
	virtual void Update();

	/**
	 * Permet de mettre à jour la montre en fonction de l'heure passé en paramètre
	 * @heure : L'heure
	 * @minute : Le nombre de minute
	 * @seconde : Le nombre de secondes
	 */
	void SetHeure(int heure, int minute, int seconde);

	/**
	 * Permet de remonter l'heure
	 * 1 seconde devient 1 minute
	 * @reverse : Permet de choisir le sens (horraire ou trigonométrique)
	 */
	void Remonter(bool reverse = false);

	/*
	 * Permet de changer le fond
	 * id : Identifiant de la texture
	 */
	void SetBackground(int id);

	/** 
	 * Permet d'afficher uniquement le mécanisme
	 */
	void ShowMecanisme(bool show);

	/**
	 * Permet de savoir si l'utilisateur est en train de remonter la montre
	 * Retourne Vrai si il la remonte
	 */
	bool IsUserChanging();

	/**
	 * Permet de'activer la modification de la montre par l'utilisateur
	 */
	void SetUserChanging(bool val);

private:

	/**
	 * Retourne la rotation d'un cube heure en fonction de la rotation global
	 * cubeAxe : numéro du cube
	 */
	float GetCurrentHourRotation(int cubeAxe);

	/**
	 * Construit la base supérieur
	 * rotation : Rotation globale
	 */
	void BuildStructureSuperieure(float rotation);

	/**
	 * Construit la base inférieur, jusquau secondes
	 * rotation : Rotation globale
	 */
	void BuildStructureSecondesInferieure(float rotation);

	/**
	 * Construit la base inférieur, jusquau turbine
	 * rotation : Rotation globale
	 */
	void BuildStructureTurbineInferieure(float rotation);

	/**
	 * Construit la structure intermédiaire
	 * rotation : Rotation globale
	 */
	void BuildStructureIntermediaire();
};
#endif