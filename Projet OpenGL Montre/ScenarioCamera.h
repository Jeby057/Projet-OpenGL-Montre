/**
 * Classe ScenarioCamera
 * *********************
 * Classe abstraite permettant de générer des scénarios de déplacement de caméra
 * Il faut hérité de celle-ci pour creer un nouveau scénario
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 2 Décembre 2012
 * Version : 1
 */
#ifndef SCENARIO_H
#define SCENARIO_H

#include "TrackBallCamera.h"

class ScenarioCamera
{
protected:
	// Camera utilisé
	TrackBallCamera* _camera;

	// Permet de savoir si l'animation est terminé
	bool _finised;

public:

	/**
	 * Constructeur de ScenarioCamera
	 * camera : Camera à déplacer
	 */
	ScenarioCamera(TrackBallCamera* camera);

	/**
	 * La caméra ne sera pas désaloué ici!
	 */
	virtual ~ScenarioCamera(void);

	/**
	 * Callback à appeler afin de mettre à jour le scénario
	 */
	virtual void Update() = 0;
};
#endif
