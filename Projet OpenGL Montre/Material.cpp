#include "Material.h"


Material::Material(GLfloat alpha)
{
	_ambiant[3] = alpha;
}



Material::Material(const GLfloat ambiant[4], const GLfloat diffuse[3], const GLfloat specular[3], const GLfloat shininess, GLfloat alpha)
{
	_shininess = shininess;
	_ambiant[3] = alpha;
	for(int i=0; i<4; i++)
	{
		_ambiant[i] = ambiant[i];
		if(i!=3){
			_diffuse[i] = diffuse[i];
			_specular[i] = specular[i];
		}
	}
}


Material::~Material()
{
}


void Material::Enable()
{
	if(_ambiant[3] != 1.0){
		glEnable(GL_BLEND) ;
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT, _ambiant);
	glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, _diffuse);
	glMaterialfv (GL_FRONT_AND_BACK, GL_SPECULAR, _specular);
	glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, _shininess * 128.0);
}

void Material::Disable()
{
	glDisable(GL_BLEND);
}

void Material::ToChrome()
{
	_ambiant[0] = 0.25;
	_ambiant[1] = 0.25;
	_ambiant[2] = 0.25;
	_diffuse[0] = 0.4;
	_diffuse[1] = 0.4;
	_diffuse[2] = 0.4;
	_specular[0] = 0.774597;
	_specular[1] = 0.774597;
	_specular[2] = 0.774597;
	_shininess = 0.6;
}

void Material::ToSilver()
{
	_ambiant[0] = 0.19225;
	_ambiant[1] = 0.19225;
	_ambiant[2] = 0.19225;
	_diffuse[0] = 0.50754;
	_diffuse[1] = 0.50754;
	_diffuse[2] = 0.50754;
	_specular[0] = 0.508273;
	_specular[1] = 0.508273;
	_specular[2] = 0.508273;
	_shininess = 0.4;
}

void Material::ToBlackRubber()
{
	_ambiant[0] = 0.02;
	_ambiant[1] = 0.02;
	_ambiant[2] = 0.02;
	_diffuse[0] = 0.01;
	_diffuse[1] = 0.01;
	_diffuse[2] = 0.01;
	_specular[0] = 0.2;
	_specular[1] = 0.2;
	_specular[2] = 0.2;
	_shininess = .078125;
}



void Material::ToMagentaReflect()
{
	_ambiant[0] = 1.0;
	_ambiant[1] = 0.0;
	_ambiant[2] = 1.0;
	_diffuse[0] = 0.0;
	_diffuse[1] = 0.0;
	_diffuse[2] = 0.0;
	_specular[0] = 0.52;
	_specular[1] = 0.33;
	_specular[2] = 0.54;
	_shininess = 8.0;
}


void Material::ToBlackReflect()
{
	_ambiant[0] = 0.03;
	_ambiant[1] = 0.03;
	_ambiant[2] = 0.03;
	_diffuse[0] = 0.0;
	_diffuse[1] = 0.0;
	_diffuse[2] = 0.0;
	_specular[0] = 0.656777;
	_specular[1] = 0.837622;
	_specular[2] = 0.686014;
	_shininess = 0.6;
}


void Material::ToGreyReflect()
{
	_ambiant[0] = 0.2;
	_ambiant[1] = 0.2;
	_ambiant[2] = 0.2;
	_diffuse[0] = 0.13;
	_diffuse[1] = 0.13;
	_diffuse[2] = 0.13;
	_specular[0] = 0.8;
	_specular[1] = 0.8;
	_specular[2] = 0.8;
	_shininess = 8.0;
}


void Material::ToWhiteReflect()
{
	_ambiant[0] = 0.6;
	_ambiant[1] = 0.6;
	_ambiant[2] = 0.6;
	_diffuse[0] = 0.8;
	_diffuse[1] = 0.8;
	_diffuse[2] = 0.8;
	_specular[0] = 1.0;
	_specular[1] = 1.0;
	_specular[2] = 1.0;
	_shininess = 8.0;
}

