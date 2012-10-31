#ifndef TRACKBALL_CAMERA_H
#define TRACKBALL_CAMERA_H

#include "Include.h"
class TrackBallCamera
{
	public:
    TrackBallCamera();

    virtual void OnMouseMotion(const int x, const int y);
    virtual void OnMouseButton(int button, int state,int x,int y);
	virtual void OnKeyboard(unsigned char key,int x,int y);

    virtual void Look();
    virtual void SetMotionSensivity(double sensivity);
    virtual void SetScrollSensivity(double sensivity);

    virtual ~TrackBallCamera();
protected:
    double _motionSensivity;
    double _scrollSensivity;
	double _offsetSensivity;
    bool _tracked, _moved;
    double _distance;
    double _angleY, _angleZ;
    double _oldX, _oldY;
    double _offsetZ, _offsetY;
};

#endif