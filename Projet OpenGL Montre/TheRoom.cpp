#include "TheRoom.h"


TheRoom::TheRoom(float taille): _taille(taille)
{

	GLuint texturesId[10];

	char* nameFace[10];
	 for(int i=0; i<10; i++)
		nameFace[i] = new char[60];
	 
	 sprintf(nameFace[0],"%s", "the_room/sole.ppm");
	 sprintf(nameFace[1],"%s", "the_room/plafond.ppm");
	 sprintf(nameFace[2],"%s", "the_room/mur1.ppm");
	 sprintf(nameFace[3],"%s", "the_room/mur2.ppm");
	 sprintf(nameFace[4],"%s", "the_room/mur3.ppm");
	 sprintf(nameFace[5],"%s", "the_room/mur4.ppm");

	 sprintf(nameFace[6],"%s", "the_room/plaque_horloge.ppm");
	 sprintf(nameFace[7],"%s", "the_room/notice_d_emploi.ppm");
	 sprintf(nameFace[8],"%s", "the_room/mur_tunnel.ppm");
	 sprintf(nameFace[9],"%s", "the_room/porte.ppm");

	//charger les texutre
	this->LoadTexture(texturesId, nameFace, 10); 
	 
	 for(int i=0; i<10; i++)
		delete nameFace[i];

	 // Copie en attribut
	 _sole = texturesId[0];    //le sol
	 _plafond = texturesId[1];   //le plafond
	 _mur1 = texturesId[2]; //le mur 1
	 _mur2 = texturesId[3]; //le mur 2
	 _mur3 = texturesId[4]; //le mur 3
	 _mur4 = texturesId[5]; //le mur 4

	 _plaqueHorloge = texturesId[6];  //la plaque horloge
	 _noticeEmploi = texturesId[7];  //la plaque notice d'emploi
	 _murTunnel = texturesId[8]; //la mur tunnel
	 _porte = texturesId[9]; //la porte





	this->_angleSeconde = -10;
	this->_angleMinute = -354;
	this->_angleHeure = -330;
	this->_anglePondule = 0;
	this->alpha = 1;
	this->_zOiseau = 0.0;
	this->_oiseauOk = false;
	this->_heurOieau = 11;
	this->_heurOiseauControle = 0;

	this->_fermerPorte = false;
	this->_OuvrirPorte = true;
	this->_anglePorte = 0.0;
}


TheRoom::~TheRoom(void)
{
}

void TheRoom::BuildAndDisplay()
{
	//le tunnel
	glPushMatrix();
		this->Tunnel();
	glPopMatrix();
	
	glPushMatrix();
		glTranslated(0.0,-this->_taille/1.5,0.01); //decalage sur l'axe z pour la faire monté, puis décalage sur l'ax y pour la collé sur le mur
		glRotated(90,0.0,1.0,0.0); //rotation sur l'axe y
		glRotated(90,0.0,0.0,1.0); //rotation sur l'axe z
		glRotated(90,0.0,1.0,0.0); //rotation sur l'axe x
		this->TableComande(this->_taille/9);
	glPopMatrix();
	
	//la table d'exposition
	glPushMatrix();
		glRotated(90,1.0,0.0,0.0);
		this->VitrineExposition(this->_taille/8, this->_taille/8);
	glPopMatrix();
	

	//le lustre
	glPushMatrix();
		glTranslated(0.0, 0.0, this->_taille);
		glRotated(180,1.0,0.0,0.0);
		this->Lustre(this->_taille/10,this->_taille/10);
	glPopMatrix();
	

	//la chambre de musée
	glEnable(GL_TEXTURE_2D);
	this->TheMuseum();
	glDisable(GL_TEXTURE_2D);

}

void TheRoom::BuildAndDisplayHorlogePorte()
{
	glPushMatrix();
		glPushMatrix();
			this->HorlogeComplete(0.8*12/10);
		glPopMatrix();

		glPushMatrix();
			this->MurPorte();
		glPopMatrix();
	glPopMatrix();
}

