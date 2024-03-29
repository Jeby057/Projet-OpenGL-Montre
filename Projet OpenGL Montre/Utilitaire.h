/**
 * Classe Utilitaire
 * *****************
 *  Permet d'�x�cuter quelques algorithmes math�mtiques
 *  Ces algorithmes ont �t� r�cup�r�s du projet "modelisation 2D 3D" 2011 de SCHEIBEL Jean-Baptiste
 *
 * Auteurs : GUENDOUL Samir, PIERSON Cyril, SCHEIBEL Jean-Baptiste
 * Modifi� le : 2 D�cembre 2012
 * Version : 1
 */
#ifndef UTILITAIRE_H
#define UTILITAIRE_H

#include "Include.h"

// Structure Point3D
struct Point3D
{
	GLfloat _x, _y, _z;

	Point3D()
	{
		_x = 0;
		_y = 0;
		_z = 0;
	}

	Point3D(GLfloat x, GLfloat y, GLfloat z)
	{
		_x = x;
		_y = y;
		_z = z;
	}
};

class Utilitaire
{
public:


	static void EquationDroite (double x1, double y1, double x2, double y2,
								double *Pa, double *Pb, double *Pc) ;

	static double DistancePointDroite (double x, double y, double x1,
										double y1, double x2, double y2);

	static void IntersectionsDroiteCercleOrigine (double x1, double y1, double x2,
													double y2, double R, int* PNbInt,
													double* pxi1, double* pyi1,
													double* pxi2, double* pyi2);

	static void IntersectionsDroiteCercle (double x1, double y1, double x2, double y2,
											double xc, double yc, double R, int* PNbInt,
											double* pxi1, double* pyi1, double* pxi2,
											double* pyi2);

private:
	static const double EpsDistance;
};
#endif
