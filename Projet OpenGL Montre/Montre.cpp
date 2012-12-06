#include "Montre.h"


Montre::Montre(Time* time)
{
	// On pointe sur le timer
	_time = time;

	// Récupértion de l'heure systeme
	SYSTEMTIME systemTime = Time::GetSystemGMTTime();

	// Initialisation de la montre à l'heure du système
	SetHeure(systemTime.wHour, systemTime.wMinute, systemTime.wSecond);

	//L'utilisateur n'est pas en train de changer l'heure
	_inUserChanging = false;

	_fractal = 0;
	_displayMecanismeOnlyProcessing = false;

	_displayMecanismeOnly = false;

	// Création des engrenages
	

	_engrenage_M0p01_0p255 = new Engrenage(0.01, 255*0.01, 0.045, 1);
	_engrenage_M0p01_0p255->BuildAndSave();

	// Petit engrenage plateau & engrenage finaux
	_engrenage_M0p01_0p85 = new Engrenage(0.01, 85*0.01, 0.045, 1);
	_engrenage_M0p01_0p85->BuildAndSave();

	// Engrenages intermédiaires
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

	// Création de la piece maitresse
	_maitresse = new Maitresse(0.15, 0.15, 0.15, 0.35, 0.045, 0.45, 0.8 );
	_maitresse->BuildAndSave();

	// Plaque de séparation
	 char* namFace[3];
	 for(int i=0; i<3; i++)
		namFace[i] = new char[12];
	 
	 sprintf(namFace[0],"%s", "carbone.ppm");
	 sprintf(namFace[1],"%s", "pamela.ppm");
	 sprintf(namFace[2],"%s", "galets.ppm");
	 _plaqueSeparation = new PlaqueSeparation(0.025, 3.2 + 0.4, 5.2, 0.65, namFace, 3);
	 _plaqueSeparation->BuildAndSave();
	 
	 for(int i=0; i<3; i++)
		delete namFace[i];

	 // Sur-rotor central
	 _surCentralRotor = new PieceCentreMontre(0.4, 0.15); 
	 _surCentralRotor->BuildAndSave();

	// Rotor pièce maitresse
	_rotorPieceMaitresse = new PartialDisque(0, 0.3, 0.46 + (0.045 + 0.0125) * 5 + 0.025, 50, 360);
	_rotorPieceMaitresse->BuildAndSave();

	// Caches engrenages
	_cacheEngrenage = new CacheEngrenage(0.8/3, 0.8, 50, 0.045, 240, 0.045/2, 0.045/2);
	_cacheEngrenage->BuildAndSave();

	// Cadres horraires
	 _pointeurHorraire = new EntourantCube(0.45, 0.08, 0.27, 0.05, 0.085, 0.07, 0.37, 0.5, 0.175);
	 _pointeurHorraire->BuildAndSave();

	 // Indicateur des minutes
	 _indicateurMin = new IndicateurMins(0.265, 0.085, 0.085, 0.35, 0.01, 0.01);
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

	 _chiffre0 = new PieceChiffres(0.15, 0);
	 _chiffre15 = new PieceChiffres(0.15, 1, 5);
	 _chiffre30 = new PieceChiffres(0.15, 3, 0);
	 _chiffre45 = new PieceChiffres(0.15, 4, 5);
	 _chiffre60 = new PieceChiffres(0.15, 6, 0);
	 _chiffre0->BuildAndSave();
	 _chiffre15->BuildAndSave();
	 _chiffre30->BuildAndSave();
	 _chiffre45->BuildAndSave();
	 _chiffre60->BuildAndSave();


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

	 // On lance l'annimation des turbines
	 _turbineTime.Start();
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
	delete _chiffre0;
	delete _chiffre15;
	delete _chiffre30; 
	delete _chiffre45; 
	delete _chiffre60;
	for(int i=0; i<3; i++)
		delete _cubeHeure[i];
}