//la fonction update qui mis a jour l'horloge
void TheRoom::Update()
{
	//rotation des aiguilles
	this->_angleSeconde -=1;
	if(this->_angleSeconde == -360)
	{
		//rotation des eguailles*******************************
		this->_angleSeconde = 0;
		this->_angleMinute -= 6;
		if(this->_angleMinute == -360)
		{
			this->_angleMinute  = 0;
			this->_angleHeure -= 30;
			this->_oiseauOk = true;
			this->_heurOiseauControle = 0;
			this->_heurOieau++;
			if(this->_angleHeure == -360)
			{
				this->_angleHeure  = 0;
			}
		}
		//*****************************************************
	}
	//*********************************************************

	//rotation de pondule**********************************
		this->_anglePondule += alpha;
		if(this->_anglePondule == 20)
		{
			alpha = -1;
		}
		if(this->_anglePondule == -20)
		{
			alpha = 1;
		}
	//*****************************************************

	//traitement de oiseau*********************************
		if(this->_zOiseau < 1.0 && this->_oiseauOk && this->_heurOieau > this->_heurOiseauControle)
		{
			this->_zOiseau += 0.1;
		}
		else
		{
			this->_oiseauOk = false;
		}

		if(!this->_oiseauOk && this->_zOiseau > 0.1)
		{
			this->_zOiseau -= 0.1;
		}
		if(!this->_oiseauOk && this->_zOiseau <= 0.1)
		{
			this->_heurOiseauControle++;
			this->_oiseauOk = true;
			if(this->_heurOieau == 12 && this->_heurOiseauControle == 12)
				this->_heurOieau = 0;
		}
	//*************************************************

	//controle de la porte*********************************
	if(this->_OuvrirPorte)
	{
		if(this->_anglePorte <= 90.0)
			this->_anglePorte += 0.5;
		else
		{
			this->_fermerPorte = true;
			this->_OuvrirPorte = false;
		}
	}
	if(this->_fermerPorte)
	{
		if(this->_anglePorte >= 0.0)
			this->_anglePorte -= 0.5;
		else
		{
			this->_fermerPorte = false;
			this->_OuvrirPorte = true;
		}
	}
	//fin controle porte***********************************
}

void TheRoom::HorlogeComplete(float taille)
{
	glPushMatrix();
		glTranslated(0.0,-this->_taille/1.5-0.35*this->_taille/10,7.0*this->_taille/10); //decalage sur l'axe z pour la faire monté, puis décalage sur l'ax y pour la collé sur le mur
		glRotated(90,0.0,1.0,0.0); //rotation sur l'axe y
		glRotated(90,0.0,0.0,1.0); //rotation sur l'axe z
		glRotated(90,0.0,1.0,0.0); //rotation sur l'axe x
		glScaled(taille,taille,taille);
		glPushMatrix();//drawo horloge
			glTranslated(0.0,0.2,0.52);
			glScaled(0.5,0.5,0.5);
			this->Horloge();
		glPopMatrix();

		glPushMatrix();//draw oiseau
			glTranslated(0.0,0.97,this->_zOiseau);
			glScaled(0.1,0.1,0.1);
			this->Oiseau();
		glPopMatrix();

		glPushMatrix();  //draw cadre horloge
			this->CadreHorloge();
		glPopMatrix();
	glPopMatrix();
}

void TheRoom::Oiseau()
{
	//début oiseau****************************************
	//le corp
	glPushMatrix();
		GLfloat VertPistache[] = {0.72f, 0.83f, 0.06f, 1.0f};
		glMaterialfv(GL_FRONT,GL_DIFFUSE,VertPistache);
		glScaled(1.0,0.5,1.5);
		glutSolidSphere(1.0,25,25);
	glPopMatrix();

	//le coup
	glPushMatrix();
		GLfloat Orange[] = {1.0f, 0.48f, 0.15f, 1.0f};
		glMaterialfv(GL_FRONT,GL_DIFFUSE,Orange);
		glTranslated(0.0,0.7,1.0);
		glScaled(0.5,1.0,0.5);
		glRotated(110,1.0,0.0,0.0);
		this->CylindreRemplis();
	glPopMatrix();

	//la tete
	glPushMatrix();
		GLfloat Viole[] = {0.67f, 0.83f, 0.91f, 1.0f};
		glMaterialfv(GL_FRONT,GL_DIFFUSE,Viole);
		glTranslated(0.0,1.0,1.2);
		glutSolidSphere(0.5,25,25);
	glPopMatrix();

	//la nez
	glPushMatrix();
		GLfloat Marron[] = {0.68f, 0.28f, 0.08f, 1.0f};
		glMaterialfv(GL_FRONT,GL_DIFFUSE,Marron);
		glTranslated(0.0,0.85,1.6);
		glScaled(1.0,0.5,1.0);
		glutSolidCone(0.25,0.35,15,15);
	glPopMatrix();

	//les yeux
	glPushMatrix(); //gauche
		glTranslated(0.2,1.15,1.6);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Rouge());
		glutSolidSphere(0.05,15,15);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->BleuCiel(0.3));
		glutSolidSphere(0.1,15,15);
		glDisable(GL_BLEND);
	glPopMatrix();
	glPushMatrix(); //droite
		glTranslated(-0.2,1.15,1.6);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Rouge());
		glutSolidSphere(0.05,15,15);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->BleuCiel(0.3));
		glutSolidSphere(0.1,15,15);
		glDisable(GL_BLEND);
	glPopMatrix();

	//les soursille
	glPushMatrix();//gauche
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Noir());
		glTranslated(0.18,1.32,1.6);
		glRotated(30,0.0,0.0,1.0);
		glPushMatrix();
		glScaled(2.0,0.5,0.5);
		glutSolidCube(0.1);
		glPopMatrix();
	glPopMatrix();
	//les soursille
	glPushMatrix(); //droite
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Noir());
		glTranslated(-0.18,1.32,1.6);
		glRotated(-30,0.0,0.0,1.0);
		glPushMatrix();
		glScaled(2.0,0.5,0.5);
		glutSolidCube(0.1);
		glPopMatrix();
	glPopMatrix();
	//fin oiseu********************************************

	//début bras oiseau************************************
	glPushMatrix(); 
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->GrisClair());
		glTranslated(0.0,-0.45,0.0);
		glScaled(0.2,1.0,0.2);
		glRotated(90,1.0,0.0,0.0);
		this->CylindreRemplis();
	glPopMatrix();

	glPushMatrix(); 
		glTranslated(0.0,-1.0,-4.9);
		glScaled(0.2,0.2,10.0);
		this->CylindreRemplis();
	glPopMatrix();
	//fin bras oiseau**************************************
}

