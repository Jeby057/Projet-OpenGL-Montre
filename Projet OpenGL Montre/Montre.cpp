#include "Montre.h"


Montre::Montre(void)
{
	// R�cup�rtion de l'heure systeme
	GetSystemTime(&_oldMilliSecondsTime);
	GetSystemTime(&_oldSecondsTime);

	// Initialisation de la montre � l'heure du syst�me
	SetHeure(_oldMilliSecondsTime.wHour, _oldMilliSecondsTime.wMinute, _oldMilliSecondsTime.wSecond);

	// Set scale � 1 (montre en temps r�el)
	_scaleTime = 2;

	//L'utilisateur n'est pas en train de changer l'heure
	_inUserChanging = false;

	_displayMecanismeOnly = false;

	// Cr�ation des engrenages
	

	_engrenage_M0p01_0p255 = new Engrenage(0.01, 255*0.01, 0.045, 1);
	_engrenage_M0p01_0p255->BuildAndSave();

	// Petit engrenage plateau & engrenage finaux
	_engrenage_M0p01_0p85 = new Engrenage(0.01, 85*0.01, 0.045, 1);
	_engrenage_M0p01_0p85->BuildAndSave();

	// Engrenages interm�diaires
	_engrenage_M0p01_0p25 = new Engrenage(0.01, 25*0.01, 0.045, 1);
	_engrenage_M0p01_0p25->BuildAndSave();

	_engrenage_M0p01_0p15G = new Engrenage(0.01, 15*0.01, 0.045*2 + 0.01 * 2, 1);
	_engrenage_M0p01_0p15G->BuildAndSave();

	_engrenage_M0p01_0p15 = new Engrenage(0.01, 15*0.01, 0.045, 1);
	_engrenage_M0p01_0p15->BuildAndSave();

	_engrenage_M0p01_0p75 = new Engrenage(0.01, 75*0.01, 0.045, 1);
	_engrenage_M0p01_0p75->BuildAndSave();

	_engrenage_M0p01_0p60 = new Engrenage(0.01, 60*0.01, 0.045, 1);
	_engrenage_M0p01_0p60->BuildAndSave();

	_engrenage_M0p01_0p5 = new Engrenage(0.01, 5*0.01, 0.045, 1);
	_engrenage_M0p01_0p5->BuildAndSave();

	// Cr�ation de la piece maitresse
	_maitresse = new Maitresse(0.15, 0.15, 0.15, 0.35, 0.045, 0.45, 0.8 );
	_maitresse->BuildAndSave();

	// Plaque de s�paration
	 char* namFace[2];
	 for(int i=0; i<2; i++)
		namFace[i] = new char[12];
	 
	 sprintf(namFace[0],"%s", "carbone.ppm");
	 sprintf(namFace[1],"%s", "pamela.ppm");
	 _plaqueSeparation = new PlaqueSeparation(0.025, 3.2 + 0.4, 5.2, 0.65, namFace, 2);
	 _plaqueSeparation->BuildAndSave();
	 
	 for(int i=0; i<2; i++)
		delete namFace[i];

	 // Sur-rotor central
	 _surCentralRotor = new PieceCentreMontre(0.4, 0.15); 
	 _surCentralRotor->BuildAndSave();

	// Rotor pi�ce maitresse
	_rotorPieceMaitresse = new PartialDisque(0, 0.3, 0.46 + (0.045 + 0.0125) * 5 + 0.025, 50, 360);
	_rotorPieceMaitresse->BuildAndSave();

	// Caches engrenages
	_cacheEngrenage = new CacheEngrenage(0.8/3, 0.8, 50, 0.045, 240, 0.045/2, 0.045/2);
	_cacheEngrenage->BuildAndSave();

	// Cadres horraires
	 _pointeurHorraire = new EntourantCube(0.45, 0.08, 0.27, 0.05, 0.085, 0.07, 0.37, 0.5, 0.175);
	 _pointeurHorraire->BuildAndSave();

	 // Indicateur des minutes
	 _indicateurMin = new IndicateurMins(0.35, 0.085, 0.085, 0.55, 0.01, 0.01);
	 _indicateurMin->BuildAndSave();

	 // Rotor Engrenage final
	 _rotorEngrenageFinal = new PartialDisque(0, 0.8/4, 0.065+0.018, 50, 360);
	 _rotorEngrenageFinal->BuildAndSave();

	 _rotorEngrenageReductionHeureMin = new PartialDisque(0, 0.06, 0.045 + 0.025 + 0.005, 50, 360);
	 _rotorEngrenageReductionHeureMin->BuildAndSave();

	 _rotorEngrenageSecondes = new PartialDisque(0, 0.025, (0.045 + 0.01) + 0.025 + 0.01, 50, 360);
	 _rotorEngrenageSecondes->BuildAndSave();

	 _rotorInferieur = new PartialDisque(0, 0.3/1.8, (0.045 + 0.0125) * 5 + 0.025 + 0.01 *2, 50, 360);
	 _rotorInferieur->BuildAndSave();

	 _aiguillesSecondes = new AiguillesSec(0.31, 0.08, 0.02);
	 _aiguillesSecondes->BuildAndSave();

	 _turbine = new PieceVentilo(60*0.01/2/4, 60*0.01 / 2, 0.045 *5);
	 _turbine->BuildAndSave();

	 _disqueSecondes = new PieceSeconde(0.31 + 0.08 * 1.5, 0.01);
	 _disqueSecondes->BuildAndSave();

	 _armature = new Armature(5.5, 4.5 + 0.5, 0.75);
	 _armature->BuildAndSave();

	 _contenantTurbine = new ContenantTurbine(60*0.01, (0.045 + 0.01));
	 _contenantTurbine->BuildAndSave();
	 (0.5, 1, 1, 0.2, 0.2, 0.5);

	 _blocMinute = new BlocMinute(4.6/3.35, 2, 1.8, 0.9, 0.9, 0.3);
	 _blocMinute->BuildAndSave();

	 // Cube heure
	 for(int cube=0; cube<3; cube++)
	 {
		 char* namFace[6];
		 for(int i=0; i<6; i++)
			 namFace[i] = new char[7];

		 sprintf(namFace[0],"%i.ppm", 7+cube);
		 sprintf(namFace[1],"%i.ppm", 4+cube);
		 sprintf(namFace[2],"%i.ppm", 1+cube);
		 sprintf(namFace[3],"%i.ppm", 10+cube);
	     sprintf(namFace[4],"%i.ppm", 13);
		 sprintf(namFace[5],"%i.ppm", 14);

		 _cubeHeure[cube] = new CubeHeure(0.17 ,namFace);
		 _cubeHeure[cube]->BuildAndSave();

		 for(int i=0; i<6; i++)
			delete namFace[i];
	 }

	 // Rotor Cube Heure
	 _rotorCubeHeure = new PartialDisque(0, 0.17/2.5, 0.27*2 + 0.085 + 0.07 + 0.05, 50, 360);
	 _rotorCubeHeure->BuildAndSave();

	 _connectorCubeHeure = new Connector(0.17/3, 0.17/1.2);
	 _connectorCubeHeure->BuildAndDisplay();
}


