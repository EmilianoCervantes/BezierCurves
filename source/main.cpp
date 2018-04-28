//
//  main.cpp
//  Bezier
//
//  Created by Irvin Mundo on 20/04/18.
//  Copyright © 2018 MundoSystems. All rights reserved.
//

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
#include "Bezier.hpp"
#include "Point.hpp"
Bezier* bezier;
Point* points;
Point* puntossiguientes;

float contador;

void init(){
    points = new Point[6];
    points[0].x = 0.-1.5;
    points[0].y = 0.-2;
    points[0].z = 0.0;
    points[1].x = 0.-2.5;
    points[1].y = 0.-1;
    points[1].z = 0.0;
    points[2].x = 0.-1;
    points[2].y = 0.2;
    points[2].z = 0.0;
    points[3].x = 0.9;
    points[3].y = 0.2;
    points[3].z = 0.0;
    points[4].x = 1.5;
    points[4].y = 0.-1;
    points[4].z = 0.0;
    points[5].x = 1;
    points[5].y = 0.-2;
    points[5].z = 0.0;
    
    for(int i = 0; i < 6; i++){
        points[i].r = 1;
        points[i].g = 0;
        points[i].b = 0;
        points[i].radius = 0.1;
    }
    bezier = new Bezier(6, points);
    contador = 0;
    
    glEnable(GL_DEPTH_TEST);            // Enable check for close and far objects.
    glClearColor(0.3, 0.3, 0.3, 1.0);    // Clear the color state. Cambiar el color sw fondo
    glMatrixMode(GL_MODELVIEW);            // Go to 3D mode.
    glLoadIdentity();
    
}

void show(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                // Clear color and depth buffers. Borramos todo de los bufers
    Point* nuevospuntos = bezier->evalBezier(contador);
    bezier->draw();
    glPushMatrix();{
        glTranslatef(nuevospuntos->x,nuevospuntos->y,nuevospuntos->z);
        glColor3f(0.5,0.7,0.2);
        glutSolidSphere(0.1, 20, 20);
    }glPopMatrix();
    for(int i = 0; i < 15; i++){
        glPushMatrix();{
            glColor3f(1,0,0);
            puntossiguientes = bezier->evalBezier(i/15);
            puntossiguientes -> r = 1;
            puntossiguientes -> g = 1;
            puntossiguientes -> b = 0;
            glTranslatef(puntossiguientes->x,puntossiguientes->y,puntossiguientes->z);
            puntossiguientes->draw();
            glutSolidSphere(0.015, 20, 20);
        }glPopMatrix();
    }
    
    
    glutSwapBuffers();
}

void idle(){
    //printf("%f.3f -- %-3f\n", offsetX, offsetY);
    contador += 0.01;
    if(contador >= 1){
        contador = 0;
    }
    glutPostRedisplay();                                            // Display again. Ultima linea de idle
}

void reshape(int x, int y)                                            // Called when the window geometry changes.
{
    glMatrixMode(GL_PROJECTION);                                    // Go to 2D mode.
    glLoadIdentity();                                                // Reset the 2D matrix.
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 50.0);        // Configure the camera lens aperture.
    glMatrixMode(GL_MODELVIEW);                                        // Go to 3D mode.
    glLoadIdentity();                                                // Reset the 3D matrix.
    glViewport(0, 0, x, y);                                            // Configure the camera frame dimensions.
    gluLookAt(0.0, 0.0, 10.0,                                        // Where the camera is. Posicion de la camara
              0.0, 0.0, 0.0,                                                // To where the camera points at.
              0.0, 1.0, 0.0);                                                // "UP" vector.
    show();
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);                                            // Init GLUT with command line parameters. Iniciamos el GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);        // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG DEMO");
    
    init();
    glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
    glutDisplayFunc(show);                                        // Display CALLBACK function.
    glutIdleFunc(idle);                                                // Idle CALLBACK function.
    glutMainLoop();                                                    // Begin graphics program.
    return 0;                                                        // ANSI C requires a return value.
}
