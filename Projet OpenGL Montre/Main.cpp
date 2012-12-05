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

// Propriétés de la source lumineuse
GLfloat light_ambient[] = {1, 1, 1, 1 };
GLfloat light_specular[] = { 1, 1, 1, 1 };
GLfloat light1_ambient[] = {0, 0, 0, 1 };
GLfloat light1_specular[] = { 0, 0, 0, 1 };

GLfloat posDayLight[4] = {0.0,7,0.0,1.0};
GLfloat posNightLight[4] = {0.0,4,0.0,1.0};
// Propriétés générales de l’éclairage

/* parametres diffus en R,V,B */
GLfloat Mshiny=50;

TrackBallCamera* camera;
ScenarioDemonstration* _scenario;
CubeHeure* cubeHeure;


TheRoom* room;
Montre* montre;

Light *_nightLight, *_dayLight;

	GLuint texName[2];


Time* _time;
bool _exitCalled;
bool _exitRequest;
bool _displayExited;


void ExitApp()
{
	if(!_exitCalled && _displayExited)
	{
		_exitCalled = true;
		delete montre;
		delete _time;
		delete room;
		delete _nightLight;
		delete _dayLight;
		exit(0);
	}
}

void display()
{
	// On ne repasse pas dans le loop si il y a une demande de fermeture
	if(_exitRequest || glutGet(GLUT_WINDOW_FORMAT_ID) == 0 ){
		_displayExited = true;
		return;
	}

	// Vidage de la frame	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	camera->Look();

	Material mat = Material();
	mat.ToWhiteReflect();
	
	
	mat.Enable();
	glPushMatrix();
		glRotatef(-45.0, 1.0, 0.0, 0.0);
		glScalef(0.4, 0.4, 0.4);
		montre->FastDisplay();
	glPopMatrix();

	mat.Enable();
	glPushMatrix();
		glTranslatef(0, -3, 0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		room->FastDisplay();
		room->BuildAndDisplayHorlogePorte();
	glPopMatrix();
	//BlocMinute bloc = BlocMinute(0.5, 1, 1, 0.2, 0.2, 0.5);
	//bloc.BuildAndDisplay();
	
	
	GLfloat p[4] = {0.0,7,0.0,1.0};
	GLfloat p2[4] = {0.0,-1,0.0,1.0};
	float Light1Dir[3] = {0.0f, -1.0f, 0.0f}; 
	Light l0 = Light(GL_LIGHT0, p, light_ambient, Couleur::Blanc(), light_specular);
	Light l1 = Light(GL_LIGHT1, p, light1_ambient ,Couleur::RougeFonce(), light1_specular);
	
	//Light l1 = Light(GL_LIGHT0, 5.0, Couleur::Jaune(), p2, light_ambient, light_diffuse, light_specular);
	
	//l0.Display();
	//l1.Enable();


	glutSwapBuffers();
	glFlush();
}

void mouse(int button, int state,int x,int y)
{
	camera->OnMouseButton(button, state, x, y);

	glutPostRedisplay();
}

void mousemotion(int x,int y)
{
	camera->OnMouseMotion(x, y);
	glutPostRedisplay();
}

void key(unsigned char key,int x,int y) {
	// Envoi à la caméra
	camera->OnKeyboard(key, x, y);
	glutPostRedisplay();
}

void specialKey(int key, int x, int y){

	if(montre->IsUserChanging())
	{
		if ( key == GLUT_KEY_UP )
			montre->Remonter(true);
		else if ( key == GLUT_KEY_DOWN )
			montre->Remonter(false);
		glutPostRedisplay();
	}
}

void myReshape(int w,int h) {
	camera->SetFrameSize(w, h);
	glutPostRedisplay();
}


void update()
{
	// Exit
	if(_exitRequest || glutGet(GLUT_WINDOW_FORMAT_ID) == 0 ){
		ExitApp();
	}
	else
	{
		montre->Update();
		_time->Update();
		camera->Update();
		//_scenario->Update();
		glutPostRedisplay();
	}

	room->Update();
}

void ArrierePlanMenu(int selection) {
	switch (selection) {
		case 11  : 
			montre->SetBackground(0);
		break;
		case 12  : 
			montre->SetBackground(1);
		break;
	}
	_time->Start();
	glutPostRedisplay();
}


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

void MecanismeMenu(int selection) {
	switch (selection) {
		case 31  : 
			montre->ShowMecanisme(true);
		break;
		case 32  : 
			montre->ShowMecanisme(false);
		break;
	}
	_time->Start();
	glutPostRedisplay();
}

void ModeMenu(int selection) {
	switch (selection) {
		case 41  : 
			montre->SetUserChanging(true);
		break;
		case 42  : 
			montre->SetUserChanging(false);
		break;
	}
	_time->Start();
	glutPostRedisplay();
}

void GeneralMenu(int selection) {

	switch (selection) {
		case 0  : 
			_exitRequest = true;
		break;
		case 1  : 
			SYSTEMTIME sTime = Time::GetSystemGMTTime();
			montre->SetHeure(sTime.wHour, sTime.wMinute, sTime.wSecond);
		break;
	}
	_time->Start();
	glutPostRedisplay();
}

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

int main(int argc, char *argv[])
{
	_exitCalled = false;
	_exitRequest = false;
	_displayExited = false;

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GL_STENCIL_BUFFER_BIT);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Projet OpenGL Montre - Promotion 2012 - GUENDOUL, PIERSON, SCHEIBEL");

	// Initialisation
	glDepthFunc(GL_LESS);

	// Lissage
	glShadeModel(GL_SMOOTH);

	// Lumiere
	GLfloat lmodel_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);

	// Création d'une trackball caméra
	camera = new TrackBallCamera();
    camera->SetScrollSensivity(0.1);
    camera->SetMotionSensivity(0.1);
	camera->SetOffsetSensivity(0.05);
	camera->SetLocked(false);

	// on abonne le scénario de démonstration à la caméra
	_scenario = new ScenarioDemonstration(camera);

	//création d'un cubeHeur
	_time = new Time();
	_time->Start();
	montre = new Montre(_time);
	room = new TheRoom(12);
	room->BuildAndSave();

	// Arriere plan
	int menuArrierePlan = glutCreateMenu(ArrierePlanMenu);
      glutAddMenuEntry("Défaut",11);
      glutAddMenuEntry("Pamela",12); 

	int menuTemps = glutCreateMenu(TempsMenu);
      glutAddMenuEntry("X1",21);
      glutAddMenuEntry("X10",22); 
      glutAddMenuEntry("X30",23); 
      glutAddMenuEntry("X60",24); 
      glutAddMenuEntry("X120",25);
      glutAddMenuEntry("X180",26);
	  
	int menuMecanisme = glutCreateMenu(MecanismeMenu);
      glutAddMenuEntry("Seulement le mécanisme",31);
      glutAddMenuEntry("Toute la montre",32); 

   int menuMode = glutCreateMenu(ModeMenu);
      glutAddMenuEntry("Activer (utiliser les flèches haut/bas)",41);
      glutAddMenuEntry("Désaciver",42);

   int lumiereMode = glutCreateMenu(LumiereMenu);
      glutAddMenuEntry("Mode jour",51);
      glutAddMenuEntry("Mode nuit",52); 

	// Clavier
	  int menuMontre = glutCreateMenu(GeneralMenu);
      glutAddSubMenu("Arrière plan", menuArrierePlan);
      glutAddSubMenu("Afficher", menuMecanisme);
      glutAddSubMenu("Accélérer le temps", menuTemps);
	  glutAddSubMenu("Remontoire", menuMode);
	  glutAddSubMenu("Lumière", lumiereMode);


  glutCreateMenu(GeneralMenu);
       glutAddSubMenu("Paramètres",menuMontre);
	   glutAddMenuEntry("Mettre à l'heure système",1);
       glutAddMenuEntry("Quitter",0);
       
  /* On associe le choix du bouton gauche de la souris */
  
  glutAttachMenu(GLUT_RIGHT_BUTTON);

	_dayLight = new Light(GL_LIGHT0, posDayLight, light_ambient, Couleur::Blanc(), light_specular);
	_nightLight = new Light(GL_LIGHT1, posNightLight, light1_ambient ,Couleur::RougeFonce(), light1_specular);
	_dayLight->Enable();

	// Aboonnement
	glutDisplayFunc(display) ;
	glutMouseFunc(mouse);
    glutMotionFunc(mousemotion);
	glutIdleFunc(update);
	glutKeyboardFunc(key);
	glutSpecialFunc(specialKey);
  glutReshapeFunc(myReshape);
	glutMainLoop() ;


	
	return(0);
}

