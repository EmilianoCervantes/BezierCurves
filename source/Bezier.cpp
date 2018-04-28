//
//  Bezier.cpp
//  Bezier
//
//  Created by Irvin Mundo on 20/04/18.
//  Copyright © 2018 MundoSystems. All rights reserved.
//

#include "Bezier.hpp"

Bezier::Bezier(int d, Point* ctrl){
    degree = d;
    ctrlPoints = new Point[degree];
    int i = 0;
    for(i = 0; i < degree; i++){
        ctrlPoints[i].x = ctrl[i].x;
        ctrlPoints[i].y = ctrl[i].y;
        ctrlPoints[i].z = ctrl[i].z;
        ctrlPoints[i].r = ctrl[i].r;
        ctrlPoints[i].g = ctrl[i].g;
        ctrlPoints[i].b = ctrl[i].b;
        ctrlPoints[i].radius = ctrl[i].radius;
    }
    coefficients = new float[degree];
    
    //INitialize yout coefficients here, for later use
    for(i = 0; i < degree; i++){
        coefficients[i] = binomial(d-1,i);
    }
    
}

void Bezier::draw(){
    for(int i = 0; i < degree; i++){
        ctrlPoints[i].draw();
    }
}

Point* Bezier::evalBezier(float t){
    Point* point = new Point();
    for(int  i = 0; i < degree; i++){
        point->x += coefficients[i]*powf(1.0f - t, degree-i-1)*powf(t,i)*ctrlPoints[i].x;
        point->y += coefficients[i]*powf(1.0f - t, degree-i-1)*powf(t,i)*ctrlPoints[i].y;
        point->z += coefficients[i]*powf(1.0f - t, degree-i-1)*powf(t,i)*ctrlPoints[i].z;
    }
    return point;
}

int Bezier::factorial(int x){
    if(x == 0) return 1;
    else return x * factorial(x-1);
}

float Bezier::binomial(int n, int i){
    return (float)factorial(n)/(factorial(i)*factorial(n-1));
}
