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
	virtual void SetOffsetSensivity(double sensivity);
	virtual void SetTargetMoveSensivity(double);
	virtual void SetFrameSize(int width, int height);
	virtual void Update();
	virtual void Rotate(double x, double y);
	virtual void Translate(double x, double y);

	void SetTarget(Point3D target);
	void SetDesiredDistance(double distance);
	void SetLocked(bool locked);
	bool IsDistanceJoined();


    virtual ~TrackBallCamera();
protected:
    double _motionSensivity;
    double _scrollSensivity;
	double _offsetSensivity;
	double _targetMovedSensivity;

    bool _tracked, _moved;
    double _distance;
    double _angleY, _angleZ;
    double _oldX, _oldY;
    double _offsetZ, _offsetY;
	int _width, _height;
	double _maxDistance;
	double _distanceDesired;
	Point3D _target;
	bool _locked;



};
#endif