void TheRoom::CadreHorloge()
{
	//premiere partie de la petit maison******************************************
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glScaled(1.0,1.5,1.0);
		//face de deriere
		glBindTexture(GL_TEXTURE_2D, this->_plaqueHorloge);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(1.0,0.5,-0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(1.0,-0.5,-0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(-1.0,-0.5,-0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(-1.0,0.5,-0.5);
		glEnd();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(0.0,1.0,-0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(1.0,0.5,-0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(-1.0,0.5,-0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(0.0,1.0,-0.5);
		glEnd();

		//face de bas
		glBindTexture(GL_TEXTURE_2D, this->_plaqueHorloge);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(-1.0,-0.5,-0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(1.0,-0.5,-0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(1.0,-0.5,0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(-1.0,-0.5,0.5);
		glEnd();

		//face de gauche
		glBindTexture(GL_TEXTURE_2D, this->_plaqueHorloge);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(1.0,0.5,-0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(1.0,-0.5,-0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(1.0,-0.5,0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(1.0,0.5,0.5);
		glEnd();

		//face de droite
		glBindTexture(GL_TEXTURE_2D, this->_plaqueHorloge);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(-1.0,0.5,-0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,-0.5,-0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(-1.0,-0.5,0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(-1.0,0.5,0.5);
		glEnd();
		
		//face de haut gauche
		glBindTexture(GL_TEXTURE_2D, this->_plaqueHorloge);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(0.0,1.0,-0.65);
			glTexCoord2f(0.0, 1.0); glVertex3f(1.2,0.4,-0.65);
			glTexCoord2f(1.0, 1.0); glVertex3f(1.2,0.4,0.65);
			glTexCoord2f(1.0, 0.0); glVertex3f(0.0,1.0,0.65);
		glEnd();

		//face de haut droite
		glBindTexture(GL_TEXTURE_2D, this->_plaqueHorloge);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(0.0,1.0,-0.65);
			glTexCoord2f(0.0, 1.0); glVertex3f(-1.2,0.4,-0.65);
			glTexCoord2f(1.0, 1.0); glVertex3f(-1.2,0.4,0.65);
			glTexCoord2f(1.0, 0.0); glVertex3f(0.0,1.0,0.65);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	//***fin de la petit maison**************************
	
	//le pendule
	glPushMatrix();
		glRotated(this->_anglePondule, 0.0,0.0,1.0); //rotation de pondule sur l'ax z
		glPushMatrix();
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->BleuCiel(0.2));
			glTranslated(0.0,-2.20,0.0);
			glScaled(1.0,0.8,0.25);
			glutSolidSphere(0.25,25,25);
			glDisable(GL_BLEND);
		glPopMatrix();
		glPushMatrix();
			glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Jaune());
			glTranslated(0.0,-1.0,0.0);
			glScaled(0.15,2.0,0.05);
			glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
			glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Jaune());
			glTranslated(0.0,-2.20,0.0);
			glScaled(1.0,0.8,0.1);
			glutSolidSphere(0.4,25,25);
		glPopMatrix();
	glPopMatrix();

	
	//le trou de oiseau
	glPushMatrix();
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Brun());
		glTranslated(0.0,1.0,0.48);
		glScaled(0.35,0.35,1.0);
			glPushMatrix();
				glScaled(1.0,1.0,0.1);
				this->CylindreCrue(0.02);
			glPopMatrix();
			glPushMatrix();
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->BleuCiel(0.1));
				glScaled(0.98,0.98,0.1);
				this->CylindreRemplis();
				glDisable(GL_BLEND);
			glPopMatrix();
	glPopMatrix();

	//la bouche
	glPushMatrix();
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Brun());
		glTranslated(0.0,-0.5,0.48);
		glScaled(0.8,0.15,1.0);
			glPushMatrix();
				glScaled(1.0,1.0,0.1);
				this->CylindreCrue(0.02);
			glPopMatrix();
			glPushMatrix();
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->BleuCiel(0.1));
				glScaled(0.98,0.98,0.1);
				this->CylindreRemplis();
				glDisable(GL_BLEND);
			glPopMatrix();
	glPopMatrix();
	
	//deuxieme partie de la petit maison******************************************
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glScaled(1.0,1.5,1.0);
		//face de devant
		glBindTexture(GL_TEXTURE_2D, this->_plaqueHorloge);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(1.0,0.5,0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(1.0,-0.5,0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(-1.0,-0.5,0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(-1.0,0.5,0.5);
		glEnd();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(0.0,1.0,0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(1.0,0.5,0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(-1.0,0.5,0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(0.0,1.0,0.5);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	//***fin de la petit maison**************************
}

void TheRoom::Horloge()
{
	//le cylendre
	glPushMatrix();
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Brun());
		glScaled(2.0, 2.0, 0.4);
		this->CylindreCrue(0.05);
	glPopMatrix();

	//le cache deriere cylendre
	glPushMatrix();
		glTranslated(0.0,0.0,-0.025);
		glScaled(2.0, 2.0, 0.05);
		this->CylindreRemplis();
	glPopMatrix();


	//les tige
	glPushMatrix();
	glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Jaune());
	for(int i = 0; i <=60; i++)
	{
		if(i%5==0){			
			glPushMatrix();
			glTranslated(1.0-0.15,0.0,0.05);
			glScaled(0.75, 0.08, 0.1);
			glutSolidCube(0.2);
			glPopMatrix();
		}else{
			glPushMatrix();
			glTranslated(1.0-0.1,0.0,0.05);
			glScaled(0.5, 0.08, 0.1);
			glutSolidCube(0.2);
			glPopMatrix();
		}
		glRotated(6.0, 0.0, 0.0, 1.0);
	}
	glPopMatrix();


	//**********************les aiguilles *******************************/
	glPushMatrix();
		glTranslated(0.0,0.0,0.1);
		//la sphère
		glPushMatrix();
			glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->GrisClair());
			glutSolidSphere(0.08,15,15);
		glPopMatrix();
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Jaune());
		//heur
		glPushMatrix();
			glRotated(this->_angleHeure, 0.0,0.0,1.0);  //rotation des heurs sur l'axe z
			glScaled(0.075, 0.45, 0.025);
			glPushMatrix();
				glTranslated(0.0,0.5,0.0);
				glutSolidCube(1.0);
			glPopMatrix();
			glPushMatrix();
				glRotated(-90,1.0,0.0,0.0);
				glTranslated(0.0,0.0,1.0);
				glutSolidCone(0.5,0.1,25,25);
			glPopMatrix();
		glPopMatrix();

		//minute
		glPushMatrix();
			glRotated(this->_angleMinute, 0.0,0.0,1.0);  //rotation des minute sur l'axe z
			glScaled(0.05, 0.7, 0.025);
			glPushMatrix();
				glTranslated(0.0,0.5,0.0);
				glutSolidCube(1.0);
			glPopMatrix();
			glPushMatrix();
				glRotated(-90,1.0,0.0,0.0);
				glTranslated(0.0,0.0,1.0);
				glutSolidCone(0.65,0.1,25,25);
			glPopMatrix();
		glPopMatrix();

		//seconde
		glPushMatrix();
			glRotated(this->_angleSeconde, 0.0,0.0,1.0);  //rotation des seconde sur l'axe z
			glScaled(0.025, 0.8, 0.025);
			glPushMatrix();
				glTranslated(0.0,0.5,0.0);
				glutSolidCube(1.0);
			glPopMatrix();
			glPushMatrix();
				glRotated(-90,1.0,0.0,0.0);
				glTranslated(0.0,0.0,1.0);
				glutSolidCone(0.65,0.1,25,25);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	//**********************fin des aiguilles *******************************/

	
	//la vitre avant
	glPushMatrix();
	glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->BleuCiel(0.2));
		glTranslated(0.0,0.0,0.2);
		glScaled(2.0, 2.0, 0.05);
		this->CylindreRemplis();
		glDisable(GL_BLEND);
	glPopMatrix();
	
}

void TheRoom::TheMuseum()
{
	//dessiner la chambre
	glPushMatrix();
	glScaled(1.5*this->_taille, 1.5*this->_taille,this->_taille);
	//dessiner le sole
		glPushMatrix();
			glRotated(-90,0.0,0.0,1.0);
			glBindTexture(GL_TEXTURE_2D, this->_sole);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.0);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.5, -0.5, 0.0);
				glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.0);
			glEnd();
		glPopMatrix();
	
		//dessiner le plafond
		glPushMatrix();
			glTranslated(0.0, 0.0, 1.0);
			glRotated(90,0.0,0.0,1.0);
			glBindTexture(GL_TEXTURE_2D, this->_plafond);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.0);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.5, -0.5, 0.0);
				glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.0);
			glEnd();
		glPopMatrix();

		//dessiner le mur 1 vers x
		glPushMatrix();
			glTranslated(0.5, 0.0, 0.5);
			glRotated(90,0.0,1.0,0.0);
			glBindTexture(GL_TEXTURE_2D, this->_mur1);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.0);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.5, -0.5, 0.0);
				glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.0);
			glEnd();
		glPopMatrix();
		
		//dessiner le mur 2 vers -x
		glPushMatrix();
			glTranslated(-0.5, 0.0, 0.5);
			glRotated(90,0.0,1.0,0.0);
			glBindTexture(GL_TEXTURE_2D, this->_mur2);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.0);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.5, -0.5, 0.0);
				glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.0);
			glEnd();
		glPopMatrix();
	
		//dessiner le mur 4 vers -z
		glPushMatrix();
			glTranslated(0.0, -0.5, 0.5);
			glRotated(90,0.0,1.0,0.0);
			glRotated(90,1.0,0.0,0.0);
			glBindTexture(GL_TEXTURE_2D, this->_mur4);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.0);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.5, -0.5, 0.0);
				glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.0);
			glEnd();
		glPopMatrix();
		
	glPopMatrix();
	
}