Montre::~Montre(void)
{
	delete _engrenage_M0p01_0p255;
	delete _engrenage_M0p01_0p85;
	delete _engrenage_M0p01_0p25;	
	delete _engrenage_M0p01_0p75;	
	delete _engrenage_M0p01_0p15; 
	delete _engrenage_M0p01_0p15G;	
	delete _engrenage_M0p01_0p60;	
	delete _engrenage_M0p01_0p5;
	delete _maitresse;
	delete _cacheEngrenage;
	delete _pointeurHorraire;
	delete _indicateurMin;
	delete _rotorEngrenageFinal;
	delete _rotorCubeHeure;	
	delete _rotorPieceMaitresse;
	delete _rotorEngrenageSecondes;
	delete _rotorEngrenageReductionHeureMin;
	delete _rotorInferieur;	
	delete _plaqueSeparation;
	delete _surCentralRotor;
	delete _aiguillesSecondes;
	delete _disqueSecondes;
	delete _turbine;
	delete _connectorCubeHeure;
	delete _armature;
	delete _contenantTurbine;
	delete _blocMinute;
	for(int cube=0; cube<3; cube++)
		delete _cubeHeure[cube];
	delete _cubeHeure[3];
}

void Montre::BuildAndDisplay()
{
	// Appel de FastDisplay car il n'y a pas de 
	// construction de pi�ce supl�mentaire
	FastDisplay();
}

