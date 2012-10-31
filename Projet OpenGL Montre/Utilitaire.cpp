#include "Utilitaire.h"

const double Utilitaire::EpsDistance = 0.001 ;            // Distance sous laquelle deux points sont considérés superposés

Utilitaire::Utilitaire(void)
{
}


Utilitaire::~Utilitaire(void)
{
}

// Calcule l'équation d'une droite passant par les points (x1,y1) et (x2,y2), // supposés DIFFERENTS !!
void Utilitaire::EquationDroite (double x1, double y1, double x2, double y2, double *Pa, double *Pb, double *Pc) 
{
     *Pb = x1 - x2 ;
	 *Pa = y2 - y1 ; 
	 *Pc = -*Pa * x1 - *Pb * y1 ; 
}

// Distance du point (x,y) à la droite (P1,P2) 
double Utilitaire::DistancePointDroite (double x, double y, double x1, double y1, double x2, double y2)
{
     double    a,b,c ;

    EquationDroite (x1,y1,x2,y2,&a,&b,&c) ;

    double    norme = sqrt (a*a + b*b),
                dist = fabs (a*x + b*y + c) / norme ;

    return dist ;
}

void Utilitaire::IntersectionsDroiteCercleOrigine (double x1, double y1, double x2, double y2, double R,
													int* PNbInt, double* pxi1, double* pyi1, double* pxi2, double* pyi2)
//
// *PNbInt est le nombre d'intersections :
//    -1 si données incohérentes
// 1 si tangence
{
     if (((x1 == x2) && (y1 == y2)) || (R <= 0)) {
        *PNbInt = -1 ; return ;
    }

     double    dx = x2 - x1,
                dy = y2 - y1,
             LongueurCarree = dx*dx + dy*dy,
             D = DistancePointDroite (0,0,x1,y1,x2,y2),
             DeltaDist = R - D ;

    if (fabs (DeltaDist) < EpsDistance) {    // Tangence
        *PNbInt = 1 ;

       double    Param = -(x1*dx + y1*dy) / LongueurCarree ;
       *pxi1 = x1 + Param*dx ;
       *pyi1 = y1 + Param*dy ;
    }
    else if (DeltaDist >= EpsDistance) {    // 2 intersections
        *PNbInt = 2 ;

       // METHODE 1
       double    K = -(x1*dx + y1*dy) / sqrt (LongueurCarree) ;
       double    L = sqrt (R*R - D*D) ;
       double    Param1 = (K-L) / sqrt (LongueurCarree),
                   Param2 = (K+L) / sqrt (LongueurCarree) ;
       *pxi1 = x1 + Param1*dx ;
       *pyi1 = y1 + Param1*dy ;
       *pxi2 = x1 + Param2*dx ;
       *pyi2 = y1 + Param2*dy ;
    }
    else
        *PNbInt = 0 ;
}

void Utilitaire::IntersectionsDroiteCercle (double x1, double y1, double x2, double y2, double xc, double yc, double R, int* PNbInt, double* pxi1, double* pyi1, double* pxi2, double* pyi2)
// Intersections d'une droite quelconque et d'un cercle // // *PNbInt est le nombre d'intersections :
//    -1 si données incohérentes
// 1 si tangence
// 0 ou 2 dans les autres cas.
{
     // Changement de repère
    x1 -= xc ; y1 -= yc ;
    x2 -= xc ; y2 -= yc ;

     IntersectionsDroiteCercleOrigine(x1,y1,x2,y2,R,PNbInt,pxi1,pyi1,pxi2,pyi2) ;

    if (*PNbInt > 0) {
        *pxi1 += xc ; *pyi1 += yc ;    // Changement de repère

       if (*PNbInt > 1)
            *pxi2 += xc ; *pyi2 += yc ;    // Changement de repère
    }
}