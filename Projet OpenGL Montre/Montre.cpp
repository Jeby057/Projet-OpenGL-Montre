#include "Montre.h"


Montre::Montre(void)
{
	rotation = 0;

	// Création des engrenages
	engrenage_M0p01_0p85 = new Engrenage(0.01, 85*0.01, 0.045, 1);
	engrenage_M0p01_0p85->BuildAndSave();

	engrenage_M0p01_0p45 = new Engrenage(0.01, 25*0.01, 0.045, 1);
	engrenage_M0p01_0p45->BuildAndSave();

	// Création de la piece maitresse
	maitresse = new Maitresse(0.15, 0.15, 0.15, 0.35, 0.045, 0.45, 0.8 );
	maitresse->BuildAndSave();

	// Caches engrenages
	_cacheEngrenage = new CacheEngrenage(0.8/3, 0.8, 50, 0.045, 240, 0.045/2, 0.045/2);
	_cacheEngrenage->BuildAndSave();

	// Cadres horraires
	 _pointeurHorraire = new EntourantCube(0.45, 0.08, 0.27, 0.05, 0.085, 0.07, 0.37, 0.5, 0.175);
	 _pointeurHorraire->BuildAndSave();

	 // Indicateur des minutes
	 _indicateurMin = new IndicateurMins(0.2, 0.085, 0.085, 0.45/1.5, 0.01, 0.01);
	 _indicateurMin->BuildAndSave();

	 // Rotor Engrenage final
	 _rotorEngrenageFinal = new PartialDisque(0, 0.8/4, 0.065+0.018, 50, 360);
	 _rotorEngrenageFinal->BuildAndSave();

	 // Cube heure
	 for(int cube=0; cube<3; cube++)
	 {
		 char* namFace[6];
		 for(int i=0; i<6; i++)
			 namFace[i] = (char*) malloc(6);

		 sprintf(namFace[0],"%i.ppm", 10+cube);
		 sprintf(namFace[1],"%i.ppm", 7+cube);
		 sprintf(namFace[2],"%i.ppm", 4+cube);
		 sprintf(namFace[3],"%i.ppm", 1+cube);
	     sprintf(namFace[4],"%i.ppm", 13);
		 sprintf(namFace[5],"%i.ppm", 14);

		 _cubeHeure[cube] = new CubeHeure(0.17 ,namFace);
		 _cubeHeure[cube]->BuildAndSave();
	 }

	 rotationGlobalHeure[0] = 360 ;
	 rotationGlobalHeure[1] = 240 ;
	 rotationGlobalHeure[2] = 120 ;

	 rotationHeure[0] = 180+45 ;
	 rotationHeure[1] = 180 ;
	 rotationHeure[2] = 180 ;

	 // Rotor Cube Heure
	 _rotorCubeHeure = new PartialDisque(0, 0.17/2, 0.27*2 + 0.085 + 0.07 + 0.05, 50, 360);
	 _rotorCubeHeure->BuildAndSave();
}


Montre::~Montre(void)
{
	delete engrenage_M0p01_0p85;
	delete engrenage_M0p01_0p45;
	delete maitresse;
}

void Montre::BuildAndDisplay()
{

	float ratio = 85.0 / 25.0;

	glPushMatrix();
		// Engrenage principal
		glPushMatrix();
			glTranslatef(0, -0.01, 0);
			engrenage_M0p01_0p85->FastDisplay();
		glPopMatrix();

		// Structure complète
		glPushMatrix();

			// Rotation de la structure complète
			glRotatef(rotation, 0, 1, 0);

			// Piece maitresse
			glPushMatrix();
				glRotatef(-30, 0, 1, 0);
				maitresse->FastDisplay();
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
							glRotatef(rotation * ratio + iAxe*4, 0, 1, 0);
							engrenage_M0p01_0p45->FastDisplay();
						glPopMatrix();

						// Engrenages finaux
						glPushMatrix();
							glTranslatef(1.11, 0, 0);
							
							// Rotation des engrenages 
							glPushMatrix();
								glRotatef(-rotation - iAxe*5, 0, 1, 0);
								engrenage_M0p01_0p85->FastDisplay();
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
												glRotatef(rotationHeure[iAxe], 1, 0, 0);
												_cubeHeure[iAxe]->FastDisplay();
											glPopMatrix();

											// Rotor Cube heure
											glPushMatrix();
												glTranslatef(-0.05,0,0.17);
												glRotatef(-90, 0, 1, 0);
												_rotorCubeHeure->FastDisplay();
											glPopMatrix();
											
										glPopMatrix();

										// Pointeur mintute
										glPushMatrix();
											glTranslatef(0.03+0.085/2,0.2/2,0.045+0.175-0.085+0.05/2);
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


void Montre::Update()
{
	double pas = 0.1;
	rotation-=pas;
	int rot4T = abs(rotation)/360;
	int decalage = 65;

	for(int axe=0; axe<3; axe++)
	{
		rotationGlobalHeure[axe] += pas;
		if(rotationGlobalHeure[axe] >= 240 + decalage && rotationGlobalHeure[axe] <= 360 + decalage)
			rotationHeure[axe] += 90.0/120.0*pas;
		if(rotationGlobalHeure[axe] >= 360 + decalage)
			rotationGlobalHeure[axe] = decalage;
	}

	// Quand l'on a fait 4 fois le tours : 12h en tout!
	if(rot4T>=4)
		rotation = 0;

}