void Montre::BuildAndSave()
{
	// Il y a seulement des modification de taille, de position et de rotation 
	// Il n'y a pas de cr�ation d'objets
	// Il n'y a donc pas d'objets � sauvegarder en m�moires
}

void Montre::FastDisplay()
{
	// Ratio sous engrenage (3H) principale vers engrenage de r�duction (1H)
	float ratio_0p255_0p60 = 255.0 / 60.0;
	float ratio_0p75_0p25 = 75.0 / 25.0;
	float ratio_0p75_0p15 = 75.0 / 15.0;
	float ratio_0p60_0p5 = 60.0 / 5.0;


	glPushMatrix();
		// Structure sup�rieur
		glPushMatrix();
			glTranslatef(0, 0.05, 0);

			// Boite minute
			if(!_displayMecanismeOnly){
				glPushMatrix();
					glRotatef(180, 0, 1, 0);
					glTranslatef(0.325, 0.0, 0.0);
					_blocMinute->FastDisplay();
				glPopMatrix();
			}

			BuildStructureSuperieur(_rotation);
		glPopMatrix();

		// Structure inf�rieure
		glPushMatrix();

			// Plaque de s�paration
			glTranslatef(0.2, -0.045 -0.025, 0);
			
			if(!_displayMecanismeOnly){
				glPushMatrix();
					glTranslatef(-0.35, 0, 0);
					glRotatef(180, 0, 1, 0);
					_plaqueSeparation->FastDisplay();
				glPopMatrix();
			}

			// Pilier de soutien
			for(int i=0; i<4; i++)
			{
				Material mat = Material();
				mat.ToBlackReflect();
				mat.Enable();
				glPushMatrix();
					glTranslatef((i%2?1:-1)*1.15, 0.02, (i%3?1:-1)*1.15);
					glRotatef(90, 1, 0, 0);
					_rotorInferieur->FastDisplay();
				glPopMatrix();
			}
			// Translation pour positionner les engrenages
			glTranslatef(0, -0.01 * 2 -0.045, 0);

			glPushMatrix();
				// Sous engrenage (3H) -> Vers secondes
				glPushMatrix();
					glRotatef(_rotation, 0, 1, 0);
					_engrenage_M0p01_0p75->FastDisplay();
				glPopMatrix();

				glPushMatrix();
					glTranslatef(75*0.01/2 +25*0.01/2, 0, 0);
					float reduction = ratio_0p75_0p25;

					// Rotor de l'engrenage de r�duction
					glPushMatrix();
						glRotatef(-90, 1, 0, 0);
						_rotorEngrenageReductionHeureMin->FastDisplay();
					glPopMatrix();

					// Engrenage de r�duction (1H)
					glPushMatrix();
						glRotatef(-_rotation * reduction, 0, 1, 0);
						_engrenage_M0p01_0p25->FastDisplay();
					glPopMatrix();

					glPushMatrix();
						glTranslatef(25*0.01, -0.01, 0);

						// Rotor de l'engrenage conjoint de r�duction
						glPushMatrix();
							glRotatef(-90, 1, 0, 0);
							_rotorEngrenageReductionHeureMin->FastDisplay();
						glPopMatrix();

						// Engrenage conjoint de r�duction (1H)
						glPushMatrix();
							glRotatef(_rotation * reduction, 0, 1, 0);
							_engrenage_M0p01_0p25->FastDisplay();
						glPopMatrix();

						glPushMatrix();
							glTranslatef(0, - 0.045, 0);
						
							// Sous engrenage (R�duction 1H)
							glPushMatrix();
								glRotatef(_rotation * reduction, 0, 1, 0);
								_engrenage_M0p01_0p75->FastDisplay();
							glPopMatrix();

							glPushMatrix();
								glTranslatef(75*0.01/2 +15*0.01/2, 0, 0);
								reduction *= ratio_0p75_0p15;
							
								// Engrenange de r�duction (12min)
								glPushMatrix();
									glTranslatef(0, 0.045 + 0.01 * 2, 0);
									glRotatef(-_rotation * reduction, 0, 1, 0);
									_engrenage_M0p01_0p15G->FastDisplay();
								glPopMatrix();

								glPushMatrix();
									glTranslatef(0, (0.045 + 0.01)*2, 0);
								
									// Sur Engrenange de r�duction (12min)
									glPushMatrix();
										glRotatef(-_rotation * reduction, 0, 1, 0);
										_engrenage_M0p01_0p60->FastDisplay();
									glPopMatrix();

								
									glPushMatrix();
										reduction *= ratio_0p60_0p5;
										glTranslatef(-60*0.01/2 - 5*0.01/2, 0, 0);
									
										// Engrenange de r�duction (1min) (sens horraire)
										glPushMatrix();

											// Disque des secondes
											glPushMatrix();
												glTranslatef(0,0.025,0);
												_disqueSecondes->FastDisplay();
											glPopMatrix();


											glRotatef(_rotation * reduction + 3.5, 0, 1, 0);
											_engrenage_M0p01_0p5->FastDisplay();
										
											// Rotor des secondes
											glTranslatef(0,-0.045 + 0.01,0);
											glPushMatrix();
												glRotatef(-90, 1, 0, 0);
												_rotorEngrenageSecondes->FastDisplay();
											glPopMatrix();

											// Aiguilles des secondes
											glPushMatrix();
												glTranslatef(0,(0.045 + 0.01 * 1.5) + 0.025,0);
												_aiguillesSecondes->FastDisplay();
											glPopMatrix();
										glPopMatrix();
									glPopMatrix();
								glPopMatrix();
							glPopMatrix();
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();

				// Etage inf�rieur -> Engrenages vers turbines
				glPushMatrix();
					glTranslatef(0, -(0.045 + 0.01)*2, 0);

					// Sous engrenage (3H) -> Vers turbines
					glPushMatrix();
						glRotatef(_rotation, 0, 1, 0);
						_engrenage_M0p01_0p255->FastDisplay();
					glPopMatrix();

					// D�placement vers le m�canisme des turbines
					glPushMatrix();
						glTranslatef(-255*0.01/2 - 60*0.01/2, 0, 0);

						// Engrenage turbine central
						glPushMatrix();
							glRotatef(-_rotation * ratio_0p255_0p60, 0, 1, 0);
							_engrenage_M0p01_0p60->FastDisplay();
						glPopMatrix();

						// Engrenages sup�rieurs turbines
						glPushMatrix();
							glTranslatef(0, (0.045 + 0.01)*3 -0.01, 0);

							// Engrenage turbine central
							glPushMatrix();
								glRotatef(-_rotation * ratio_0p255_0p60, 0, 1, 0);
								_engrenage_M0p01_0p60->FastDisplay();
								glPushMatrix();
									glTranslatef(0, 0.045 , 0);
									glRotatef(90, 1, 0, 0);
									_rotorInferieur->FastDisplay();
								glPopMatrix();
							glPopMatrix();

							// Engrenage turbine gauche
							glPushMatrix();
								glTranslatef(0, 0, - 60*0.01);
								glRotatef(_rotation * ratio_0p255_0p60 - 2.5, 0, 1, 0);
								_engrenage_M0p01_0p60->FastDisplay();

								// Turbine
								glPushMatrix();
									glRotatef(-_rotation * ratio_0p255_0p60 + 2.5, 0, 1, 0);
									glTranslatef(0, (-0.045 - 0.01)*2, 0);
									glPushMatrix();
										glRotatef(_rotationTurbine, 0, 1, 0);
										_turbine->FastDisplay();
									glPopMatrix();
									
									// Vitre turbine
									glPushMatrix();
										glTranslatef(0, (-0.045 )*4, 0);
										glRotatef(-90, 1, 0, 0);
										_contenantTurbine->FastDisplay();
									glPopMatrix();

								glPopMatrix();
							glPopMatrix();

							// Engrenage turbine droit
							glPushMatrix();
								glTranslatef(0, 0, 60*0.01);	
								glRotatef(_rotation * ratio_0p255_0p60 + 2.5, 0, 1, 0);
								_engrenage_M0p01_0p60->FastDisplay();
								
								// Turbine
								glPushMatrix();
									glRotatef(-_rotation * ratio_0p255_0p60 + 2.5, 0, 1, 0);
									glTranslatef(0, (-0.045 - 0.01)*2, 0);
									glPushMatrix();
										glRotatef(_rotationTurbine, 0, 1, 0);
										_turbine->FastDisplay();
									glPopMatrix();
									
									// Vitre turbine
									glPushMatrix();
										glTranslatef(0, (-0.045 )*4, 0);
										glRotatef(-90, 1, 0, 0);
										_contenantTurbine->FastDisplay();
									glPopMatrix();
								glPopMatrix();
							glPopMatrix();

						glPopMatrix();
					glPopMatrix();
				glPopMatrix();


			glPopMatrix();
		glPopMatrix();

		// Armature
		if(!_displayMecanismeOnly){
			glPushMatrix();
				glRotatef(-90, 1, 0, 0);
				glRotatef(180, 0, 0, 1);
				_armature->FastDisplay();
			glPopMatrix();

		}
	glPopMatrix();
}


