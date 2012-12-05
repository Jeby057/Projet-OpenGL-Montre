#ifndef SCENARIO_DEMO_H
#define SCENARIO_DEMO_H

#include "scenariocamera.h"
class ScenarioDemonstration :
	public ScenarioCamera
{
	Point3D _desiredTarget;
	int _state;

public:
	ScenarioDemonstration(TrackBallCamera* camera);
	virtual ~ScenarioDemonstration(void);
	virtual void Update();

	bool Pass1();
	bool Pass2();
	bool Pass3();
};
#endif
