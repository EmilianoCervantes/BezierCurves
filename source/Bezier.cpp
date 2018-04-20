#include "Bezier.h"

Bezier::Bezier(int d, Point* ctrl)
{
	degree = d;
	ctrlPoints = new Point[degree];
	for (int i = 0; i < degree+1; i++)
	{
		ctrlPoints[i].x = ctrl[i].x;
		ctrlPoints[i].y = ctrl[i].y;
		ctrlPoints[i].z = ctrl[i].z;
		ctrlPoints[i].r = ctrl[i].r;
		ctrlPoints[i].g = ctrl[i].g;
		ctrlPoints[i].b = ctrl[i].b;
		ctrlPoints[i].radius = ctrl[i].radius;
	}
	coefficients = new float[degree];
	//Inicializar coeficientes para usar después.
	for (int i = 0; i < degree; i++)
	{
		coefficients[i] = binomial(degree, i);
	}

	evalBezier(0.9f);
}

Point* Bezier::evalBezier(float t)
{
	Point* ps = new Point[1];
	ps[0].r = 0;
	ps[0].g = 0;
	ps[0].b = 1.0;
	for (int i = 0; i < degree; i++)
	{
		ps[0].x += coefficients[i] * powf(1.0f - t, degree - i) * powf(t, i) * ctrlPoints[i].x;
		ps[0].y += coefficients[i] * powf(1.0f - t, degree - i) * powf(t, i) * ctrlPoints[i].y;
		ps[0].z += coefficients[i] * powf(1.0f - t, degree - i) * powf(t, i) * ctrlPoints[i].z;
	}

	return ps;
}

int Bezier::factorial(int x)
{
	if (x == 0) return 1;
	else return x * factorial(x - 1);
}

float Bezier::binomial(int n, int i)
{
	return (float)factorial(n) / (factorial(i)*factorial(n - i));
}

void Bezier::draw()
{
	glPushMatrix();
	{
		for (int i = 0; i < degree; i++)
		{
			ctrlPoints[i].draw();
		}
	}
	glPopMatrix();
}


Bezier::~Bezier()
{
}
