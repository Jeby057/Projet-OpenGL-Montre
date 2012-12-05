#ifndef TIME_H
#define TIME_H

#include <Windows.h>



class Time
{
private:

	SYSTEMTIME _time;
	bool _isRunning;
	int _scale;

public:
	Time();
	~Time();

	void Start();
	void Update();
	void Stop();
	SYSTEMTIME GetInterval();
	static SYSTEMTIME GetSystemGMTTime();
	void SetScale(int scale);
	SYSTEMTIME ApplyScale(SYSTEMTIME);
};
#endif
