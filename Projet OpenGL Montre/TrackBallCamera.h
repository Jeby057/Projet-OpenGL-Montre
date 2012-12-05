/**
 * Classe TrackBallCamera
 * ***********************
 *  Permet de gérer la caméra de OpenGl
 *  Fonctionnalités :
 *   - Rotation autour d'une cible avec la sourie
 *   - Translation sur un plan
 *   - Zoom / Dé-zoom
 *   - Changer une cible de visée
 *   - Changer la distance à cette cible
 * 
 *  Utiliser Look pour utiliser la caméra dans le mainloop
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 2 Décembre 2012
 * Version : 1
 */
#ifndef TRACKBALL_CAMERA_H
#define TRACKBALL_CAMERA_H

#include "Include.h"
class TrackBallCamera
{
	public:
	/**
	 * Construit la caméra avec les paramètres par défaut
	 */
    TrackBallCamera();

	/**
	 * Permet d'utiliser les coordonnées souris pour éxécuter une rotation de la caméra
	 * x, y : Coordonnée de la souris
	 */
    virtual void OnMouseMotion(const int x, const int y);

	/**
	 * Permet d'utiliser les boutons de la souris pour le drag and drop de rotation et la translation
	 * button : Bouton cliqué
	 * state : Etat du bouton
	 * x, y : Coordonnées souris
	 */
    virtual void OnMouseButton(int button, int state,int x,int y);

	/**
	 * Permet d'utiliser les touchers clavier pour gérer le zoom
	 * key : Touche appuyée
	 * x, y : Coordonnées
	 */
	virtual void OnKeyboard(unsigned char key,int x,int y);

	/**
	 * Permet de placer la caméra
	 * Doit être utilisé dans le mainloop
	 */
    virtual void Look();

	/**
	 * Permet de modifier la sensibilité de la souris (rotation)
	 */
    virtual void SetMotionSensivity(double sensivity);

	/**
	 * Permet de modifier la sensibilité du zoom
	 */
    virtual void SetScrollSensivity(double sensivity);

	/**
	 * Permet de modifier la sensibilité de la translation
	 */
	virtual void SetOffsetSensivity(double sensivity);

	/**
	 * Permet de modifier la sensibilité de changement de cible
	 */
	virtual void SetTargetMoveSensivity(double);

	/**
	 * Permet de modifier la taille de la frame
	 * width, height : Largeur / Hauteur de la frame
	 */
	virtual void SetFrameSize(int width, int height);

	/**
	 * Met à jour les animations caméras
	 */
	virtual void Update();

	/**
	 * Permet de faire une rotation de la caméra
	 */
	virtual void Rotate(double x, double y);

	/**
	 * Pemet de faire une tranlation de la caméra
	 */
	virtual void Translate(double x, double y);

	/**
	 * Permet de selectionner une nouvelle cible
	 */
	void SetTarget(Point3D target);

	/**
	 * Permet de spécifier une distance désiré
	 * La caméra va automatique se déplacer vers la nouvelle distance
	 */
	void SetDesiredDistance(double distance);

	/**
	 * Permet de vérouiller les actions utilisateurs sur la caméra
	 * locked : Vrai pour vérouiller
	 */
	void SetLocked(bool locked);

	/**
	 * Retourne Vrai si la distance et la distance désiré sont de même ordre de grandeur
	 */
	bool IsDistanceJoined();

    virtual ~TrackBallCamera();
protected:

	// Sensibilités
    double _motionSensivity;
    double _scrollSensivity;
	double _offsetSensivity;
	double _targetMovedSensivity;

	// Permet de faire du drag and drop pour la rotation de la caméra
    bool _tracked, _moved;

	// Distance de la caméra
    double _distance;

	// Angle de rotation sur Y et Z
    double _angleY, _angleZ;

	// Ancienne position de la caméra
    double _oldX, _oldY;

	// Translation en offset
    double _offsetZ, _offsetY;

	// Taille de la frame
	int _width, _height;

	// Distance max de la caméra
	double _maxDistance;

	// Nouvelle distance désirée
	double _distanceDesired;

	// Cible de la caméra
	Point3D _target;

	// Vrai si les actions utilisateurs sont bloqués
	bool _locked;
};
#endif