void Montre::Update()
{
	// La mise � jour de la montre s'effectue uniquement si l'utilisateur 
	// n'est pas en train de modifier l'heure lui m�me
	if(!_inUserChanging)
	{
		// Calcul du nombre de tours effectu�s
		float nbTours = abs(_rotation)/360.0;
	
		// R�cup�ration de l'heure actuelle
		GetSystemTime(&_time);


		// On tourne dans le sens horraire
		float diffTime = 0;
		diffTime += (_time.wMilliseconds - _oldMilliSecondsTime.wMilliseconds) * DELTA_MILLISECONDE;
		diffTime += (_time.wSecond - _oldMilliSecondsTime.wSecond) * DELTA_SECONDE;
		diffTime += (_time.wMinute - _oldMilliSecondsTime.wMinute) * DELTA_MINUTE;
		diffTime += (_time.wHour - _oldMilliSecondsTime.wHour) * DELTA_HEURE;

		_rotation -= diffTime * _scaleTime;
		_oldMilliSecondsTime = _time;

		// Rotation de la turbine
		float diffTurbineTime = 0;
		diffTurbineTime += (_time.wMilliseconds - _oldSecondsTime.wMilliseconds) * DELTA_MILLISECONDE;
		diffTurbineTime += (_time.wSecond - _oldSecondsTime.wSecond) * DELTA_SECONDE;
		diffTurbineTime += (_time.wMinute - _oldSecondsTime.wMinute) * DELTA_MINUTE;
		diffTurbineTime += (_time.wHour - _oldSecondsTime.wHour) * DELTA_HEURE;

		if(diffTurbineTime >= DELTA_SECONDE * 2){
			_sensTurbine = !_sensTurbine;
			_oldSecondsTime = _time;
		}
		
		float scaleTurbinePass = 30;

		if(diffTurbineTime >= DELTA_SECONDE && diffTurbineTime <= DELTA_SECONDE * 1.9 )
			scaleTurbinePass = 20;

		if((diffTurbineTime >= DELTA_SECONDE * 0.9 && diffTurbineTime <= DELTA_SECONDE) || diffTurbineTime >= DELTA_SECONDE * 1.9)
			scaleTurbinePass = (_sensTurbine?-1:-0) * 20;
		
		_rotationTurbine += (_sensTurbine?1:-1) * scaleTurbinePass;

		// Quand l'on a fait 4 fois le tours : 12h en tout!
		if(nbTours >= 4)
			_rotation = 0;
	}
	else
	{
		_oldMilliSecondsTime = _time;
		_oldSecondsTime = _time;
	}
}

