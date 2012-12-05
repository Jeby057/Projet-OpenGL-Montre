/**
 * Classe ScenarioDemonstration
 * ****************************
 * Permet de générer un scénario de démonstration pour la scène
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 2 Décembre 2012
 * Version : 1
 */
#ifndef SCENARIO_DEMO_H
#define SCENARIO_DEMO_H

#include "scenariocamera.h"
class ScenarioDemonstration :
	public ScenarioCamera
{
	// Cible à atteindre
	Point3D _desiredTarget;

	// Etat du scénario
	int _state;

public:

	/**
	 * Constructeur de ScenarioDemonstration
	 * camera : Camera à déplacer
	 */
	ScenarioDemonstration(TrackBallCamera* camera);
	virtual ~ScenarioDemonstration(void);
	virtual void Update();

	bool Pass1();
	bool Pass2();
	bool Pass3();
};
#endif
