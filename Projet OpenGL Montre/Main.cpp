#include "include.h"
#include "Engrenage.h"
#include "CubeHeure.h"
#include "TrackBallCamera.h"

GLfloat L0pos[]={ 0.0,1.0,-1.0};
GLfloat L1pos[]={ 2.0,2.0,2.0};

/* parametres diffus en R,V,B */
GLfloat L0dif[]={ 1.0,0.5,0.4};
GLfloat Mshiny=50;

TrackBallCamera* camera;
CubeHeure* cubeHeure;

void display()
{
	glClearColor(1.0,1.1,1.1,0.0);
	camera->Look();

	GLfloat material[] = {0.1f, 0.1f, 0.1f, 0.8f};
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, material); 

	Piece* engrenage = new Engrenage(0.01, 0.01*30, 0.05, 3);
	engrenage->Build();

	//creer le cube heure
	//cubeHeure->Build();
	
	glLightfv(GL_LIGHT0,GL_POSITION,L0pos);
	glLightfv(GL_LIGHT1,GL_POSITION,L1pos);

	glutSwapBuffers();

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
	camera->OnKeyboard(key, x, y);
	glutPostRedisplay();
}

void myReshape(int w,int h) {
	camera->SetFrameSize(w, h);
	glutPostRedisplay();
}


int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(800, 600);
	glutCreateWindow("light1");

	// Initialisation
	//glColor3f(1.0,0.0,0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	// Lissage
	glShadeModel(GL_SMOOTH);

	// Lumiere
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat l_pos[] = { 0.0, 0.0, -3.0,0.0 };
	glLightfv(GL_LIGHT0,GL_POSITION,l_pos);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	/*glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,L0dif);*/

	glutDisplayFunc(display) ;

	// Création d'une trackball caméra
	camera = new TrackBallCamera();
    camera->SetScrollSensivity(0.1);
    camera->SetMotionSensivity(0.1);
	camera->SetOffsetSensivity(0.05);

	//création d'un cubeHeur
	cubeHeure = new CubeHeure(0,0,0);

	// Aboonnement
	glutMouseFunc(mouse);
    glutMotionFunc(mousemotion);
	glutKeyboardFunc(key);
  glutReshapeFunc(myReshape);
	glutMainLoop() ;

	return(0);
}


