//
//  Rectangle.cpp
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student: Write the implementation of the class here

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Shape.h"
#include "Rectangle.h"

Rectangle::Rectangle (string n, float xcent, float ycent, float w, float h):Shape(n, xcent, ycent){
    width = w;
    height = h;
}

Rectangle::~Rectangle(){

}

float Rectangle::getWidth() const{
    return(width);
}

float Rectangle::getHeight() const{
    return(height);
}

void Rectangle::setWidth(float w){
    width = w;
}

void Rectangle::setHeight(float h){
    height = h;
}

void Rectangle::draw() const{
    cout << std::fixed;
    cout << std::setprecision(2);
    
    // Print the information
    cout << "rectangle: " << name << " "
         << x_centre << " " << y_centre
         << " " << width << " " << height
         << " " << computeArea()
         << endl;
}

float Rectangle::computeArea() const{
    return(width*height);
}

Shape* Rectangle::clone() const{
    return (new Rectangle(*this));
}