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
						// Rotation des engrenages intermédiaires
						glPushMatrix();
							glTranslatef(1.11, 0, 0);
							glRotatef(-rotation - iAxe*5, 0, 1, 0);
							engrenage_M0p01_0p85->FastDisplay();
						glPopMatrix();
					glPopMatrix();
				}
			glPopMatrix();
		glPopMatrix();


	glPopMatrix();
}

void Montre::Update()
{
	rotation-=0.05;
}