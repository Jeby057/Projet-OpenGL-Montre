#include "Armature.h"

Armature::Armature(float longueur, float largeur, float epaisseur) : _longueur(longueur), _largeur(largeur), _epaisseur(epaisseur)
{
}

Armature::~Armature()
{
}

void Armature::BuildAndDisplay()
{
	// Les points pour les faces du dessus (par rapport à l'épaisseur)
	Point3D tabDessus[28];

	// Les points pour les faces du dessous (sert à fermer l'armature en faisant le tour)
	Point3D tabDessous[28];

	// La création est faite en découpant la structure en deux symétriquement (axe horizontal) : une moitié bas et une moitié hauts

	// Remplissage des tableaux
	// moitié bas

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

	// moitié haut
	
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

	// On copie les points des faces de dessus dans le tableau de celles de dessous (en z, on passe le -z des points de dessus)
	for(int i=0; i<27; i+=2)
	{
		tabDessous[i]._x = tabDessus[i+1]._x;
		tabDessous[i]._y = tabDessus[i+1]._y;
		tabDessous[i]._z = -tabDessus[i+1]._z;

		tabDessous[i+1]._x = tabDessus[i]._x;
		tabDessous[i+1]._y = tabDessus[i]._y;
		tabDessous[i+1]._z = -tabDessus[i]._z;
	}
	
	// Tableau des points représentant la face de dessous : elle est pleine car tout est fermé (pas besoin de refaire comme avec le trou pour les faces du dessus)
	Point3D tabBords[11];

	// On se sert du tableau des points des faces de dessous
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

	// Construction des faces du dessus (avec la surélévation)

	Material mat = Material();
	mat.ToBlackReflect();
	mat.Enable();

	float posZ; // Valeur qui change en z pour contruire le surplus d'élévation de la coque sur le dessus
	float epDessus = 4; // on divise l'épaisseur par ce nombre pour obtenir le surplus d'élévation de la coque sur le dessus

	// Moitié haut
	// Tous les deux points (pour QUAD_STRIP) on ajoute l'élévation en z
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

	// Moitié bas
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

	// Construction de la face du dessous

	mat.ToBlackReflect();
	mat.Enable();

	glBegin(GL_TRIANGLE_FAN);
		for(int i=0; i<11; i++)
			glVertex3f(_longueur*tabBords[i]._x, _largeur*tabBords[i]._y , _epaisseur*tabBords[i]._z);
	glEnd();

	// Construction des faces du tour - épaisseur - pour fermer
	// Tour extérieur

	mat.ToSilver();
	mat.Enable();

	// Moitié haut
	glBegin(GL_QUAD_STRIP);
		for(int i=0; i<13; i+=2)
		{
			glVertex3f(this->_longueur*tabDessous[i+1]._x, this->_largeur*tabDessous[i+1]._y, this->_epaisseur*tabDessous[i+1]._z);
			glVertex3f(this->_longueur*tabDessus[i]._x, this->_largeur*tabDessus[i]._y, this->_epaisseur*tabDessus[i]._z);
		}
	glEnd();

	// Moitié bas
	glBegin(GL_QUAD_STRIP);
		for(int i=14; i<27; i+=2)
		{
			glVertex3f(this->_longueur*tabDessus[i+1]._x, this->_largeur*tabDessus[i+1]._y, this->_epaisseur*tabDessus[i+1]._z);
			glVertex3f(this->_longueur*tabDessous[i]._x, this->_largeur*tabDessous[i]._y, this->_epaisseur*tabDessous[i]._z);
		}
	glEnd();

	// Tour intérieur

	mat.ToGreyReflect();
	mat.Enable();
	
	// Moitié haut
	glBegin(GL_QUAD_STRIP);
		for(int i=0; i<13; i+=2)
		{
			glVertex3f(this->_longueur*tabDessus[i+1]._x, this->_largeur*tabDessus[i+1]._y, this->_epaisseur*tabDessus[i+1]._z + _epaisseur / epDessus);
			glVertex3f(this->_longueur*tabDessous[i]._x, this->_largeur*tabDessous[i]._y, this->_epaisseur*tabDessous[i]._z);
		}
	glEnd();
	
	// Moitié bas
	glBegin(GL_QUAD_STRIP);
		for(int i=14; i<27; i+=2)
		{
			glVertex3f(this->_longueur*tabDessous[i+1]._x, this->_largeur*tabDessous[i+1]._y, this->_epaisseur*tabDessous[i+1]._z);
			glVertex3f(this->_longueur*tabDessus[i]._x, this->_largeur*tabDessus[i]._y, this->_epaisseur*tabDessus[i]._z + _epaisseur / epDessus);
		}
	glEnd();

	// Construction de la vitre
	// dans le trou au niveau de la surélévation

	mat = Material(0.05);
	mat.ToBlueDark();
	mat.Enable();

	// Les points représentant le polygone qui décrit la vitre
	Point3D polInterieur[8];

	// L'épaisseur de la vitre
	float epaisseurVitre = 0.1;

	polInterieur[0] = Point3D(_longueur*tabDessus[11]._x, _largeur*tabDessus[11]._y, tabDessus[11]._z + _epaisseur / epDessus - epaisseurVitre);
	polInterieur[1] = Point3D(_longueur*tabDessus[9]._x, _largeur*tabDessus[9]._y, tabDessus[9]._z + _epaisseur / epDessus - epaisseurVitre);
	polInterieur[2] = Point3D(_longueur*tabDessus[5]._x, _largeur*tabDessus[5]._y, tabDessus[5]._z + _epaisseur / epDessus - epaisseurVitre);
	polInterieur[3] = Point3D(_longueur*tabDessus[3]._x, _largeur*tabDessus[3]._y, tabDessus[3]._z + _epaisseur / epDessus - epaisseurVitre);
	polInterieur[4] = Point3D(_longueur*tabDessus[16]._x, _largeur*tabDessus[16]._y, tabDessus[16]._z + _epaisseur / epDessus - epaisseurVitre);
	polInterieur[5] = Point3D(_longueur*tabDessus[18]._x, _largeur*tabDessus[18]._y, tabDessus[18]._z + _epaisseur / epDessus - epaisseurVitre);
	polInterieur[6] = Point3D(_longueur*tabDessus[22]._x, _largeur*tabDessus[22]._y, tabDessus[22]._z + _epaisseur / epDessus - epaisseurVitre);
	polInterieur[7] = Point3D(_longueur*tabDessus[24]._x, _largeur*tabDessus[24]._y, tabDessus[24]._z + _epaisseur / epDessus - epaisseurVitre);

	// La face du dessus
	glBegin(GL_POLYGON);
        for(int i = 0; i < 8; i++)
        {
            glVertex3f(polInterieur[i]._x, polInterieur[i]._y, polInterieur[i]._z);
        }
    glEnd();
	
	// La face du dessous
    glBegin(GL_POLYGON);
        for(int i = 7; i > -1; i--)
        {
            glVertex3f(polInterieur[i]._x, polInterieur[i]._y, polInterieur[i]._z - epaisseurVitre);
        }
    glEnd();
    
	// Le tour pour fermer (crée l'épaisseur)
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
	Material mat = Material();
	mat.ToBlackReflect();
	mat.Enable();
		Piece::FastDisplay();
	mat.Disable();
}
