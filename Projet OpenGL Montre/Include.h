#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

#include <gl/glut.h>

#include <cmath>
#define PI (3.141592653589793)
#define DEGREES_TO_RADIANS(angle) ((angle) / 180.0 * PI)
#define RADIANS_TO_DEGREES(radians) ((radians) * (180.0 / PI))

#include "Utilitaire.h"
#include "Couleurs.h"
#include "Material.h"
#include "Light.h"
#include "SpotLight.h"

#endif