void Montre::BuildAndDisplay()
{
	// Appel de FastDisplay car il n'y a pas de 
	// construction de pièce suplémentaire
	FastDisplay();
}

void Montre::BuildAndSave()
{
	// Il y a seulement des modification de taille, de position et de rotation 
	// Il n'y a pas de création d'objets
	// Il n'y a donc pas d'objets à sauvegarder en mémoires
}

void Montre::FastDisplay()
{
	// Ratio sous engrenage (3H) principale vers engrenage de réduction (1H)
	float ratio_0p255_0p60 = 255.0 / 60.0;
	float ratio_0p75_0p25 = 75.0 / 25.0;
	float ratio_0p75_0p15 = 75.0 / 15.0;
	float ratio_0p60_0p5 = 60.0 / 5.0;


	glPushMatrix();
		// Structure supérieur
		glPushMatrix();
			glTranslatef(0, 0.05 + _fractal, 0);
			BuildStructureSuperieure(_rotation);
		glPopMatrix();

		// Structure inférieure
		glPushMatrix();

			// Plaque de séparation
			glTranslatef(0, -0.045 -0.025, 0);
			glPushMatrix();
				glTranslatef(0.2, 0, 0);
				if(!_displayMecanismeOnly && !_displayMecanismeOnlyProcessing)
					BuildStructureIntermediaire();
			glPopMatrix();

			// Translation pour positionner les engrenages
			glTranslatef(0, -0.01 * 2 -0.045, 0);

			glPushMatrix();
				BuildStructureSecondesInferieure(_rotation);
				
				glTranslatef(0, -_fractal, 0);
				BuildStructureTurbineInferieure(_rotation);
			glPopMatrix();
		glPopMatrix();

		// Armature
		if(!_displayMecanismeOnly && !_displayMecanismeOnlyProcessing){
			glPushMatrix();
				glRotatef(-90, 1, 0, 0);
				glRotatef(180, 0, 0, 1);
				_armature->FastDisplay();
			glPopMatrix();
		}
	glPopMatrix();
}

