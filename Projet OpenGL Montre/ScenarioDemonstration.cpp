#include "ScenarioDemonstration.h"


ScenarioDemonstration::ScenarioDemonstration(TrackBallCamera* camera):ScenarioCamera(camera)
{
	_state = 1;
}


ScenarioDemonstration::~ScenarioDemonstration(void)
{
}

void ScenarioDemonstration::Update()
{
	bool change = false;
	switch(_state)
	{
		case 1:
			change = Pass1();
		break;

		case 2:
			change = Pass2();
		break;

		case 3:
			change = Pass3();
		break;

		default:
			_camera->SetLocked(false);
		break;
	}

	if(change)
		_state++;
}

bool ScenarioDemonstration::Pass1()
{
	_desiredTarget = Point3D(0, 0, 0);
	_camera->SetDesiredDistance(9.5);
	_camera->SetTarget(_desiredTarget);
	_camera->Rotate(0, 1);
	return _camera->IsDistanceJoined();
}

bool ScenarioDemonstration::Pass2()
{
	if(_desiredTarget._y <= 6){
		_desiredTarget._y += 0.1;
		_camera->Translate(0, 0.05);
		_camera->SetTarget(_desiredTarget);
	}
	return false;
}

bool ScenarioDemonstration::Pass3()
{
	return false;
}