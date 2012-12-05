#ifndef SCENARIO_H
#define SCENARIO_H

#include "TrackBallCamera.h"

class ScenarioCamera
{
protected:
	TrackBallCamera* _camera;
	bool _finised;


public:
	ScenarioCamera(TrackBallCamera* camera);
	virtual ~ScenarioCamera(void);
	virtual void Update() = 0;
};
#endif
