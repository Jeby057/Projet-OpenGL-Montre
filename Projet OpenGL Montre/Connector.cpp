#include "Connector.h"


Connector::Connector(float base, float height):_base(base), _height(height)
{
}


Connector::~Connector(void)
{
}

void Connector::BuildAndDisplay()
{
	Material mat = Material(0.6);
	mat.ToMagentaReflect();
	mat.Enable();
	glutSolidCone(_base, _height, 50, 50);
	mat.Disable();
}
