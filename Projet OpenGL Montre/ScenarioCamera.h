/**
 * Classe ScenarioCamera
 * *********************
 * Classe abstraite permettant de g�n�rer des sc�narios de d�placement de cam�ra
 * Il faut h�rit� de celle-ci pour creer un nouveau sc�nario
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 2 D�cembre 2012
 * Version : 1
 */
#ifndef SCENARIO_H
#define SCENARIO_H

#include "TrackBallCamera.h"

class ScenarioCamera
{
protected:
	// Camera utilis�
	TrackBallCamera* _camera;

	// Permet de savoir si l'animation est termin�
	bool _finised;

public:

	/**
	 * Constructeur de ScenarioCamera
	 * camera : Camera � d�placer
	 */
	ScenarioCamera(TrackBallCamera* camera);

	/**
	 * La cam�ra ne sera pas d�salou� ici!
	 */
	virtual ~ScenarioCamera(void);

	/**
	 * Callback � appeler afin de mettre � jour le sc�nario
	 */
	virtual void Update() = 0;
};
#endif
