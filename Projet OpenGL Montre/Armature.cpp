#include "Armature.h"

Armature::Armature(float longueur, float largeur, float epaisseur) : _longueur(longueur), _largeur(largeur), _epaisseur(epaisseur) //, _rayonTurbine(rayonTurbine), _decalTurbX(decalTurbX), _decalTurbY(decalTurbY)
{
	_transparency = 1.0;
}

Armature::~Armature()
{
}

void Armature::BuildAndDisplay()
{

	

	//this->RepereMonde(1);

	Point3D * tabDessus = new Point3D [28];
	Point3D * tabDessous = new Point3D [28];

	// moitié de bas

	tabDessus[0] = Point3D(0.5, 0.0, 0.5);
	tabDessus[1] = Point3D(0.45, 0.0, 0.5);
	tabDessus[2] = Point3D(0.5, -0.25, 0.5);
	tabDessus[3] = Point3D(0.45, -0.2, 0.5);

	tabDessus[4] = Point3D(0.28, -0.4, 0.5);
	tabDessus[5] = Point3D(0.25, -0.35, 0.5);

	tabDessus[6] = Point3D(0.2, -0.5, 0.5);
	tabDessus[7] = Point3D(0.2, -0.35, 0.5);

	tabDessus[8] = Point3D(-0.35, -0.5, 0.5);
	tabDessus[9] = Point3D(-0.2, -0.35, 0.5);

	tabDessus[10] = Point3D(-0.5, -0.35, 0.5);
	tabDessus[11] = Point3D(-0.35, -0.2, 0.5);

	tabDessus[12] = Point3D(-0.5, 0.0, 0.5);
	tabDessus[13] = Point3D(-0.35, 0.0, 0.5);

	// moitié haute
	
	tabDessus[14] = Point3D(0.45, 0.0, 0.5);
	tabDessus[15] = Point3D(0.5, 0.0, 0.5);
	tabDessus[16] = Point3D(0.45, 0.2, 0.5);
	tabDessus[17] = Point3D(0.5, 0.25, 0.5);
	
	tabDessus[18] = Point3D(0.25, 0.35, 0.5);
	tabDessus[19] = Point3D(0.28, 0.4, 0.5);
	
	tabDessus[20] = Point3D(0.2, 0.35, 0.5);
	tabDessus[21] = Point3D(0.2, 0.5, 0.5);
	
	tabDessus[22] = Point3D(-0.2, 0.35, 0.5);
	tabDessus[23] = Point3D(-0.35, 0.5, 0.5);

	tabDessus[24] = Point3D(-0.35, 0.2, 0.5);
	tabDessus[25] = Point3D(-0.5, 0.35, 0.5);
	
	tabDessus[26] = Point3D(-0.35, 0.0, 0.5);
	tabDessus[27] = Point3D(-0.5, 0.0, 0.5);

	for(int i=0; i<27; i+=2)
	{
		tabDessous[i]._x = tabDessus[i+1]._x;
		tabDessous[i]._y = tabDessus[i+1]._y;
		tabDessous[i]._z = -tabDessus[i+1]._z;

		tabDessous[i+1]._x = tabDessus[i]._x;
		tabDessous[i+1]._y = tabDessus[i]._y;
		tabDessous[i+1]._z = -tabDessus[i]._z;
	}
	
	Point3D * tabBords  = new Point3D[11];

	tabBords[0] = Point3D(tabDessous[13]._x, tabDessous[13]._y, tabDessous[13]._z);
	tabBords[1] = Point3D(tabDessous[24]._x, tabDessous[24]._y, tabDessous[24]._z);
	tabBords[2] = Point3D(tabDessous[22]._x, tabDessous[22]._y, tabDessous[22]._z);
	tabBords[3] = Point3D(tabDessous[20]._x, tabDessous[20]._y, tabDessous[20]._z);
	tabBords[4] = Point3D(tabDessous[18]._x, tabDessous[18]._y, tabDessous[18]._z);
	tabBords[5] = Point3D(tabDessous[16]._x, tabDessous[16]._y, tabDessous[16]._z);
	tabBords[6] = Point3D(tabDessous[3]._x, tabDessous[3]._y, tabDessous[3]._z);
	tabBords[7] = Point3D(tabDessous[5]._x, tabDessous[5]._y, tabDessous[5]._z);
	tabBords[8] = Point3D(tabDessous[7]._x, tabDessous[7]._y, tabDessous[7]._z);
	tabBords[9] = Point3D(tabDessous[9]._x, tabDessous[9]._y, tabDessous[9]._z);
	tabBords[10] = Point3D(tabDessous[11]._x, tabDessous[11]._y, tabDessous[11]._z);

	/*Point3D centreTurbine = Point3D(tabDessous[1]._x - _decalTurbX, tabDessous[1]._y - _decalTurbY, _epaisseur*tabDessous[0]._z);

	float cote = 5.0/12;

	tabTrou[0] = Point3D(centreTurbine._x + _rayonTurbine*cote, centreTurbine._y + _rayonTurbine, centreTurbine._z);
	tabTrou[1] = Point3D(centreTurbine._x - _rayonTurbine*cote, centreTurbine._y + _rayonTurbine, centreTurbine._z);
	tabTrou[2] = Point3D(centreTurbine._x - _rayonTurbine, centreTurbine._y + _rayonTurbine*cote, centreTurbine._z);
	tabTrou[3] = Point3D(centreTurbine._x - _rayonTurbine, centreTurbine._y - _rayonTurbine*cote, centreTurbine._z);
	tabTrou[4] = Point3D(centreTurbine._x - _rayonTurbine*cote, centreTurbine._y - _rayonTurbine, centreTurbine._z);
	tabTrou[5] = Point3D(centreTurbine._x + _rayonTurbine*cote, centreTurbine._y - _rayonTurbine, centreTurbine._z);
	tabTrou[6] = Point3D(centreTurbine._x + _rayonTurbine, centreTurbine._y - _rayonTurbine*cote, centreTurbine._z);
	tabTrou[7] = Point3D(centreTurbine._x + _rayonTurbine, centreTurbine._y + _rayonTurbine*cote, centreTurbine._z);*/

	// face dessus

	Material mat = Material();
	mat.ToBlackRubber();
	mat.Enable();

	float posZ;
	float epDessus = 4; // on divise l'épaisseur par ce nombre pour obtenir le surplus d'élévation de la coque sur le dessus
	
	glBegin(GL_QUAD_STRIP);
		for(int i=0; i<14; i++)
		{
			if(i % 2 != 0)
				posZ = this->_epaisseur*tabDessus[i]._z + _epaisseur / epDessus;
			else
				posZ = this->_epaisseur*tabDessus[i]._z;

			glVertex3f(this->_longueur*tabDessus[i]._x, this->_largeur*tabDessus[i]._y, posZ);
		}
	glEnd();

	glBegin(GL_QUAD_STRIP);
		for(int i=14; i<28; i++)
		{
			if(i % 2 == 0)
				posZ = this->_epaisseur*tabDessus[i]._z + _epaisseur / epDessus;
			else
				posZ = this->_epaisseur*tabDessus[i]._z;

			glVertex3f(this->_longueur*tabDessus[i]._x, this->_largeur*tabDessus[i]._y, posZ);
		}
	glEnd();

	// face dessous

	mat.ToBlackRubber();
	mat.Enable();

	glBegin(GL_TRIANGLE_FAN);
		for(int i=0; i<11; i++)
			glVertex3f(_longueur*tabBords[i]._x, _largeur*tabBords[i]._y , _epaisseur*tabBords[i]._z);
	glEnd();

	// moitié bas
	/*
	glBegin(GL_TRIANGLE_STRIP);
		for(int i = 0; i < 7; i++)
		{
			glVertex3f(tabTrou[i]._x, tabTrou[i]._y, tabTrou[i]._z);
			glVertex3f(tabBords[i]._x, tabBords[i]._y, tabBords[i]._z);
		}
		glVertex3f(tabTrou[7]._x, tabTrou[7]._y, tabTrou[7]._z);
		glVertex3f(tabBords[0]._x, tabBords[0]._y, tabBords[0]._z);
		glVertex3f(tabTrou[0]._x, tabTrou[0]._y, tabTrou[0]._z);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		for(int i = 6; i > -1; i--)
		{
			glVertex3f(tabTrou[i]._x, tabTrou[i]._y, tabTrou[i]._z);
			glVertex3f(tabBords[i]._x, tabBords[i]._y, tabBords[i]._z);
		}
		glVertex3f(tabTrou[7]._x, tabTrou[7]._y, tabTrou[7]._z);
		glVertex3f(tabBords[6]._x, tabBords[6]._y, tabBords[6]._z);
		glVertex3f(tabTrou[6]._x, tabTrou[6]._y, tabTrou[6]._z);
	glEnd();*/

	// moitié haut

	// tour
	// extérieur
	mat.ToSilver();
	mat.Enable();
	
	glBegin(GL_QUAD_STRIP);
		for(int i=0; i<13; i+=2)
		{
			glVertex3f(this->_longueur*tabDessous[i+1]._x, this->_largeur*tabDessous[i+1]._y, this->_epaisseur*tabDessous[i+1]._z);
			glVertex3f(this->_longueur*tabDessus[i]._x, this->_largeur*tabDessus[i]._y, this->_epaisseur*tabDessus[i]._z);
		}
	glEnd();

	glBegin(GL_QUAD_STRIP);
		for(int i=14; i<27; i+=2)
		{
			glVertex3f(this->_longueur*tabDessus[i+1]._x, this->_largeur*tabDessus[i+1]._y, this->_epaisseur*tabDessus[i+1]._z);
			glVertex3f(this->_longueur*tabDessous[i]._x, this->_largeur*tabDessous[i]._y, this->_epaisseur*tabDessous[i]._z);
		}
	glEnd();

	// intérieur
	mat.ToGreyReflect();
	mat.Enable();
	

	glBegin(GL_QUAD_STRIP);
		for(int i=0; i<13; i+=2)
		{
			glVertex3f(this->_longueur*tabDessus[i+1]._x, this->_largeur*tabDessus[i+1]._y, this->_epaisseur*tabDessus[i+1]._z + _epaisseur / epDessus);
			glVertex3f(this->_longueur*tabDessous[i]._x, this->_largeur*tabDessous[i]._y, this->_epaisseur*tabDessous[i]._z);
		}
	glEnd();
	
	glBegin(GL_QUAD_STRIP);
		for(int i=14; i<27; i+=2)
		{
			glVertex3f(this->_longueur*tabDessous[i+1]._x, this->_largeur*tabDessous[i+1]._y, this->_epaisseur*tabDessous[i+1]._z);
			glVertex3f(this->_longueur*tabDessus[i]._x, this->_largeur*tabDessus[i]._y, this->_epaisseur*tabDessus[i]._z + _epaisseur / epDessus);
		}
	glEnd();


	// Vitre
	mat = Material(0.05);
	mat.ToBlueDark();
	mat.Enable();

	Point3D * polInterieur = new Point3D[8];
	float epaisseurVitre = 0.1;

	polInterieur[0] = Point3D(_longueur*tabDessus[11]._x, _largeur*tabDessus[11]._y, tabDessus[11]._z + _epaisseur / epDessus - epaisseurVitre);
	polInterieur[1] = Point3D(_longueur*tabDessus[9]._x, _largeur*tabDessus[9]._y, tabDessus[9]._z + _epaisseur / epDessus - epaisseurVitre);
	polInterieur[2] = Point3D(_longueur*tabDessus[5]._x, _largeur*tabDessus[5]._y, tabDessus[5]._z + _epaisseur / epDessus - epaisseurVitre);
	polInterieur[3] = Point3D(_longueur*tabDessus[3]._x, _largeur*tabDessus[3]._y, tabDessus[3]._z + _epaisseur / epDessus - epaisseurVitre);
	polInterieur[4] = Point3D(_longueur*tabDessus[16]._x, _largeur*tabDessus[16]._y, tabDessus[16]._z + _epaisseur / epDessus - epaisseurVitre);
	polInterieur[5] = Point3D(_longueur*tabDessus[18]._x, _largeur*tabDessus[18]._y, tabDessus[18]._z + _epaisseur / epDessus - epaisseurVitre);
	polInterieur[6] = Point3D(_longueur*tabDessus[22]._x, _largeur*tabDessus[22]._y, tabDessus[22]._z + _epaisseur / epDessus - epaisseurVitre);
	polInterieur[7] = Point3D(_longueur*tabDessus[24]._x, _largeur*tabDessus[24]._y, tabDessus[24]._z + _epaisseur / epDessus - epaisseurVitre);

	glBegin(GL_POLYGON);
        for(int i = 0; i < 8; i++)
        {
            glVertex3f(polInterieur[i]._x, polInterieur[i]._y, polInterieur[i]._z);
        }
    glEnd();
	
    glBegin(GL_POLYGON);
        for(int i = 7; i > -1; i--)
        {
            glVertex3f(polInterieur[i]._x, polInterieur[i]._y, polInterieur[i]._z - epaisseurVitre);
        }
    glEnd();
    
    glBegin(GL_QUAD_STRIP);
        for(int i = 0; i < 8; i++)
        {
            glVertex3f(polInterieur[i]._x, polInterieur[i]._y, polInterieur[i]._z);
            glVertex3f(polInterieur[i]._x, polInterieur[i]._y, polInterieur[i]._z - epaisseurVitre);
        }
        glVertex3f(polInterieur[0]._x, polInterieur[0]._y, polInterieur[0]._z);
        glVertex3f(polInterieur[0]._x, polInterieur[0]._y, polInterieur[0]._z - epaisseurVitre);
    glEnd();
	
	mat.Disable();

}

void Armature::FastDisplay()
{
	Material mat = Material(_transparency);
	mat.ToBlackReflect();
	mat.Enable();
		Piece::FastDisplay();
	mat.Disable();
}



void Armature::SetTransparency(float transparency){
	_transparency = transparency;
}