void TheRoom::VitreTransparante()
{
	glPushMatrix();
		Material mat(0.1);
		mat.ToBlueDark();
		mat.Enable();
		
		//**********************les faces**********************************************
		//face deriere
		glBegin(GL_QUADS);
			glVertex3f(-0.5, 0.5,0.0);
			glVertex3f(0.5, 0.5,0.0);
			glVertex3f(0.5, -0.5,0.0);
			glVertex3f(-0.5, -0.5,0.0);
		glEnd();

		//face devnat
		glBegin(GL_QUADS);
			glVertex3f(-0.475, -0.475,0.025);
			glVertex3f(0.475, -0.475,0.025);
			glVertex3f(0.475, 0.475,0.025);
			glVertex3f(-0.475, 0.475,0.025);
		glEnd();

		//face de haut
		glBegin(GL_QUADS);
			glVertex3f(-0.5, 0.5,0.0);
			glVertex3f(0.5, 0.5,0.0);
			glVertex3f(0.475, 0.475,0.025);
			glVertex3f(-0.475, 0.475,0.025);
		glEnd();

		//face de bas
		glBegin(GL_QUADS);
			glVertex3f(-0.475, -0.475,0.025);
			glVertex3f(0.475, -0.475,0.025);
			glVertex3f(0.5, -0.5,0.0);
			glVertex3f(-0.5, -0.5,0.0);
		glEnd();

		//face de gauche
		glBegin(GL_QUADS);
			glVertex3f(-0.5, 0.5,0.0);
			glVertex3f(0.475, 0.475,0.025);
			glVertex3f(0.475, -0.475,0.025);
			glVertex3f(-0.5, -0.5,0.0);
		glEnd();

		//face de droite
		glBegin(GL_QUADS);
			glVertex3f(-0.475, -0.475,0.025);
			glVertex3f(0.5, -0.5,0.0);
			glVertex3f(0.5, 0.5,0.0);
			glVertex3f(-0.475, 0.475,0.025);
		glEnd();
		//************************fin des face****************************************/

		mat.Disable();
	glPopMatrix();
}

