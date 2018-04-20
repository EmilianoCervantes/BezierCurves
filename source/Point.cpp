#include "Point.h"

Point::Point()
{
	x = y = z = 0.0f;
	r = g = b = 1.0f;
	radius = 1.0f;
}

Point::Point(float _x, float _y, float _z, float _r, float _g, float _b, float _radius)
{
	x = _x;
	y = _y;
	z = _z;
	r = _r;
	g = _g;
	b = _b;
	radius = _radius;
}


Point::~Point()
{
}

void Point::draw()
{
	glPushMatrix();
	{
		glTranslatef(x, y, z);
		glColor3f(r, g, b);
		glutSolidSphere(radius, 10, 10);
	}
	glPopMatrix();
}
