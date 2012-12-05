/**
 * Classe Time
 * ***********
 *  Permet de g�n�rer un timer
 *  Calcul l'interval de temps depuis la derniere mise � jour
 *  Lors d'une mise � jour, le timer est r�-initialiser
 *  Permet aussi d'acc�l�rer le timer ou de le r�duire gr�ce � scale
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 2 D�cembre 2012
 * Version : 1
 */
#ifndef TIME_H
#define TIME_H

#include <Windows.h>

class Time
{
private:

	// Temps sauvegard�
	SYSTEMTIME _time;

	// Vrai si le timer est en cours d'�x�cution
	bool _isRunning;

	// Acc�l�ation du timer
	// *1 : Temps standard
	// >1 : Acc�l�ration, et inversement
	int _scale;

public:
	Time();
	~Time();

	/**
	 * D�marre le timer
	 */
	void Start();

	/**
	 * Met � jour la variable time
	 */
	void Update();

	/**
	 * Stop le timer
	 */ 
	void Stop();

	/**
	 * Retourne l'interval de temps entre le dernier update ou start et la date actuelle
	 */
	SYSTEMTIME GetInterval();

	/**
	 * Retourne l'heure systeme
	 */
	static SYSTEMTIME GetSystemGMTTime();

	/**
	 * Modifie le scaleTime permettant d'acc�l�rer le temps
	 */
	void SetScale(int scale);

	/**
	 * Permet d'appliquer le scale sur une SystemTime et retourne le SystemTime correspondant
	 */
	SYSTEMTIME ApplyScale(SYSTEMTIME);
};
#endif