void Montre::BuildStructureSuperieur(float rotation)
{
	// Ratio engrenage principale vers bras des heures
	float ratio_0p85_0p25 = 85.0 / 25.0;

	// Structure compl�te
	glPushMatrix();

		// Engrenage principal
		glPushMatrix();
			glTranslatef(0, -0.01, 0);
			_engrenage_M0p01_0p85->FastDisplay();
		glPopMatrix();

		// Rotation de la structure compl�te
		glRotatef(rotation, 0, 1, 0);

		glPushMatrix();

			// Rotor structure principale du minutes heures
			glPushMatrix();
				glRotatef(90, 1, 0, 0);
				glTranslatef(0, 0, -0.045 * 2 - 0.15/2 - 0.15 - 0.025);
				_rotorPieceMaitresse->FastDisplay();
			glPopMatrix();

			// Sur-rotor central
			glPushMatrix();
				glRotatef(-30, 0, 1, 0);
				glRotatef(-90, 1, 0, 0);
				glTranslatef(0, 0, 0.045 * 2 + 0.15/2);
				_surCentralRotor->FastDisplay();
			glPopMatrix();

			// Piece maitresse
			glPushMatrix();
				glRotatef(-30, 0, 1, 0);
				_maitresse->FastDisplay();
			glPopMatrix();

			// Matrice des engrenages
			glPushMatrix();
				glTranslatef(0, -0.01, 0);

				// Parcours des bras m�caniques
				for(int iAxe = 0; iAxe<3; iAxe++)
				{
					// Placements des 3 axes
					glPushMatrix();
						glRotatef(iAxe*120, 0, 1, 0);

						// Engrenages interm�diaires
						// Rotation des engrenages interm�diaires
						glPushMatrix();
							glTranslatef(0.552, 0, 0);
							glRotatef(rotation * ratio_0p85_0p25 + iAxe*4, 0, 1, 0);
							_engrenage_M0p01_0p25->FastDisplay();
						glPopMatrix();

						// Engrenages finaux
						glPushMatrix();
							glTranslatef(1.11, 0, 0);
							
							// Rotation des engrenages 
							glPushMatrix();
								glRotatef(-rotation - iAxe*5, 0, 1, 0);
								_engrenage_M0p01_0p85->FastDisplay();
							glPopMatrix();

							// Plateau fixe
							glPushMatrix();
								glRotatef(-rotation - iAxe * 120, 0, 1, 0);
								
								// Cache engrenage
								glPushMatrix();
									glRotatef(-90, 1.0, 0.0, 0.0);

									// Rotor
									glPushMatrix();
										glTranslatef(0,0,0.045);
										_rotorEngrenageFinal->FastDisplay();
									glPopMatrix();

									// Cache
									glPushMatrix();
										glTranslatef(0,0,0.065);

										glPushMatrix();
											_cacheEngrenage->FastDisplay();
										glPopMatrix();

										// Pointeur horraire
										glPushMatrix();
											glRotatef(180, 0, 0, 1);

											// Cadre horraire
											glPushMatrix();
												glTranslatef(-0.8+0.08/2,-0.25,0.045+0.175);
												_pointeurHorraire->FastDisplay();
											glPopMatrix();
											
											// Cube heure
											glPushMatrix();
												glTranslatef(-0.27 - 0.085 - 0.07 - 0.05,0,0.17);
												glRotatef(GetCurrentHourRotation(iAxe), 1, 0, 0);
												_cubeHeure[iAxe]->FastDisplay();
											glPopMatrix();

											// Rotor Cube heure
											glPushMatrix();
												glTranslatef(-0.05,0,0.17);
												glRotatef(-90, 0, 1, 0);

												Material mat = Material();
												mat.ToBlackReflect();
												mat.Enable();
												_rotorCubeHeure->FastDisplay();

												glPushMatrix();
													glTranslatef(0,0,0.06);
													_connectorCubeHeure->BuildAndDisplay();
												glPopMatrix();

												glPushMatrix();
													glRotatef(180.0, 1,0,0);
													glTranslatef(0,0,-0.71);
													_connectorCubeHeure->BuildAndDisplay();
												glPopMatrix();
											glPopMatrix();
											
										glPopMatrix();

										// Pointeur mintute
										glPushMatrix();
											glTranslatef(0.03+0.085/2, 0.35/2, 0.045+0.175-0.085+0.05/2);
											glRotatef(180, 0, 0, 1);
											glRotatef(90, 1, 0, 0);
											_indicateurMin->FastDisplay();
										glPopMatrix();
									glPopMatrix();
								glPopMatrix();
							glPopMatrix();
						glPopMatrix();
					glPopMatrix();
				}
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

float Montre::GetCurrentHourRotation(int cubeAxe)
{
	// Calcul de la rotation relative
	int relativeRotation = (int)abs(_rotation) % 360;

	// Calcul de la position relative d'un cube heure
	float rotationGlobalHeure = (relativeRotation + 240 - (120 * cubeAxe)) % 360;

	// Calcul de la position absolue d'un cube heure
	// Il ne faut pas oublier de retrancher la tranche de rotation et l'ecart � la tranche (=60+30)
	// On retire aussi un delta = 1� afin de ne pas avoir de r�sultat visual innatendue
	float rotationAbsolueHeure = (abs(_rotation) + 240 - (120 * cubeAxe)) + 60 + 30 - 1;

	// Calcul du nombre de tours effectu�s par un cube heure
	float nbToursCubeHeure = abs(rotationAbsolueHeure)/360.0;

	// Si le cube heure se trouve dans la tranche de transition horraire
	float txRotationHeure = 0;
	float ecartRotationHeure = 60.0;
	if(rotationGlobalHeure <= 270 && rotationGlobalHeure >= 270-ecartRotationHeure)
	{
		// Calcul d'un taux de rotation dans l'�cart de transition horaire
		txRotationHeure = (ecartRotationHeure - (270 - rotationGlobalHeure)) / ecartRotationHeure;
	}

	// On retourne la rotation du cube actuelle
	return ((int)nbToursCubeHeure) * 90 + (90 * txRotationHeure);
}

void Montre::SetHeure(int heure, int minute, int seconde)
{
	_rotation = -(heure%12 * DELTA_HEURE + minute * DELTA_MINUTE + seconde * DELTA_SECONDE);
}

void Montre::Remonter(bool reverse)
{
	_rotation -= DELTA_MINUTE * (reverse?-1:1);
}


void Montre::SetBackground(int id)
{
	_plaqueSeparation->SetTexture(id);
}

void Montre::SetScaleTime(int scale)
{
	_scaleTime = scale;
}


void Montre::SetArmatureTransparency(float transparency)
{
	_armature->SetTransparency(transparency);
}


void Montre::ShowMecanisme(bool show){
	_displayMecanismeOnly = show;
}


bool Montre::IsUserChanging()
{
	return this->_inUserChanging;
}

void Montre::SetUserChanging(bool val)
{
	this->_inUserChanging = val;
}