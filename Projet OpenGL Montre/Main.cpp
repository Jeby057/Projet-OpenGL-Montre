#include "include.h"
#include "Engrenage.h"
#include "TrackBallCamera.h"

float campX = 0.0F, campY = -5.0F, campZ = -6.0F, camdX = 0.0F, camdY = 0.0F, camdZ = 0.0F, camvX = 0.0F, camvY = 1.0F, camvZ = 0.0F;
GLfloat L0pos[]={ 0.0,1.0,-1.0};
/* parametres diffus en R,V,B */
GLfloat L0dif[]={ 1.0,0.5,0.4};
GLfloat Mshiny=50;

TrackBallCamera* camera;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );
	//gluLookAt(campX, campY, campZ, camdX, camdY, camdZ, camvX, camvY, camvZ);
	camera->Look();

	glLightfv(GL_LIGHT0,GL_POSITION,L0pos);

	GLfloat material[] = {1.0f, 0.0f, 0.0f, 1.0f};
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, material); 

	Piece* engrenage = new Engrenage(0.1, 0.1*50, 0.3, 3);
	engrenage->Build();
	
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


int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(400,400);
	glutCreateWindow("light1");

	// Initialisation
	glClearColor(1.0,1.1,1.1,0.0);
	glColor3f(1.0,0.0,0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	// Lissage
	glShadeModel(GL_SMOOTH);

	// Lumiere
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,L0dif);

	// Perspective
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,1.0,0.1,10.0);
	glMatrixMode(GL_MODELVIEW);

	glutDisplayFunc(display) ;

	// Création d'une trackball caméra
	camera = new TrackBallCamera();
    camera->SetScrollSensivity(0.1);
    camera->SetMotionSensivity(0.1);

	// Aboonnement
	glutMouseFunc(mouse);
    glutMotionFunc(mousemotion);
	glutKeyboardFunc(key);
	glutMainLoop() ;

	return(0);
}


