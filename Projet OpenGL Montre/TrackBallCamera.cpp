#include "TrackBallCamera.h"


TrackBallCamera::TrackBallCamera(void)
{
	_tracked = false;
	_moved = false;
    _angleY = 10;
    _angleZ = -125;
	_offsetZ = 0;
	_offsetY = 0;
    _distance = 9.5; 
    _motionSensivity = 0.3;
    _scrollSensivity = 1;
    _offsetSensivity = 0.1;
	_maxDistance = 9.5;
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
    else if (key == '-' && abs(_distance) < _maxDistance)
    {
		// Augmentation de la distance
        _distance += _scrollSensivity;
    }
}


void TrackBallCamera::Look()
{
	// Projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0,1.0*(GLfloat)_width/(GLfloat)_height,1.0,30.0);
	glMatrixMode(GL_MODELVIEW);

	// Caméra
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );
    gluLookAt(_distance,0,0,0,0,0,0,1,0);
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

void TrackBallCamera::SetFrameSize(int width, int height)
{
	_width = width;
	_height = height;
	glViewport(0,0,_width,_height);
}