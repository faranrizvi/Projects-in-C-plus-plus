//
//  Triangle.h
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#ifndef Triangle_h
#define Triangle_h

#include <iostream>
#include <string>
#include "Shape.h"
using namespace std;

class Triangle : Shape{
private:
    float x1, y1, x2, y2, x3, y3;
public:
    Triangle(string n, float xcent, float ycent, float x_1, float y_1, float x_2, float y_2, float x_3, float y_3);
    virtual ~Triangle();
    
    float getx_1() const;
    float gety_1() const;
    float getx_2() const;
    float gety_2() const;
    float getx_3() const;
    float gety_3() const;
    
    void setx_1(float x_1);
    void sety_1(float y_1);
    void setx_2(float x_2);
    void sety_2(float y_2);
    void setx_3(float x_3);
    void sety_3(float y_3);
    
    virtual void draw() const;
    
    virtual float computeArea() const;
    
    virtual Shape* clone() const;
    
    float Xcentre() const;
    float Ycentre() const;
};
#endif /* Triangle_h */
