#pragma once
#ifdef __APPLE__
// See: http://lnx.cx/docs/opengl-in-xcode/
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif
#include <stdio.h>
#include <math.h>
class Point
{
public:
	Point();
	Point(float _x, float _y, float _z, float _r, float _g, float _b, float _radius);
	~Point();

	void draw();

	float x, y, z;
	float r, g, b;
	float radius;
};

