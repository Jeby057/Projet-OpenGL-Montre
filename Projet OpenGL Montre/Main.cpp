#include "include.h"
#include "Engrenage.h"
#include "CubeHeure.h"
#include "TrackBallCamera.h"
#include "BrasMaitre.h"
#include "Disque.h"
#include "Maitresse.h"
#include "Montre.h"
#include "PartialCylinder.h"
int LightPos[4] = {-1,2,-1,2};
int MatSpec [4] = {1,1,1,1};

/* parametres diffus en R,V,B */
GLfloat L0dif[]={ 1.0,0.5,0.4};
GLfloat Mshiny=50;

TrackBallCamera* camera;
CubeHeure* cubeHeure;

Piece* montre;

	GLuint texName[2];

void display()
{
	glLightiv(GL_LIGHT0,GL_POSITION,LightPos);

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

	
	glBegin(GL_QUADS);
	glColor3ub(114, 157, 187);
    glVertex3i(-10,0,-10);
    glVertex3i(10,0,-10);
    glVertex3i(10,0,10);
    glVertex3i(-10,0,10);
    glEnd();
	
	glPushMatrix();
		glTranslatef(0, 0.5, 0);
		montre->BuildAndDisplay();
	glPopMatrix();
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
	camera->OnKeyboard(key, x, y);
	glutPostRedisplay();
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

int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GL_STENCIL_BUFFER_BIT);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(800, 600);
	glutCreateWindow("light1");

	// Initialisation
	//glColor3f(1.0,0.0,0.0);
	glDepthFunc(GL_LESS);

	// Lissage
	glShadeModel(GL_SMOOTH);

	// Lumiere
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Création d'une trackball caméra
	camera = new TrackBallCamera();
    camera->SetScrollSensivity(0.1);
    camera->SetMotionSensivity(0.1);
	camera->SetOffsetSensivity(0.05);

	//création d'un cubeHeur
	montre = new Montre();
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
	// Aboonnement
	glutDisplayFunc(display) ;
	glutMouseFunc(mouse);
    glutMotionFunc(mousemotion);
	glutIdleFunc(update);
	glutKeyboardFunc(key);
  glutReshapeFunc(myReshape);
	glutMainLoop() ;


	delete montre;
	return(0);
}