void TheRoom::VitrineExposition(float largeur, float hauteur)
{
	glPushMatrix();
	glScaled(largeur, hauteur, largeur);
		//******************les pieds********************************/
		float couleurTable[] = { 0.35F,0.176F,0.0F,1.0F };
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleurTable);
		//pied gauche bas
		glPushMatrix();
			glTranslated(0.5, 0.075, 0.5);;
			glScaled(0.1,0.15,0.1);
			this->CubeTexture();
		glPopMatrix();

		//pide droite bas
		glPushMatrix();
			glTranslated(-0.5, 0.075, 0.5);;
			glScaled(0.1,0.15,0.1);
			this->CubeTexture();
		glPopMatrix();

		//pied gauche haut
		glPushMatrix();
			glTranslated(0.5, 0.075, -0.5);;
			glScaled(0.1,0.15,0.1);
			this->CubeTexture();
		glPopMatrix();

		//pide droite haut
		glPushMatrix();
			glTranslated(-0.5, 0.075, -0.5);
			glScaled(0.1,0.15,0.1);
			this->CubeTexture();
		glPopMatrix();
		//*************************fin des pieds***************************/

		//***************************les plaque laterale********************/
		//plaque gauche
		glPushMatrix();
			glTranslated(0.5, 0.1+0.25+0.05, 0.0);
			glScaled(0.1,0.5,1.1);
			this->CubeTexture();
		glPopMatrix();

		//plaque droite
		glPushMatrix();
			glTranslated(-0.5, 0.1+0.25+0.05, 0.0);
			glScaled(0.1,0.5,1.1);
			this->CubeTexture();
		glPopMatrix();

		//plaque de devant
		glPushMatrix();
			glTranslated(0.0, 0.1+0.25+0.05, 0.5);
			glScaled(0.9,0.25,0.1);
			this->CubeTexture();
		glPopMatrix();

		//plaque deriere
		glPushMatrix();
			glTranslated(0.0, 0.1+0.25+0.05, -0.5);
			glScaled(0.9,0.25,0.1);
			this->CubeTexture();
		glPopMatrix();

		//plaque haut
		glPushMatrix();
			glTranslated(0.0, 0.1+0.25+0.05+0.25, 0.0);
			glScaled(1.1,0.1,1.1);
			this->CubeTexture();
		glPopMatrix();
		//************************fin des plaques laterale******************/

		//***************************vert de la table***********************/
		glPushMatrix();
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->BleuCiel(0.4));
			glTranslated(0.0, 0.1+0.25+0.05+0.25+0.05, 0.0);
			glScaled(1.1,0.025,1.1);
			glutSolidCube(1.0);
			glDisable(GL_BLEND); 
		glPopMatrix();
		//*********************fin vert de la table*************************/

		//***********************vitre d'exposition************************/
		glPushMatrix();
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->BleuCiel(0.3));
			glTranslated(0.0, 0.1+0.25+0.05+0.25+0.05+0.025+0.5, 0.0);
			glScaled(1.0,1.0,1.0);
			glPushMatrix();
				glPushMatrix();
				for(int i = 0; i <4; i++)
				{
					glPushMatrix();
						glTranslated(0.0,0.0,-0.5);
						VitreTransparante();
					glPopMatrix();
					glRotated(90,0.0,1.0, 0.0);
				}
				glPopMatrix();

				glPushMatrix();
				for(int i = 0; i <2; i++)
				{
					glPushMatrix();
						glTranslated(0.0,0.5,0.0);
						glRotated(90,1.0,0.0, 0.0);
						VitreTransparante();
					glPopMatrix();
					glRotated(180,0.0,0.0, 1.0);
				}
				glPopMatrix();
			glPopMatrix();
			glDisable(GL_BLEND); 
		glPopMatrix();
		//********************fin exposition********************************/
	glPopMatrix();
}

