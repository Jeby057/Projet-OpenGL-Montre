/**
 * Classe ScenarioDemonstration
 * ****************************
 * Permet de g�n�rer un sc�nario de d�monstration pour la sc�ne
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 2 D�cembre 2012
 * Version : 1
 */
#ifndef SCENARIO_DEMO_H
#define SCENARIO_DEMO_H

#include "scenariocamera.h"
class ScenarioDemonstration :
	public ScenarioCamera
{
	// Cible � atteindre
	Point3D _desiredTarget;

	// Etat du sc�nario
	int _state;

public:

	/**
	 * Constructeur de ScenarioDemonstration
	 * camera : Camera � d�placer
	 */
	ScenarioDemonstration(TrackBallCamera* camera);
	virtual ~ScenarioDemonstration(void);
	virtual void Update();

	bool Pass1();
	bool Pass2();
	bool Pass3();
};
#endif
