#include "CubeHeure.h"


CubeHeure::CubeHeure(float x, float y, float z): _posX(x), _posY(y), _posZ(z)
{
	this->angleRotation = 360;
	this->temps = 0;

	char* namFace[6] = {"textures/1.ppm", "textures/2.ppm", "textures/3.ppm", "textures/4.ppm", "textures/13.ppm", "textures/13.ppm"};

	this->LoadTexture(namFace);
}


CubeHeure::~CubeHeure(void)
{
}


void CubeHeure::Build()
{
	 



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //face1
	glBindTexture(GL_TEXTURE_2D, this->_faceTexture[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.3, -0.20, 0.20);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.3, 0.20, 0.20);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.3, 0.20, 0.20);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.3, -0.20, 0.20);
	glEnd();
	
	//face2
	glBindTexture(GL_TEXTURE_2D, this->_faceTexture[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-0.3, -0.20, -0.20);
	glTexCoord2f(0.0, 1.0); glVertex3f(-0.3, 0.20, -0.20);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.3, 0.20, -0.20);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.3, -0.20, -0.20);
	glEnd();

	
	//face3
	glBindTexture(GL_TEXTURE_2D, this->_faceTexture[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-0.3, -0.20, 0.20);
	glTexCoord2f(0.0, 1.0); glVertex3f(-0.3, -0.20, -0.20);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.3, -0.20, -0.20);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.3, -0.20, 0.20);
	glEnd();

	//face4
	glBindTexture(GL_TEXTURE_2D, this->_faceTexture[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.3, 0.20, 0.20);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.3, 0.20, -0.20);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.3, 0.20, -0.20);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.3, 0.20, 0.20);
	glEnd();
   

	//face5
	glBindTexture(GL_TEXTURE_2D, this->_faceTexture[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-0.3, 0.20, -0.20);
	glTexCoord2f(0.0, 1.0); glVertex3f(-0.3, 0.20, 0.20);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.3, -0.20, 0.20);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.3, -0.20, -0.20);
	glEnd();

	//face6
	glBindTexture(GL_TEXTURE_2D, this->_faceTexture[5]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.3, 0.20, -0.20);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.3, 0.20, 0.20);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.3, -0.20, 0.20);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.3, -0.20, -0.20);
	glEnd();

	/*
	glBindTexture(GL_TEXTURE_2D, this->_faceTexture[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 1.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 1.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 1.0, 1.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.0, -1.0, 1.0);
	glEnd();
   
	glBindTexture(GL_TEXTURE_2D, this->_faceTexture[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(1.0, 0.0, -1.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 0.0, 1.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 0.0, 1.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.0, 0.0, -1.0);
	glEnd();
	


	/*
	glPushMatrix(); //retaion sur laxe 0.0.0
	glRotatef(angleRotation,0, 1, 0);
	glTranslatef(0.5,0,0);

	glPushMatrix(); //retaion sur laxe cube
	//glRotatef(angleRotation,0, 1, 0);

	glPushMatrix(); //cone et cube
	glRotatef(angleRotation,1.0F,0.0F,0.0F); //rotation 
	
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Couleur::Jaune(2.0F)) ;
	glTranslatef(0.0,0.0,0.0) ;
	glutSolidCube(0.09); 

	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Couleur::Rose(5.0F)) ;
	glTranslatef(0.045,0.0,0.0) ;
	glRotatef(90,0.0F,1.0F,0.0F); //rotation 
	glutSolidCone(0.04,0.1,100,100) ;

	glPopMatrix(); //cone et cube

	glPopMatrix(); //retaion sur laxe de cube

	glPopMatrix(); //retaion sur laxe 0.0.0
	*/
}

void CubeHeure::idle()
{
	this->temps++;
	if(this->temps == 10)
	{
		this->angleRotation -=1;
		this->temps = 0;
		if(this->angleRotation == 0)
			this->angleRotation = 360;
	}
}


void CubeHeure::LoadTexture(char* face[6])
{
	glGenTextures(6, this->_faceTexture);
	for(int i = 0; i <6; i++)
	{
		PPMImage* image1 = new PPMImage(face[i]);
		glBindTexture(GL_TEXTURE_2D, this->_faceTexture[i]);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image1->GetSizeX(), image1->GetSizeY(),GL_RGB, GL_UNSIGNED_BYTE, image1->GetImage());
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	}

}