void TheRoom::Lustre(float largeur, float hauteur)
{
	glPushMatrix();
	glScaled(largeur, hauteur, largeur);
		glPushMatrix();
			glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Brun());
			//cache lustre
			glPushMatrix();
				glScaled(0.5,0.5,1.0);
				this->CylindreRemplis();
			glPopMatrix();

			//Le fil
			glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Blanc());
			glPushMatrix();
				glTranslated(0.0,0.0,0.5);
				glScaled(0.05,0.05,2.0);
				this->CylindreRemplis();
			glPopMatrix();

			//les tigre de lustre
			//tige 1
			glPushMatrix();
				glTranslated(0.0,0.4975,0.5+1.0);
				glRotated(90,1.0,0.0,0.0);
				glScaled(0.05,0.05,1.95);
				this->CylindreRemplis();
			glPopMatrix();

			//tige 2
			glPushMatrix();
				glTranslated(-0.4975,0.0,0.5+1.0);
				glRotated(90,0.0,1.0,0.0);
				glScaled(0.05,0.05,1.95);
				this->CylindreRemplis();
			glPopMatrix();

			//lampe
			glPushMatrix();
				glTranslated(0.0,0.0,0.5+1.0+0.05-0.05);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Noir());
				glPushMatrix();
					glScaled(0.2,0.2,0.3);
					this->CylindreRemplis();
				glPopMatrix();
				glPushMatrix();
					glEnable(GL_BLEND);
					glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->BleuCiel(0.4));
					glTranslated(0.0,0.0,0.25);
					glScaled(0.6,0.6,1.2);
					glutSolidSphere(0.2,25,25);
					glDisable(GL_BLEND); 
				glPopMatrix();
			glPopMatrix();

			//le cache lampe
			glPushMatrix();
				glTranslated(0.0,0.0,0.5+1.0-0.05);
				glPushMatrix();
					glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Rouge());
					glScaled(1.0,1.0,0.2);
					this->CylindreCrue(0.04);
				glPopMatrix();
				glPushMatrix();
					glEnable(GL_BLEND);
					glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Rouge(0.6));
					glScaled(1.0,1.0,1.51);
					this->CylindreCrue(0.01);
					glDisable(GL_BLEND); 
				glPopMatrix();
			glPopMatrix();
			glPushMatrix();
			glTranslated(0.0,0.0,0.5+1.0+0.75-0.05);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->Rouge());
				glScaled(1.0,1.0,0.1);
				this->CylindreCrue(0.04);
			glPopMatrix();
		
		glPopMatrix();
	glPopMatrix();
}

void TheRoom::CylindreRemplis()
{
		glPushMatrix();
			gluDisk(gluNewQuadric(),0,0.5,50,50);
			glTranslated(0, 0, 0.5);
			gluDisk(gluNewQuadric(),0,0.5,100,100);
		glPopMatrix();

		
		glPushMatrix();
			gluCylinder(gluNewQuadric(),0.5,0.5,0.5,100,100); 
			gluCylinder(gluNewQuadric(),0.5,0.5,0.5,100,100); 
		glPopMatrix();
}

