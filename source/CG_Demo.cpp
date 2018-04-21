/*
Computer Graphics. TC3022

Basic culling example.
Displays culled planes.
*/

#pragma once
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif
#include <stdio.h>
#include <math.h>

using namespace std;
#include "Bezier.h"
#include "Point.h"
Bezier* bezier;
Point* puntos;
Point* curva = new Point[20];

void renderScene(void)
{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Dibujar puntos de control
	bezier->draw();
	//Dibujar curva
	for (int i = 0; i < 20; i++)
	{
		curva[i].draw();
	}
	glutSwapBuffers();
}

// This function does any needed initialization on the rendering context. 
void init()
{
	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	int n = 5;
	float t = 0.0;
	//Porque el degree son las conexiones entre puntos
	//Si tienes un degree 1 significa que tienes una conexión entre dos puntos
	//Por eso es n+1 en Point[] y en el for
	puntos = new Point[n+1];
	for (int i; i < n+1; i++)
	{
		puntos[i].x = 1.0*i;
		puntos[i].y = 1.0*i;
		puntos[i].z = 1.0*i;
		puntos[i].r = 1.0;
		puntos[i].g = 0.0;
		puntos[i].b = 0.0;
		puntos[i].radius = 2.0f;
	}
	bezier = new Bezier(n, puntos);
	//bezier->evalBezier(t); regresa un punto
	//Aquí generamos los n puntos azules de la curva
	for (int i = 0; i < 20;i++)
	{
		t += 0.05;
		Point* p = bezier->evalBezier(t);
		curva[i].x = p->x;
		curva[i].y = p->y;
		curva[i].z = p->z;
	}
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);  // CULL: not draw it.
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Bezier Curve");
	//glutReshapeFunc(changeSize);
	//glutSpecialFunc(specialKeys);
	glutDisplayFunc(renderScene);
	init();
	glutMainLoop();

	return 0;
}