void Montre::BuildStructureSuperieure(float rotation)
{
	// Ratio engrenage principale vers bras des heures
	float ratio_0p85_0p25 = 85.0 / 25.0;

	// Structure complète
	glPushMatrix();
	
		// Boite minute
		if(!_displayMecanismeOnly && !_displayMecanismeOnlyProcessing){
			glPushMatrix();
				glRotatef(180, 0, 1, 0);
				glTranslatef(0.325, 0.0, 0.0);
				_blocMinute->FastDisplay();

				glPushMatrix();
					glRotatef(-90, 1, 0, 0);

					glPushMatrix();
						glTranslatef(0.95, 1.6, 0.3);
						_chiffre0->FastDisplay();
					glPopMatrix();

					glPushMatrix();
						glTranslatef(1.7, 0.95, 0.3);
						_chiffre15->FastDisplay();
					glPopMatrix();

					glPushMatrix();
						glTranslatef(1.95, 0.0, 0.26);
						_chiffre30->FastDisplay();
					glPopMatrix();

					glPushMatrix();
						glTranslatef(1.7, -0.95, 0.3);
						_chiffre45->FastDisplay();
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0.95, -1.6, 0.3);
						_chiffre60->FastDisplay();
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
		}


		// Engrenage principal
		glPushMatrix();
			glTranslatef(0, -0.01, 0);
			_engrenage_M0p01_0p85->FastDisplay();
		glPopMatrix();

		// Rotation de la structure complète
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

				// Parcours des bras mécaniques
				for(int iAxe = 0; iAxe<3; iAxe++)
				{
					// Placements des 3 axes
					glPushMatrix();
						glRotatef(iAxe*120, 0, 1, 0);

						// Engrenages intermédiaires
						// Rotation des engrenages intermédiaires
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

void Montre::BuildStructureSecondesInferieure(float rotation)
{
	float ratio_0p75_0p25 = 75.0 / 25.0;
	float ratio_0p75_0p15 = 75.0 / 15.0;
	float ratio_0p60_0p5 = 60.0 / 5.0;

	// Sous engrenage (3H) -> Vers secondes
	glPushMatrix();
		glRotatef(_rotation, 0, 1, 0);
		_engrenage_M0p01_0p75->FastDisplay();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(75*0.01/2 +25*0.01/2, 0, 0);
		float reduction = ratio_0p75_0p25;

		// Rotor de l'engrenage de réduction
		glPushMatrix();
			glRotatef(-90, 1, 0, 0);
			_rotorEngrenageReductionHeureMin->FastDisplay();
		glPopMatrix();

		// Engrenage de réduction (1H)
		glPushMatrix();
			glRotatef(-_rotation * reduction, 0, 1, 0);
			_engrenage_M0p01_0p25->FastDisplay();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(25*0.01, -0.01, 0);

			// Rotor de l'engrenage conjoint de réduction
			glPushMatrix();
				glRotatef(-90, 1, 0, 0);
				_rotorEngrenageReductionHeureMin->FastDisplay();
			glPopMatrix();

			// Engrenage conjoint de réduction (1H)
			glPushMatrix();
				glRotatef(_rotation * reduction, 0, 1, 0);
				_engrenage_M0p01_0p25->FastDisplay();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0, - 0.045, 0);
						
				// Sous engrenage (Réduction 1H)
				glPushMatrix();
					glRotatef(_rotation * reduction, 0, 1, 0);
					_engrenage_M0p01_0p75->FastDisplay();
				glPopMatrix();

				glPushMatrix();
					glTranslatef(75*0.01/2 +15*0.01/2, 0, 0);
					reduction *= ratio_0p75_0p15;
							
					// Engrenange de réduction (12min)
					glPushMatrix();
						glTranslatef(0, 0.045 + 0.01 * 2, 0);
						glRotatef(-_rotation * reduction, 0, 1, 0);
						_engrenage_M0p01_0p15G->FastDisplay();
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0, (0.045 + 0.01)*2, 0);
								
						// Sur Engrenange de réduction (12min)
						glPushMatrix();
							glRotatef(-_rotation * reduction, 0, 1, 0);
							_engrenage_M0p01_0p60->FastDisplay();
						glPopMatrix();

								
						glPushMatrix();
							reduction *= ratio_0p60_0p5;
							glTranslatef(-60*0.01/2 - 5*0.01/2, 0, 0);
									
							// Engrenange de réduction (1min) (sens horraire)
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
									glRotatef(180, 0, 1, 0);
									_aiguillesSecondes->FastDisplay();
								glPopMatrix();
							glPopMatrix();
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

void Montre::BuildStructureTurbineInferieure(float rotation)
{
	// Ratio sous engrenage (3H) principale vers engrenage de réduction (1H)
	float ratio_0p255_0p60 = 255.0 / 60.0;
	
	// Etage inférieur -> Engrenages vers turbines
	glPushMatrix();
		glTranslatef(0, -(0.045 + 0.01)*2, 0);

		// Sous engrenage (3H) -> Vers turbines
		glPushMatrix();
			glRotatef(_rotation, 0, 1, 0);
			_engrenage_M0p01_0p255->FastDisplay();
		glPopMatrix();

		// Déplacement vers le mécanisme des turbines
		glPushMatrix();
			glTranslatef(-255*0.01/2 - 60*0.01/2, 0, 0);

			// Engrenage turbine central
			glPushMatrix();
				glRotatef(-_rotation * ratio_0p255_0p60, 0, 1, 0);
				_engrenage_M0p01_0p60->FastDisplay();
			glPopMatrix();

			// Engrenages supérieurs turbines
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
}


void Montre::BuildStructureIntermediaire()
{
	// Plaque
	glPushMatrix();
		glTranslatef(-0.35, 0, 0);
		glRotatef(180, 0, 1, 0);
		_plaqueSeparation->FastDisplay();
	glPopMatrix();

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
}

