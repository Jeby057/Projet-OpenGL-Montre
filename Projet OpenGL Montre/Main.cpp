#include "include.h"
#include "Engrenage.h"
#include "CubeHeure.h"
#include "TrackBallCamera.h"
#include "BrasMaitre.h"
#include "PartialDisque.h"
#include "Maitresse.h"
#include "Montre.h"
#include "PartialCylinder.h"
#include "CacheEngrenage.h"
#include "BlocMinute.h"
#include "TheRoom.h"
#include "Time.h"
#include "ScenarioDemonstration.h"


// Camera
TrackBallCamera* _camera;

// Scenario de démonstration
ScenarioDemonstration* _scenario;

// Salle de démonstration
TheRoom* _room;

// Montre
Montre* _montre;

// Lumiere
Light *_nightLight, *_dayLight;

// Timer permettant de cadencer la montre
Time* _time;

// Vrai si la procedure de fermeture est en cours
bool _exitCalled;

// Vrai si la procédure de fermeture a été appelée
bool _exitRequest;

// Vrai si la boucle d'affichage (mainloop) a été arrété
bool _displayExited;


/**
 * Procédure de fermeture
 */
void ExitApp()
{
	// On éxécute la procédure si la procédure n'a pas déjà été appelé
	// Et si la boucle d'affichage est stopé
	if(!_exitCalled && _displayExited)
	{
		_exitCalled = true;
		delete _montre;
		delete _time;
		delete _room;
		delete _nightLight;
		delete _dayLight;
		exit(0);
	}
}

/**
 * Callback d'affichage d'OpenGL
 */
