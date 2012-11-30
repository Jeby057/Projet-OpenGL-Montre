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


// Propriétés de la source lumineuse
GLfloat light_ambient[] = { 1.0,1.0, 1.0, 1.0 };
GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
// Propriétés générales de l’éclairage

/* parametres diffus en R,V,B */
GLfloat Mshiny=50;

TrackBallCamera* camera;
CubeHeure* cubeHeure;


TheRoom* room;
Montre* montre;

	GLuint texName[2];

void display()
{
	// Vidage de la frame	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	camera->Look();


	//glBindTexture(GL_TEXTURE_2D, texName[0]);
	//Piece* engrenage = new Engrenage(0.1, 0.1*50, 0.3, 0);
	//engrenage->BuildAndDisplay();

	//Piece* engrenage = new Disque(0.0, 5, 0.2, 50);
    //engrenage->BuildAndDisplay();

	//BrasMaitre* bras = new BrasMaitre(3.0,2.0,0.4,3.0);
	//bras->BuildAndDisplay();

	//creer le cube heure
	//cubeHeure->BuildAndDisplay();

	/*
	glBegin(GL_QUADS);
	glColor3ub(114, 157, 187);
    glVertex3i(-10,0,-10);
    glVertex3i(10,0,-10);
    glVertex3i(10,0,10);
    glVertex3i(-10,0,10);
    glEnd();
	glPushMatrix();
		glTranslatef(0, 1.5, 0);
		glRotatef(100, 1, 0, 0);
		CacheEngrenage c(0.8/3, 0.8, 50, 0.045, 240, 0.045/2, 0.045/2);
	c.BuildAndDisplay();
	glPopMatrix();
	*/


	Material mat = Material();
	mat.ToWhiteReflect();
	mat.Enable();

	glPushMatrix();
		glRotatef(-45.0, 1.0, 0.0, 0.0);
		glScalef(0.4, 0.4, 0.4);
		montre->FastDisplay();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, -3, 0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		room->FastDisplay();
	glPopMatrix();
	//BlocMinute bloc = BlocMinute(0.5, 1, 1, 0.2, 0.2, 0.5);
	//bloc.BuildAndDisplay();
	
	
	GLfloat p[4] = {0.0,2,0.0,1.0};
	GLfloat p2[4] = {0.3,-0.25,0.0,1.0};
	float Light1Dir[3] = {0.0f, -1.5f, 0.0f}; 
	Light l0 = Light(GL_LIGHT0, 5.0, Couleur::Jaune(), p, light_ambient, light_diffuse, light_specular);
	
	Light l1 = Light(GL_LIGHT0, 5.0, Couleur::Jaune(), p2, light_ambient, light_diffuse, light_specular);
	l0.Enable();
	l1.Enable();


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
	montre->Update();
	glutPostRedisplay();
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
	glutPostRedisplay();
}

void TempsMenu(int selection) {
	switch (selection) {
		case 21  : 
			montre->SetScaleTime(1);
		break;
		case 22  : 
			montre->SetScaleTime(10);
		break;
		case 23  : 
			montre->SetScaleTime(30);
		break;
		case 24  : 
			montre->SetScaleTime(60);
		break;
		case 25  : 
			montre->SetScaleTime(120);
		break;
		case 26  : 
			montre->SetScaleTime(180);
		break;
	}
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
	glutPostRedisplay();
}

void GeneralMenu(int selection) {
	switch (selection) {
		case 0  : 
			exit(0);
		break;

	}
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GL_STENCIL_BUFFER_BIT);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(800, 600);
	glutCreateWindow("light1");

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

	//création d'un cubeHeur
	montre = new Montre();
	room = new TheRoom(12);
	room->BuildAndSave();
	//cubeHeure = new CubeHeure(0,0,0);
	/*

	PPMImage* image1 = new PPMImage("metal-brosse.ppm");
	glGenTextures(1, texName);
    
    glBindTexture(GL_TEXTURE_2D, texName[0]);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image1->GetSizeX(), image1->GetSizeY(),GL_RGB, GL_UNSIGNED_BYTE, image1->GetImage());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	*/

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
      glutAddMenuEntry("Le mécanisme",31);
      glutAddMenuEntry("Toute la montre",32); 

   int menuMode = glutCreateMenu(ModeMenu);
      glutAddMenuEntry("Remonter la montre",41);
      glutAddMenuEntry("Normal",42); 

	// Clavier
	  int menuMontre = glutCreateMenu(GeneralMenu);
      glutAddSubMenu("Arrière plan", menuArrierePlan);
      glutAddSubMenu("Afficher", menuMecanisme);
      glutAddSubMenu("Accélérer le temps", menuTemps);
	  glutAddSubMenu("Mode", menuMode);

  glutCreateMenu(GeneralMenu);
       glutAddSubMenu("Paramètres",menuMontre);
       glutAddMenuEntry("Quitter",0);
       
  /* On associe le choix du bouton gauche de la souris */
  
  glutAttachMenu(GLUT_RIGHT_BUTTON);

	// Aboonnement
	glutDisplayFunc(display) ;
	glutMouseFunc(mouse);
    glutMotionFunc(mousemotion);
	glutIdleFunc(update);
	glutKeyboardFunc(key);
	glutSpecialFunc(specialKey);
  glutReshapeFunc(myReshape);
	glutMainLoop() ;


	delete montre;
	return(0);
}


