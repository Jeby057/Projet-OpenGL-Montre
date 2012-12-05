#include "Time.h"


Time::Time()
{
	_isRunning = false;
	_scale = 1;
}

Time::~Time()
{

}


void Time::Start()
{
	Update();
	_isRunning = true;
}

void Time::Update()
{
	GetLocalTime(&_time);
}

void Time::Stop()
{
	_isRunning = false;
}


SYSTEMTIME Time::GetSystemGMTTime()
{
	SYSTEMTIME time;
	GetLocalTime(&time);
	return time;
}

SYSTEMTIME Time::GetInterval()
{
	// Création de l'intervam
	SYSTEMTIME intervalTime;
	FILETIME intervalFileTime;

	// Récupération de l'heure locale
	SYSTEMTIME currentTime;
	GetLocalTime(&currentTime);

	// Création des filetimes permettant la comparaison
	FILETIME currentFileTime, oldFileTime;
	SystemTimeToFileTime( &currentTime, &currentFileTime );
    SystemTimeToFileTime( &_time, &oldFileTime );

	// Calcul de l'interval
	LARGE_INTEGER intervalLargeInt;
	intervalLargeInt.LowPart = currentFileTime.dwLowDateTime - oldFileTime.dwLowDateTime;
	intervalLargeInt.HighPart = currentFileTime.dwHighDateTime - oldFileTime.dwHighDateTime;
     
	//Perform arithmetic
	intervalFileTime.dwLowDateTime = intervalLargeInt.LowPart;
	intervalFileTime.dwHighDateTime = intervalLargeInt.HighPart;

	// Convertion en SystemTime
	FileTimeToSystemTime(&intervalFileTime, &intervalTime);

	// Application du scale
	return ApplyScale(intervalTime);
}

void Time::SetScale(int scale)
{
	_scale = scale;
}


SYSTEMTIME Time::ApplyScale(SYSTEMTIME time)
{
	// Application du scale
	time.wMilliseconds *= _scale;
	time.wSecond *= _scale;
	time.wMinute *= _scale;
	time.wHour *= _scale;
	time.wDay *= _scale;
	time.wDayOfWeek *= _scale;
	time.wMonth *= _scale;
	time.wYear *= _scale;
	return time;
}
