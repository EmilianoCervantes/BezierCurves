//
//  Bezier.hpp
//  Bezier
//
//  Created by Irvin Mundo on 20/04/18.
//  Copyright © 2018 MundoSystems. All rights reserved.
//

#ifndef Bezier_hpp
#define Bezier_hpp

#include <math.h>
#include "Point.hpp"
class Bezier{
public:
    Bezier(int n, Point* ctrl);
    ~Bezier();
    
    int degree;
    float * coefficients;
    Point* ctrlPoints;
    
    void draw();
    int factorial(int x);
    float binomial(int n, int i);
    Point* evalBezier(float t);
};


#endif /* Point_hpp */

