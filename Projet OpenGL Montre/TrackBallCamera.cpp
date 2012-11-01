#include "TrackBallCamera.h"


TrackBallCamera::TrackBallCamera(void)
{
	_tracked = false;
	_moved = false;
    _angleY = 0;
    _angleZ = 0;
	_offsetZ = 0;
	_offsetY = 0;
    _distance = 2; 
    _motionSensivity = 0.3;
    _scrollSensivity = 1;
    _offsetSensivity = 0.1;
}


TrackBallCamera::~TrackBallCamera(void)
{
}


void TrackBallCamera::OnMouseMotion(const int x, const int y)
{
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
	// Si il y a un coup de molette vers le haut
	if ( key == '+' )
    {
		// On diminue la distance
        _distance -= _scrollSensivity;
    }

	// Si il y a un coup de molete vers le bas
    else if (key == '-')
    {
		// Augmentation de la distance
        _distance += _scrollSensivity;
    }
}


void TrackBallCamera::Look()
{
    gluLookAt(_distance,0,0,0,0,0,0,0,1);
	glTranslatef(0.0, -_offsetY, _offsetZ);
    glRotated(_angleY,0,1,0); 
    glRotated(_angleZ,0,0,1);
}

void TrackBallCamera::SetMotionSensivity(double sensivity){
	_motionSensivity = sensivity;
}

void TrackBallCamera::SetScrollSensivity(double sensivity){
	_scrollSensivity = sensivity;
}