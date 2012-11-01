#include "CubeHeure.h"


CubeHeure::CubeHeure(float x, float y, float z): _posX(x), _posY(y), _posZ(z)
{
	this->angleRotation = 360;
	this->temps = 0;
}


CubeHeure::~CubeHeure(void)
{
}


void CubeHeure::Build()
{
	 
	
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