void TheRoom::CylindreCrue(float epaisseur)
{
	glPushMatrix();
		gluDisk(gluNewQuadric(),0.5-epaisseur,0.5,50,50);
		glTranslated(0, 0, 0.5);
		gluDisk(gluNewQuadric(),0.5-epaisseur,0.5,100,100);
	glPopMatrix();

		
	glPushMatrix();
		gluCylinder(gluNewQuadric(),0.5,0.5,0.5,100,100);
		gluCylinder(gluNewQuadric(),0.5-epaisseur,0.5-epaisseur,0.5,100,100); 
	glPopMatrix();
}

//la table de comande
void TheRoom::TableComande(float taille)
{
	glPushMatrix();
		glScaled(taille,taille,taille);
		//plaque de deriere
		glPushMatrix();
			glTranslated(0.0,0.75,-0.45);
			glScaled(0.8,1.5,0.1);
			this->CubeTexture();
		glPopMatrix();

		//plaque de droite
		glPushMatrix();
			glTranslated(0.45,0.75,0.0);
			glRotated(90,0.0,0.0,1.0);
			glScaled(1.5,0.1,1.0);
			this->CubeTexture();
		glPopMatrix();

		//plaque de guauche
		glPushMatrix();
			glTranslated(-0.45,0.75,0.0);
			glRotated(90,0.0,0.0,1.0);
			glScaled(1.5,0.1,1.0);
			this->CubeTexture();
		glPopMatrix();

		//plaque de haut
		glPushMatrix();
			glTranslated(0.0,1.55,0.0);
			glScaled(1.0,0.1,1.0);
			this->CubeTexture();
		glPopMatrix();

		//les deux tige
		glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->GrisClair());
		glPushMatrix();//tige1
			glTranslated(0.25,1.55,-0.2);
			glRotated(-90,1.0,0.0,0.0);
			glScaled(0.05,0.05,1.18);
			this->CylindreRemplis();
		glPopMatrix();
		glPushMatrix();//tige2
			glTranslated(-0.25,1.55,-0.2);
			glRotated(-90,1.0,0.0,0.0);
			glScaled(0.05,0.05,1.18);
			this->CylindreRemplis();
		glPopMatrix();
	
		//la vitre transparente
		glPushMatrix();
			glTranslated(0.0,1.95,0.0);
			glRotated(45,1.0,0.0,0.0);
		
			//la texture***************************************
			glEnable(GL_TEXTURE_2D);
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, this->_noticeEmploi);
				glBegin(GL_QUADS);
					glTexCoord2f(1.0, 1.0); glVertex3f(0.3,0.026,0.4);
					glTexCoord2f(1.0, 0.0); glVertex3f(0.3,0.026,-0.4);
					glTexCoord2f(0.0, 0.0); glVertex3f(-0.3,0.026,-0.4);
					glTexCoord2f(0.0, 1.0); glVertex3f(-0.3,0.026,0.4);
				glEnd();
			glPopMatrix();
			glDisable(GL_TEXTURE_2D);
			//**********************************************
		
			//la vigtre d'exposition*************************
			glPushMatrix();
				glEnable(GL_BLEND);
					glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					glMaterialfv(GL_FRONT,GL_DIFFUSE,couleur->BleuCiel(0.3));
					glScaled(0.8,0.05,1.0);
					glutSolidCube(1.0);
				glDisable(GL_BLEND); 
			glPopMatrix();
			//*************************************************
		glPopMatrix();
	glPopMatrix();
}

