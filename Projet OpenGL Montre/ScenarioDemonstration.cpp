#include "ScenarioDemonstration.h"


ScenarioDemonstration::ScenarioDemonstration(TrackBallCamera* camera):ScenarioCamera(camera)
{
	_state = 1;
	_camera->SetTargetMoveSensivity(0.01);
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

		case 4:
			change = Pass4();
		break;

		default:
			_finised = true;
			_camera->SetLocked(false);
		break;
	}

	if(change)
		_state++;
}

bool ScenarioDemonstration::Pass1()
{
	_camera->SetDesiredDistance(3.5);
	_camera->Rotate(0, -0.5);
	return (_camera->GetAngleZ() <= -450);
}

bool ScenarioDemonstration::Pass2()
{	
	if(_camera->GetOffsetZ() < 6.5)
		_camera->Translate(0, 0.05);
	_camera->Rotate(0, -0.5);
	_camera->SetDesiredDistance(6.5);
	return (_camera->GetOffsetZ() >= 6.5 && _camera->GetAngleZ() <= -450*2 + 90);
}

bool ScenarioDemonstration::Pass3()
{
	_desiredTarget = Point3D(-6, 0, 0);
	_camera->SetDesiredTarget(_desiredTarget);
	_camera->SetTargetMoveSensivity(0.05);
	_camera->SetDesiredDistance(0);
	return _camera->IsDistanceJoined();
}

bool ScenarioDemonstration::Pass4()
{
	if(_camera->GetOffsetZ() > 0)
		_camera->Translate(0, -0.05);

	if(_camera->GetOffsetZ() < 3){
		_camera->SetDesiredDistance(4.5);
		_desiredTarget = Point3D(0, 0, 0);
		_camera->SetDesiredTarget(_desiredTarget);
	}
	return _camera->IsDistanceJoined() && _camera->GetOffsetZ() <= 0 && _camera->IsTargetJoined();
}