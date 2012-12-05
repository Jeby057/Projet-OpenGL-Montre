/**
 * Classe TrackBallCamera
 * ***********************
 *  Permet de g�rer la cam�ra de OpenGl
 *  Fonctionnalit�s :
 *   - Rotation autour d'une cible avec la sourie
 *   - Translation sur un plan
 *   - Zoom / D�-zoom
 *   - Changer une cible de vis�e
 *   - Changer la distance � cette cible
 * 
 *  Utiliser Look pour utiliser la cam�ra dans le mainloop
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 2 D�cembre 2012
 * Version : 1
 */
#ifndef TRACKBALL_CAMERA_H
#define TRACKBALL_CAMERA_H

#include "Include.h"
class TrackBallCamera
{
	public:
	/**
	 * Construit la cam�ra avec les param�tres par d�faut
	 */
    TrackBallCamera();

	/**
	 * Permet d'utiliser les coordonn�es souris pour �x�cuter une rotation de la cam�ra
	 * x, y : Coordonn�e de la souris
	 */
    virtual void OnMouseMotion(const int x, const int y);

	/**
	 * Permet d'utiliser les boutons de la souris pour le drag and drop de rotation et la translation
	 * button : Bouton cliqu�
	 * state : Etat du bouton
	 * x, y : Coordonn�es souris
	 */
    virtual void OnMouseButton(int button, int state,int x,int y);

	/**
	 * Permet d'utiliser les touchers clavier pour g�rer le zoom
	 * key : Touche appuy�e
	 * x, y : Coordonn�es
	 */
	virtual void OnKeyboard(unsigned char key,int x,int y);

	/**
	 * Permet de placer la cam�ra
	 * Doit �tre utilis� dans le mainloop
	 */
    virtual void Look();

	/**
	 * Permet de modifier la sensibilit� de la souris (rotation)
	 */
    virtual void SetMotionSensivity(double sensivity);

	/**
	 * Permet de modifier la sensibilit� du zoom
	 */
    virtual void SetScrollSensivity(double sensivity);

	/**
	 * Permet de modifier la sensibilit� de la translation
	 */
	virtual void SetOffsetSensivity(double sensivity);

	/**
	 * Permet de modifier la sensibilit� de changement de cible
	 */
	virtual void SetTargetMoveSensivity(double);

	/**
	 * Permet de modifier la taille de la frame
	 * width, height : Largeur / Hauteur de la frame
	 */
	virtual void SetFrameSize(int width, int height);

	/**
	 * Met � jour les animations cam�ras
	 */
	virtual void Update();

	/**
	 * Permet de faire une rotation de la cam�ra
	 */
	virtual void Rotate(double x, double y);

	/**
	 * Pemet de faire une tranlation de la cam�ra
	 */
	virtual void Translate(double x, double y);

	/**
	 * Permet de selectionner une nouvelle cible
	 */
	void SetTarget(Point3D target);

	/**
	 * Permet de sp�cifier une distance d�sir�
	 * La cam�ra va automatique se d�placer vers la nouvelle distance
	 */
	void SetDesiredDistance(double distance);

	/**
	 * Permet de v�rouiller les actions utilisateurs sur la cam�ra
	 * locked : Vrai pour v�rouiller
	 */
	void SetLocked(bool locked);

	/**
	 * Retourne Vrai si la distance et la distance d�sir� sont de m�me ordre de grandeur
	 */
	bool IsDistanceJoined();

    virtual ~TrackBallCamera();
protected:

	// Sensibilit�s
    double _motionSensivity;
    double _scrollSensivity;
	double _offsetSensivity;
	double _targetMovedSensivity;

	// Permet de faire du drag and drop pour la rotation de la cam�ra
    bool _tracked, _moved;

	// Distance de la cam�ra
    double _distance;

	// Angle de rotation sur Y et Z
    double _angleY, _angleZ;

	// Ancienne position de la cam�ra
    double _oldX, _oldY;

	// Translation en offset
    double _offsetZ, _offsetY;

	// Taille de la frame
	int _width, _height;

	// Distance max de la cam�ra
	double _maxDistance;

	// Nouvelle distance d�sir�e
	double _distanceDesired;

	// Cible de la cam�ra
	Point3D _target;

	// Vrai si les actions utilisateurs sont bloqu�s
	bool _locked;
};
#endif