float Montre::GetCurrentHourRotation(int cubeAxe)
{
	// Calcul de la rotation relative
	int relativeRotation = (int)abs(_rotation) % 360;

	// Calcul de la position relative d'un cube heure
	float rotationGlobalHeure = (relativeRotation + 240 - (120 * cubeAxe)) % 360;

	// Calcul de la position absolue d'un cube heure
	// Il ne faut pas oublier de retrancher la tranche de rotation et l'ecart à la tranche (=60+30)
	// On retire aussi un delta = 1° afin de ne pas avoir de résultat visual innatendue
	float rotationAbsolueHeure = (abs(_rotation) + 240 - (120 * cubeAxe)) + 60 + 30 - 1;

	// Calcul du nombre de tours effectués par un cube heure
	float nbToursCubeHeure = abs(rotationAbsolueHeure)/360.0;

	// Si le cube heure se trouve dans la tranche de transition horraire
	float txRotationHeure = 0;
	float ecartRotationHeure = 60.0;
	if(rotationGlobalHeure <= 270 && rotationGlobalHeure >= 270-ecartRotationHeure)
	{
		// Calcul d'un taux de rotation dans l'écart de transition horaire
		txRotationHeure = (ecartRotationHeure - (270 - rotationGlobalHeure)) / ecartRotationHeure;
	}

	// On retourne la rotation du cube actuelle
	return ((int)nbToursCubeHeure) * 90 + (90 * txRotationHeure);
}




void Montre::Update()
{
	// La mise à jour de la montre s'effectue uniquement si l'utilisateur 
	// n'est pas en train de modifier l'heure lui même
	if(!_inUserChanging)
	{
		// Récupération de l'heure actuelle
		SYSTEMTIME interval = _time->GetInterval();

		// Calcul du nombre de tours effectués
		float nbTours = abs(_rotation)/360.0;
	
		// On tourne dans le sens horraire
		float diffTime = 0;
		diffTime += interval.wMilliseconds * DELTA_MILLISECONDE;
		diffTime += interval.wSecond  * DELTA_SECONDE;
		diffTime += interval.wMinute * DELTA_MINUTE;
		diffTime += interval.wHour * DELTA_HEURE;
		_rotation -= diffTime;


		// Rotation de la turbine
		SYSTEMTIME intervalTurbineTime = _turbineTime.GetInterval();
		float diffTurbineTime = interval.wMilliseconds * DELTA_MILLISECONDE + interval.wSecond  * DELTA_SECONDE;

		// Reset de la rotation des turbines
		if(intervalTurbineTime.wSecond >= 2){
			_sensTurbine = !_sensTurbine;
			_turbineTime.Update();
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

	if(_displayMecanismeOnlyProcessing)
	{
		_fractal += (_displayMecanismeOnly?1.0:-1.0) * 0.01;
		if(_fractal < 0){
			_fractal = 0;
			_displayMecanismeOnlyProcessing = false;
		}
		else if(_fractal > 0.6){
			_fractal = 0.6;
			_displayMecanismeOnlyProcessing = false;
		}
	}
}

void Montre::SetHeure(int heure, int minute, int seconde)
{
	_rotation = -(heure%12 * DELTA_HEURE + minute * DELTA_MINUTE + seconde * DELTA_SECONDE);
}

void Montre::Remonter(bool reverse)
{
	_rotation -= DELTA_MINUTE * (reverse?-1:1);

	// Cas particulier
	// La rotation doit toujours être négative
	if( _rotation >= 0) {
		_rotation = - 360.0 * 4 + _rotation;
	}
}


void Montre::SetBackground(int id)
{
	_plaqueSeparation->SetTexture(id);
}

void Montre::ShowMecanisme(bool show){
	_displayMecanismeOnly = show;
	_displayMecanismeOnlyProcessing = true;
}

bool Montre::IsUserChanging()
{
	return this->_inUserChanging;
}

void Montre::SetUserChanging(bool val)
{
	this->_inUserChanging = val;
}