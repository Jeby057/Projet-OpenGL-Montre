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
	_desiredTarget = Point3D(0, 0, 12);
	_camera->SetDesiredDistance(3.5);
	_camera->Rotate(0, -1);
	return (_camera->GetAngleZ() <= -120);
}

bool ScenarioDemonstration::Pass2()
{	
	_desiredTarget = Point3D(0, 0, 12);
	_camera->SetDesiredTarget(_desiredTarget);
	_camera->SetDesiredDistance(1);
	return false;
}

bool ScenarioDemonstration::Pass3()
{
	return false;
}