void Material::ToRedReflect()
{
	_ambiant[0] = 0.5;
	_ambiant[1] = 0;
	_ambiant[2] = 0;
	_diffuse[0] = 0.35;
	_diffuse[1] = 0.00;
	_diffuse[2] = 0.00;
	_specular[0] = 1.0;
	_specular[1] = 1.0;
	_specular[2] = 1.0;
	_shininess = 8.0;
}

void Material::ToBlueDark()
{
	_ambiant[0] = 0;
	_ambiant[1] = 0;
	_ambiant[2] = 0.25;
	_diffuse[0] = 0.35;
	_diffuse[1] = 0.35;
	_diffuse[2] = 0.35;
	_specular[0] = 0.2;
	_specular[1] = 0.2;
	_specular[2] = 0.2;
	_shininess = 8.0;
}

void Material::ToCopper()
{
	_ambiant[0] = 0.19125;
	_ambiant[1] = 0.0735;
	_ambiant[2] = 0.0225;
	_diffuse[0] = 0.7038;
	_diffuse[1] = 0.27048;
	_diffuse[2] = 0.0828;
	_specular[0] = 0.256777;
	_specular[1] = 0.137622;
	_specular[2] = 0.086014;
	_shininess = 0.1;
}

void Material::ToGold()
{
	_ambiant[0] = 0.24725;
	_ambiant[1] = 0.1995;
	_ambiant[2] = 0.0745;
	_diffuse[0] = 0.75164;
	_diffuse[1] = 0.60648;
	_diffuse[2] = 0.22648;
	_specular[0] = 0.628281;
	_specular[1] = 0.555802;
	_specular[2] = 0.366065;
	_shininess = 0.4;
}


void Material::ToRuby()
{
	_ambiant[0] = 0.1745;
	_ambiant[1] = 0.01175;
	_ambiant[2] = 0.01175;
	_diffuse[0] = 0.61424;
	_diffuse[1] = 0.04136;
	_diffuse[2] = 0.04136;
	_specular[0] = 0.727811;
	_specular[1] = 0.626959;
	_specular[2] = 0.626959;
	_shininess = 0.6;
}


//vert pistache, utiliser pour paindre le oiseau
void Material::ToVertPistache()
{
	_ambiant[0] = 0.1745;
	_ambiant[1] = 0.01175;
	_ambiant[2] = 0.01175;
	_diffuse[0] = 0.72;
	_diffuse[1] = 0.83;
	_diffuse[2] = 0.06;
	_specular[0] = 0.727811;
	_specular[1] = 0.626959;
	_specular[2] = 0.626959;
	_shininess = 0.6;
}

//vert Orange, utiliser pour paindre le oiseau
void Material::ToOrange()
{
	_ambiant[0] = 0.1745;
	_ambiant[1] = 0.01175;
	_ambiant[2] = 0.01175;
	_diffuse[0] = 1.0;
	_diffuse[1] = 0.48;
	_diffuse[2] = 0.15;
	_specular[0] = 0.727811;
	_specular[1] = 0.626959;
	_specular[2] = 0.626959;
	_shininess = 0.6;
}

//vert Violet, utiliser pour paindre le oiseau
void Material::ToViolet()
{
	_ambiant[0] = 0.1745;
	_ambiant[1] = 0.01175;
	_ambiant[2] = 0.01175;
	_diffuse[0] = 0.67;
	_diffuse[1] = 0.83;
	_diffuse[2] = 0.91;
	_specular[0] = 0.727811;
	_specular[1] = 0.626959;
	_specular[2] = 0.626959;
	_shininess = 0.6;
}

//vert Marron foncer, utiliser pour paindre le oiseau
void Material::ToMarronDark()
{
	_ambiant[0] = 0.1745;
	_ambiant[1] = 0.01175;
	_ambiant[2] = 0.01175;
	_diffuse[0] = 0.68;
	_diffuse[1] = 0.28;
	_diffuse[2] = 0.08;
	_specular[0] = 0.727811;
	_specular[1] = 0.626959;
	_specular[2] = 0.626959;
	_shininess = 0.6;
}