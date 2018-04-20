#pragma once

#include <math.h>
#include "Point.h"
class Bezier
{
public:
	Bezier(int n, Point* ctrl);
	~Bezier();

	int degree;
	float* coefficients;
	Point* ctrlPoints;

	void draw();
	int factorial(int x);
	float binomial(int n, int i);
	Point* evalBezier(float t);
};