void DisplayCallback()
{
	// On ne repasse pas dans le loop si il y a une demande de fermeture
	if(_exitRequest || glutGet(GLUT_WINDOW_FORMAT_ID) == 0 ){
		_displayExited = true;
		return;
	}

	// Vidage de la frame	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// On dirige la caméra
	_camera->Look();

	// Par défaut, on applique un matérial blanc
	Material mat = Material();
	mat.ToWhiteReflect();
	mat.Enable();

	// Affichage de la montre
	glPushMatrix();
		glRotatef(-45.0, 1.0, 0.0, 0.0);
		glScalef(0.2, 0.2, 0.2);
		_montre->FastDisplay();
	glPopMatrix();

	// On réapplique le matériel 
	// Et on affiche la pièce
	mat.Enable();
	glPushMatrix();
		glTranslatef(0, -1.8, 0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		_room->BuildAndDisplayHorloge();
		_room->FastDisplay();
	glPopMatrix();

	// Netoyage
	glutSwapBuffers();
	glFlush();
}

/**
 * Callback sur l'état des boutons de la souris
 */
void MouseCallback(int button, int state,int x,int y)
{
	_camera->OnMouseButton(button, state, x, y);
	glutPostRedisplay();
}

/**
 * Callback sur l'état de la position de la souris
 */
void MouseMotionCallback(int x,int y)
{
	_camera->OnMouseMotion(x, y);
	glutPostRedisplay();
}

/**
 * Callback sur les touches du clavuer
 */
void KeyboardCallback(unsigned char key,int x,int y) 
{
	_camera->OnKeyboard(key, x, y);
	glutPostRedisplay();
}

/**
 * Callback sur les touches spéciales du clavier
 */
void SpecialKeyCallback(int key, int x, int y){

	if(_montre->IsUserChanging())
	{
		if ( key == GLUT_KEY_UP )
			_montre->Remonter(true);
		else if ( key == GLUT_KEY_DOWN )
			_montre->Remonter(false);
		glutPostRedisplay();
	}
}

/**
 * Callback sur la vue en perspective permettant de retailler la fenetre
 */
void ReshapeCallback(int w,int h) {
	_camera->SetFrameSize(w, h);
	glutPostRedisplay();
}

/**
 * Callback sur les mises à jours
 */
void UpdateCallback()
{
	// Procédure de fin
	if(_exitRequest || glutGet(GLUT_WINDOW_FORMAT_ID) == 0 ){
		ExitApp();
	}
	else
	{
		// Mise à jour
		_montre->Update();
		_time->Update();
		_camera->Update();
		//_scenario->Update();
		glutPostRedisplay();
	}
	_room->Update();
}

/**
 * Menu : Arriere plan
 */
void ArrierePlanMenu(int selection) {
	switch (selection) {
		case 11  : 
			_montre->SetBackground(0);
		break;
		case 12  : 
			_montre->SetBackground(1);
		break;
		case 13 :
			_montre->SetBackground(2);
		break;
	}
	_time->Start();
	glutPostRedisplay();
}

/**
 * Menu : Accélération du Temps
 */
void TempsMenu(int selection) {
	switch (selection) {
		case 21  : 
			_time->SetScale(1);
		break;
		case 22  : 
			_time->SetScale(10);
		break;
		case 23  : 
			_time->SetScale(30);
		break;
		case 24  : 
			_time->SetScale(60);
		break;
		case 25  : 
			_time->SetScale(120);
		break;
		case 26  : 
			_time->SetScale(180);
		break;
	}
	_time->Start();
	glutPostRedisplay();
	
}

/**
 * Menu : Mécanisme
 */
void MecanismeMenu(int selection) {
	switch (selection) {
		case 31  : 
			_montre->ShowMecanisme(true);
		break;
		case 32  : 
			_montre->ShowMecanisme(false);
		break;
	}
	_time->Start();
	glutPostRedisplay();
}

/**
 * Menu : Remonter la montre
 */
void ModeMenu(int selection) {
	switch (selection) {
		case 41  : 
			_montre->SetUserChanging(true);
		break;
		case 42  : 
			_montre->SetUserChanging(false);
		break;
	}
	_time->Start();
	glutPostRedisplay();
}

/**
 * Menu : Lumiere
 */
void LumiereMenu(int selection) {
	switch (selection) {
		case 51  : 
			_nightLight->Disable();
			_dayLight->Enable();
		break;
		case 52  : 
			_dayLight->Disable();
			_nightLight->Enable();
		break;
	}
	_time->Start();
	glutPostRedisplay();
}


/**
 * Menu : Général
 */
void GeneralMenu(int selection) {

	switch (selection) {
		case 0  : 
			_exitRequest = true;
		break;
		case 1  : 
			SYSTEMTIME sTime = Time::GetSystemGMTTime();
			_montre->SetHeure(sTime.wHour, sTime.wMinute, sTime.wSecond);
		break;
	}
	_time->Start();
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	printf("\n\n");
	printf("     Projet OpenGL  -  Promotion IHM 2013     \n");
	printf("     ************************************     \n");
	printf("         GUENDOUL - PIERSON - SCHEIBEL        \n\n\n");
	printf("       Chargement de l'environnement...       \n");

	// Procédure d'arret à faux
	_exitCalled = false;
	_exitRequest = false;
	_displayExited = false;

	// initialisation
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GL_STENCIL_BUFFER_BIT);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(800, 600);
	glDepthFunc(GL_LESS);
	glutCreateWindow("Projet OpenGL Montre - Promotion 2012 - GUENDOUL, PIERSON, SCHEIBEL");

	// Lissage
	glShadeModel(GL_SMOOTH);

	// Lumiere
	GLfloat lmodel_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	// Limiere sur les textures
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

	// Propriété de pronfondeur et d'interpolation de la lumiere
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	
	// Propriétés de la source lumineuse
	GLfloat light[] = {1, 1, 1, 1 };
	GLfloat light1[] = {0, 0, 0, 1 };
	GLfloat posDayLight[4] = {0.0,7,0.0,1.0};
	GLfloat posNightLight[4] = {0.0,4,0.0,1.0};

	// Création des lumières
	_dayLight = new Light(GL_LIGHT0, posDayLight, light, Couleur::Blanc(), light);
	_nightLight = new Light(GL_LIGHT1, posNightLight, light1 ,Couleur::RougeFonce(), light1);
	_dayLight->Enable();

	// Création d'une trackball caméra
	_camera = new TrackBallCamera();
	_camera->SetScrollSensivity(0.1);
	_camera->SetMotionSensivity(0.1);
	_camera->SetOffsetSensivity(0.05);
	_camera->SetLocked(false);

	// On abonne le scénario de démonstration à la caméra
	_scenario = new ScenarioDemonstration(_camera);

	// Création d'un timer
	_time = new Time();
	_time->Start();

	// Création de la montre
	_montre = new Montre(_time);

	// Création de la pièce
	_room = new TheRoom(12);
	_room->BuildAndSave();

	// Chargement principal terminé
	printf("               Bonne visite !                \n");

	// Menu : Arriere plan
	int menuArrierePlan = glutCreateMenu(ArrierePlanMenu);
	glutAddMenuEntry("Défaut",11);
	glutAddMenuEntry("Pamela",12);
	glutAddMenuEntry("Galets",13); 
	
	// Menu : Temps
	int menuTemps = glutCreateMenu(TempsMenu);
	glutAddMenuEntry("X1",21);
	glutAddMenuEntry("X10",22); 
	glutAddMenuEntry("X30",23); 
	glutAddMenuEntry("X60",24); 
	glutAddMenuEntry("X120",25);
	glutAddMenuEntry("X180",26);
	  
	// Menu : Mécanisme
	int menuMecanisme = glutCreateMenu(MecanismeMenu);
	glutAddMenuEntry("Seulement le mécanisme",31);
	glutAddMenuEntry("Toute la montre",32); 

	// Menu : réglage
	int menuMode = glutCreateMenu(ModeMenu);
	glutAddMenuEntry("Activer (utiliser les flèches haut/bas)",41);
	glutAddMenuEntry("Désaciver",42);

	// Menu : Lumiere
	int lumiereMode = glutCreateMenu(LumiereMenu);
	glutAddMenuEntry("Mode jour",51);
	glutAddMenuEntry("Mode nuit",52); 

	// Menu : Paramètre
	int menuMontre = glutCreateMenu(GeneralMenu);
	glutAddSubMenu("Arrière plan", menuArrierePlan);
	glutAddSubMenu("Afficher", menuMecanisme);
	glutAddSubMenu("Accélérer le temps", menuTemps);
	glutAddSubMenu("Remontoire", menuMode);
	glutAddSubMenu("Lumière", lumiereMode);

	// Menu : Général
	glutCreateMenu(GeneralMenu);
	glutAddSubMenu("Paramètres",menuMontre);
	glutAddMenuEntry("Mettre à l'heure système",1);
	glutAddMenuEntry("Quitter",0);
       
	// Bouton gauche au menu
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// Aboonnement
	glutDisplayFunc(DisplayCallback) ;
	glutMouseFunc(MouseCallback);
	glutMotionFunc(MouseMotionCallback);
	glutIdleFunc(UpdateCallback);
	glutKeyboardFunc(KeyboardCallback);
	glutSpecialFunc(SpecialKeyCallback);
	glutReshapeFunc(ReshapeCallback);

	// Boucle principale
	glutMainLoop() ;

	return(0);
}
