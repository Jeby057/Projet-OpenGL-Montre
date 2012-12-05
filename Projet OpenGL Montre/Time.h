/**
 * Classe Time
 * ***********
 *  Permet de générer un timer
 *  Calcul l'interval de temps depuis la derniere mise à jour
 *  Lors d'une mise à jour, le timer est ré-initialiser
 *  Permet aussi d'accélérer le timer ou de le réduire grâce à scale
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifié le : 2 Décembre 2012
 * Version : 1
 */
#ifndef TIME_H
#define TIME_H

#include <Windows.h>

class Time
{
private:

	// Temps sauvegardé
	SYSTEMTIME _time;

	// Vrai si le timer est en cours d'éxécution
	bool _isRunning;

	// Accéléation du timer
	// *1 : Temps standard
	// >1 : Accélération, et inversement
	int _scale;

public:
	Time();
	~Time();

	/**
	 * Démarre le timer
	 */
	void Start();

	/**
	 * Met à jour la variable time
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
	 * Modifie le scaleTime permettant d'accélérer le temps
	 */
	void SetScale(int scale);

	/**
	 * Permet d'appliquer le scale sur une SystemTime et retourne le SystemTime correspondant
	 */
	SYSTEMTIME ApplyScale(SYSTEMTIME);
};
#endif
