#include "Engrenage.h"

Engrenage::Engrenage(double module, double diametreTravail, double longueur, double coteCarre)
	:_module(module),
	 _diametreTravail(diametreTravail),
	 _longueur(longueur),
	 _coteCarre(coteCarre)
{
}


Engrenage::~Engrenage(void)
{
}


void Engrenage::Build()
{
	// Calcul de la longueur de l'arc entre 2 centres de dent
	GLfloat pas = PI * _module;

	// Calcul du diametre de tete
	GLfloat diametreTete = _diametreTravail + 2 * _module;

	// Calcul du diametre de pied
	GLfloat diametrePied = _diametreTravail - 2.5 * _module;

	// Angle des flans de denture
	GLfloat angleDent = PI / 9; // 20°

	// Angle du quart de pas
	GLfloat anglePas = 2 * pas / _diametreTravail;

	// Calcul du nombre de dents
	_nbDents = ceil(_diametreTravail / _module);

	// Point central de la dent primitive
	Point3D ptCentreDent(_diametreTravail/2, 0, 0);

	//Point de passage de la droite des flans de denture sur le diamètre primitif
	GLfloat alpha = anglePas/4;
	Point3D ptPassageFlanTrigo(ptCentreDent._x * cosf(alpha) - ptCentreDent._y * sinf(alpha), ptCentreDent._x * sinf(alpha) + ptCentreDent._y * cosf(alpha), ptCentreDent._z);
	
	// Droite des flans de denture
	Point3D vectFlan(-cosf(angleDent),sinf(angleDent),0);
	Point3D pt2 = ptPassageFlanTrigo;
	pt2._x += vectFlan._x*10;
	pt2._y += vectFlan._y*10;
	pt2._z += vectFlan._z*10;

	//Calcul du point d'intersection entre la droite de flan et le diamètre de pied
	double pxi1,pyi1,pxi2,pyi2;
	int nbPoint;
	Utilitaire::IntersectionsDroiteCercle(ptPassageFlanTrigo._x,ptPassageFlanTrigo._y,ptPassageFlanTrigo._x-2,ptPassageFlanTrigo._y,0,0,diametrePied/2,&nbPoint,&pxi1,&pyi1,&pxi2,&pyi2);
	Point3D ptIntersectionFlanPiedTrigo(pxi1,pyi1,0);

	//Calcul du point d'intersection entre la droite de flan et le diamètre de tête
	Utilitaire::IntersectionsDroiteCercle(ptPassageFlanTrigo._x,ptPassageFlanTrigo._y,pt2._x,pt2._y,0,0,diametreTete/2,&nbPoint,&pxi1,&pyi1,&pxi2,&pyi2);
	Point3D ptIntersectionFlanTeteTrigo(pxi1,pyi1,0);

	//Point d'intersection symétrique à ptIntersectionFlanTeteTrigo
	Point3D ptIntersectionFlanTeteHoraire(ptIntersectionFlanTeteTrigo._x, ptIntersectionFlanTeteTrigo._y * cosf(PI) - ptIntersectionFlanTeteTrigo._z * sinf(PI), ptIntersectionFlanTeteTrigo._y * sinf(PI) + ptIntersectionFlanTeteTrigo._z * cosf(PI));

	//Point d'intersection symétrique à ptIntersectionFlanPiedTrigo
	Point3D ptIntersectionFlanPiedHoraire(ptIntersectionFlanPiedTrigo._x, ptIntersectionFlanPiedTrigo._y * cosf(PI) - ptIntersectionFlanPiedTrigo._z * sinf(PI), ptIntersectionFlanPiedTrigo._y * sinf(PI) + ptIntersectionFlanPiedTrigo._z * cosf(PI));

	Point3D *ptDenture = new Point3D[_nbDents*4];

	// Alimentation du profil avec les points de la première denture
	ptDenture[0]=ptIntersectionFlanPiedHoraire;
	ptDenture[1]=ptIntersectionFlanTeteHoraire;
	ptDenture[2]=ptIntersectionFlanTeteTrigo;
	ptDenture[3]=ptIntersectionFlanPiedTrigo;

	//Alimentation du tableau de points du profil en prenant le point
	//à la case [courante -4] sur lequel on applique la rotation d'un pas
	for (unsigned int i =1;i<_nbDents;i++){
		for(unsigned int j=0;j<4;j++){
			ptDenture[i*4+j] = Point3D(ptDenture[4*(i-1)+j]._x * cosf(anglePas) - ptDenture[4*(i-1)+j]._y * sinf(anglePas), ptDenture[4*(i-1)+j]._x * sinf(anglePas) + ptDenture[4*(i-1)+j]._y * cosf(anglePas), ptDenture[4*(i-1)+j]._z);
		}
	}

	// Création de la roue dentée ( face avant)
	Point3D ref = Point3D(ptDenture[0]._x, ptDenture[0]._y, ptDenture[0]._z);
	glBegin(GL_TRIANGLE_FAN);
	
		glVertex3f(0.0, 0.0, ptDenture[0]._z);
		for (unsigned int i =0;i<_nbDents*4;i++)
		{
			glVertex3f(ptDenture[i]._x, ptDenture[i]._y, ptDenture[i]._z);
		}
		glVertex3f(ptDenture[0]._x, ptDenture[0]._y, ptDenture[0]._z);
	glEnd();

	// Création de la roue dentée ( face arriere)
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0, 0.0, ptDenture[0]._z + _longueur);
		for (unsigned int i =0;i<_nbDents*4;i++)
		{
			glVertex3f(ptDenture[i]._x, ptDenture[i]._y, ptDenture[i]._z + _longueur);
		}
		glVertex3f(ptDenture[0]._x, ptDenture[0]._y, ptDenture[0]._z + _longueur);
	glEnd();

	// Création des sties des dents
	glBegin(GL_TRIANGLE_STRIP);
		for (unsigned int i =0;i<_nbDents*4;i++)
		{
			if(i%2==0)
				glTexCoord2d(0.0,0.0);
			else
				glTexCoord2d(1.0,0.0);
			glVertex3f(ptDenture[i]._x, ptDenture[i]._y, ptDenture[i]._z);
			if(i%2==0)
				glTexCoord2d(0.0,1.0);
			else
				glTexCoord2d(1.0,1.0);
			glVertex3f(ptDenture[i]._x, ptDenture[i]._y, ptDenture[i]._z + _longueur);
		}
		glTexCoord2d(0.0,0.0);
		glVertex3f(ptDenture[0]._x, ptDenture[0]._y, ptDenture[0]._z);
		glTexCoord2d(0.0,1.0);
		glVertex3f(ptDenture[0]._x, ptDenture[0]._y, ptDenture[0]._z + _longueur);
	glEnd();
}