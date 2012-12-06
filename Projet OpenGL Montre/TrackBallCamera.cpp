#include "TrackBallCamera.h"


TrackBallCamera::TrackBallCamera(void)
{
	_tracked = false;
	_moved = false;
    _angleY = 0;
    _angleZ = -45;
	_offsetZ = 0;
	_offsetY = 0;
    _distance = 1.1; 
	_distanceDesired = _distance;
    _motionSensivity = 0.3;
    _scrollSensivity = 1;
    _offsetSensivity = 0.1;
	_targetMovedSensivity = 0.1;
	_maxDistance = 14;
	_target = Point3D(0,0,0);
	_desiredTarget = _target;
	_locked = false;
}


TrackBallCamera::~TrackBallCamera(void)
{
}


void TrackBallCamera::OnMouseMotion(const int x, const int y)
{
	if(_locked)
		return;

	// Si le drag est en cours
    if (_tracked)
    {
		// On calcule l'angle de rotation en fonction de la position de la sourie
        _angleZ += (x - _oldX) * _motionSensivity;
        _angleY += (y - _oldY) * _motionSensivity;
    }

	if(_moved)
	{
		_offsetY += (x - _oldX) *  _offsetSensivity;
		_offsetZ += (y - _oldY) * _offsetSensivity;
	}
    _oldX = x;
	_oldY = y;
}

void TrackBallCamera::OnMouseButton(int button, int state,int x,int y)
{
	if(_locked)
		return;

	// On change le boolean en fonction de l'état de la sourie
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		_tracked = true;
		_oldX = x;
		_oldY = y;
	}
	else
		_tracked = false;

	// Si il y a un clic sur la molette, on ré-initialise les angles
	if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
		_moved = true;
		_oldX = x;
		_oldY = y;
	}
	else
		_moved = false;
}

void TrackBallCamera::OnKeyboard(unsigned char key,int x,int y){

	if(_locked)
		return;

	// Si il y a un coup de molette vers le haut
	if ( key == '+' )
    {
		// On diminue la distance
        _distance -= _scrollSensivity;
		_distanceDesired -= _scrollSensivity;
    }

	// Si il y a un coup de molete vers le bas
    else if (key == '-' && abs(_distance) < _maxDistance)
    {
		// Augmentation de la distance
        _distance += _scrollSensivity;
		_distanceDesired += _scrollSensivity;
    }
}


void TrackBallCamera::Look()
{
	// Projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0,1.0*(GLfloat)_width/(GLfloat)_height,0.5,30.0);
	glMatrixMode(GL_MODELVIEW);

	// Caméra
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );
    gluLookAt(_distance,0,0,_target._x, _target._y, _target._z,0,1,0);
	glTranslatef(0.0, -_offsetZ, _offsetY);
    glRotated(-_angleY,0,0,1); 
    glRotated(_angleZ,0,1,0);
}

void TrackBallCamera::SetMotionSensivity(double sensivity){
	_motionSensivity = sensivity;
}

void TrackBallCamera::SetScrollSensivity(double sensivity){
	_scrollSensivity = sensivity;
}

void TrackBallCamera::SetOffsetSensivity(double sensivity){
	_offsetSensivity = sensivity;
}

void TrackBallCamera::SetTargetMoveSensivity(double sensivity){
	_targetMovedSensivity = sensivity;
}

void TrackBallCamera::Rotate(double x, double y)
{
	_angleZ += y;
	_angleY += x;
}

void TrackBallCamera::Translate(double x, double y)
{
	_offsetZ += y;
	_offsetY += x;
}

void TrackBallCamera::SetFrameSize(int width, int height)
{
	_width = width;
	_height = height;
	glViewport(0,0,_width,_height);
}

void TrackBallCamera::Update()
{
	// Animation de la distance
	if(!IsDistanceJoined())
		_distance += (_distance >_distanceDesired) ? -_targetMovedSensivity : +_targetMovedSensivity;

	// Cible X
	if(_desiredTarget._x >= _target._x + _targetMovedSensivity || _desiredTarget._x <= _target._x - _targetMovedSensivity)
		_target._x += (_desiredTarget._x > _target._x) ? _targetMovedSensivity : -_targetMovedSensivity;
	
	// Cible Y
	if(_desiredTarget._y >= _target._y + _targetMovedSensivity || _desiredTarget._y <= _target._y - _targetMovedSensivity)
		_target._y += (_desiredTarget._y > _target._y) ? _targetMovedSensivity : -_targetMovedSensivity;
	
	// Cible Z
	if(_desiredTarget._z >= _target._z + _targetMovedSensivity || _desiredTarget._z <= _target._z - _targetMovedSensivity)
		_target._z += (_desiredTarget._z > _target._z) ? _targetMovedSensivity : -_targetMovedSensivity;
}

void TrackBallCamera::SetTarget(Point3D target)
{
	_target = target;
}

void TrackBallCamera::SetLocked(bool locked)
{
	_locked = locked;
}

void TrackBallCamera::SetDesiredDistance(double distance)
{
	_distanceDesired = distance;
}

bool TrackBallCamera::IsDistanceJoined()
{
	return(_distanceDesired <= _distance + _targetMovedSensivity && _distanceDesired >= _distance - _targetMovedSensivity);
}

void TrackBallCamera::SetDesiredTarget(Point3D desiredTarget)
{
	_desiredTarget = desiredTarget;
}

double TrackBallCamera::GetAngleY()
{
	return _angleY;
}

double TrackBallCamera::GetAngleZ()
{
	return _angleZ;
}

double TrackBallCamera::GetOffsetY()
{
	return _offsetY;
}

double TrackBallCamera::GetOffsetZ()
{
	return _offsetZ;
}