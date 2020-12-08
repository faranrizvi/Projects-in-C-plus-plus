//
//  Triangle.cpp
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student: Write the implementation of the class Rectangle here

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

#include "Shape.h"
#include "Triangle.h"

Triangle::Triangle (string n, float xcent, float ycent, float x_1, float y_1, float x_2, float y_2, float x_3, float y_3):Shape(n, xcent, ycent){
    x1 = x_1;
    y1 = y_1;
    x2 = x_2;
    y2 = y_2;
    x3 = x_3;
    y3 = y_3;
}

Triangle::~Triangle(){
    
}
float Triangle::getx_1() const{
    return(x1);
}

float Triangle::gety_1() const{
    return(y1);
}

float Triangle::getx_2() const{
    return(x2);
}

float Triangle::gety_2() const{
    return(y2);
}

float Triangle::getx_3() const{
    return(x3);
}

float Triangle::gety_3() const{
    return(y3);
}

void Triangle::setx_1(float x_1){
    x1 = x_1;
}

void Triangle::sety_1(float y_1){
    y1 = y_1;
}

void Triangle::setx_2(float x_2){
    x2 = x_2;
}

void Triangle::sety_2(float y_2){
    y2 = y_2;
}

void Triangle::setx_3(float x_3){
    x3 = x_3;
}

void Triangle::sety_3(float y_3){
    y3 = y_3;
}

void Triangle::draw() const{
    cout << std::fixed;
    cout << std::setprecision(2);
    
    // Print the information
    cout << "triangle: " << name << " "
         << Xcentre() << " " << Ycentre()
         << " " << x1 << " " << y1 
         << " " << x2 << " " << y2
         << " " << x3 << " " << y3
         << " " << computeArea()
         << endl;
}

float Triangle::computeArea() const{
    return abs(((x1*(y2 - y3)) + (x2*(y3 - y1)) + (x3*(y1 - y2)))/2);
}

Shape* Triangle::clone() const{
    return(new Triangle(*this));
}
float Triangle::Xcentre() const{
    return ((x1 + x2 + x3) / 3);
}

float Triangle::Ycentre() const{
    return ((y1 + y2 + y3) / 3);
}