void TheRoom::CubeTexture()
{
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
		//face de devant
		glBindTexture(GL_TEXTURE_2D, this->_plaqueHorloge);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(0.5,0.5,0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(0.5,-0.5,0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(-0.5,-0.5,0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(-0.5,0.5,0.5);
		glEnd();
				//face de deriere
		glBindTexture(GL_TEXTURE_2D, this->_plaqueHorloge);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(0.5,0.5,-0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(0.5,-0.5,-0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(-0.5,-0.5,-0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(-0.5,0.5,-0.5);
		glEnd();
		
		//face de haut 
		glBindTexture(GL_TEXTURE_2D, this->_plaqueHorloge);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(-0.5,0.5,-0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(0.5,0.5,-0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(0.5,0.5,0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(-0.5,0.5,0.5);
		glEnd();

		//face de bas
		glBindTexture(GL_TEXTURE_2D, this->_plaqueHorloge);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(-0.5,-0.5,-0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(0.5,-0.5,-0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(0.5,-0.5,0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(-0.5,-0.5,0.5);
		glEnd();

		//face de gauche
		glBindTexture(GL_TEXTURE_2D, this->_plaqueHorloge);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(0.5,0.5,-0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(0.5,-0.5,-0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(0.5,-0.5,0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(0.5,0.5,0.5);
		glEnd();

		//face de droite
		glBindTexture(GL_TEXTURE_2D, this->_plaqueHorloge);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(-0.5,0.5,-0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(-0.5,-0.5,-0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(-0.5,-0.5,0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(-0.5,0.5,0.5);
		glEnd();
		
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

//le tunnel
void TheRoom::Tunnel()
{
	glPushMatrix();
	glRotated(90, 0.0,0.0,1.0);
	glTranslated(0.75*this->_taille, 0.0, 0.0);
	glRotated(90,1.0,0.0,0.0);
	glScaled(this->_taille, 0.5*this->_taille, 0.5*this->_taille);
	glTranslated(0.0, 0.51, 0.0);
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
		//face de devant
		glBindTexture(GL_TEXTURE_2D, this->_murTunnel);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(1.0,0.5,0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(1.0,-0.5,0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(0.0,-0.5,0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(0.0,0.5,0.5);
		glEnd();
				//face de deriere
		glBindTexture(GL_TEXTURE_2D, this->_murTunnel);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(1.0,0.5,-0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(1.0,-0.5,-0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(0.0,-0.5,-0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(0.0,0.5,-0.5);
		glEnd();
		
		//face de haut 
		glBindTexture(GL_TEXTURE_2D, this->_murTunnel);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(0.0,0.5,-0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(1.0,0.5,-0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(1.0,0.5,0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(0.0,0.5,0.5);
		glEnd();

		//face de bas
		glBindTexture(GL_TEXTURE_2D, this->_murTunnel);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(0.0,-0.5,-0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(1.0,-0.5,-0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(1.0,-0.5,0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(0.0,-0.5,0.5);
		glEnd();		
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void TheRoom::Porte()
{
	glPushMatrix();
		glPushMatrix();
			glRotated(-this->_anglePorte,0.0,1.0,0.0);
			glTranslated(-0.01,0.0,-0.2);
			//face de devant
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, this->_porte);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(0.025,0.3,0.2);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.025,-0.5,0.2);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.0,-0.5,0.2);
				glTexCoord2f(1.0, 0.0); glVertex3f(0.0,0.3,0.2);
			glEnd();

			//face de deriere
			glBindTexture(GL_TEXTURE_2D, this->_porte);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(0.025,0.3,-0.2);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.025,-0.5,-0.2);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.0,-0.5,-0.2);
				glTexCoord2f(1.0, 0.0); glVertex3f(0.0,0.3,-0.2);
			glEnd();
		
			//face de haut 
			glBindTexture(GL_TEXTURE_2D, this->_porte);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(0.0,0.3,-0.2);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.025,0.3,-0.2);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.025,0.3,0.2);
				glTexCoord2f(1.0, 0.0); glVertex3f(0.0,0.3,0.2);
			glEnd();

			//face de bas
			glBindTexture(GL_TEXTURE_2D, this->_porte);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(0.0,-0.5,-0.2);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.025,-0.5,-0.2);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.025,-0.5,0.2);
				glTexCoord2f(1.0, 0.0); glVertex3f(0.0,-0.5,0.2);
			glEnd();

			//face de gauche
			glBindTexture(GL_TEXTURE_2D, this->_porte);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(0.0,0.3,0.2);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.0,-0.5,0.2);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.0,-0.5,-0.2);
				glTexCoord2f(1.0, 0.0); glVertex3f(0.0,0.3,-0.2);
			glEnd();

			//face de droite
			glBindTexture(GL_TEXTURE_2D, this->_porte);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(0.025,0.3,0.2);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.025,-0.5,0.2);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.025,-0.5,-0.2);
				glTexCoord2f(1.0, 0.0); glVertex3f(0.025,0.3,-0.2);
			glEnd();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

void TheRoom::MurPorte()
{
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
		glScaled(1.5*this->_taille, 1.5*this->_taille,this->_taille);
		//dessiner le mur 3 vers z
		glPushMatrix();
			glTranslated(0.0, 0.5, 0.5);
			glRotated(90,0.0,1.0,0.0);
			glRotated(90,1.0,0.0,0.0);

			glPushMatrix();
				//glTranslated(0.0,0.0,0.2);
				glRotated(90, 0.0,0.0,1.0);
				glRotated(90, 0.0,1.0,0.0);
				glScaled(0.5,0.5,0.5);
				glTranslated(0.0,-0.5,0.2);
				this->Porte();
			glPopMatrix();

			glPushMatrix();
				
				Material mat = Material(0.01);
				mat.ToBlackRubber();
				mat.Enable();
					glScaled(0.4,0.19,0.005);
					glTranslated(0.75,0.0,0.0);
					glutSolidCube(1.0);
				mat.Disable();

				mat = Material();
				mat.ToWhiteReflect();
				mat.Enable();
			glPopMatrix();

			glBindTexture(GL_TEXTURE_2D, this->_mur3);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.0);
				glTexCoord2f(1.0, 1.0); glVertex3f(0.5, -0.5, 0.0);
				glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.0);
			glEnd();
		glPopMatrix();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}