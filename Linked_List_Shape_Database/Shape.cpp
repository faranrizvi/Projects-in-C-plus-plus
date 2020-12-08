//
//  Shape.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the Shape class below

#include <iostream>
#include "Shape.h"
#include <string>

using namespace std;

Shape::Shape(string n, string t, int x_loc, int y_loc, int x_sz, int y_sz){
    name = n;
    type = t; 
    x_location = x_loc;
    y_location = y_loc;
    x_size = x_sz;
    y_size = y_sz;
}

string Shape::getType(){
    return(type);
}

string Shape::getName(){
    return(name);
}

int Shape::getXlocation(){
    return(x_location);
}

int Shape::getYlocation(){
    return(y_location);
}

int Shape::getXsize(){
    return(x_size);
}

int Shape::getYsize(){
    return(y_size);
}

void Shape::setType(string t){
    type  = t;
}

void Shape::setName(string n){
    name = n;
}

void Shape::setXlocation(int x_loc){
    x_location = x_loc;
}

void Shape::setYlocation(int y_loc){
    y_location = y_loc;
}

void Shape::setXsize(int x_sz){
    x_size = x_sz;
}

void Shape::setYsize(int y_sz){
    y_size = y_sz;
}

void Shape::draw(){
    cout << name << ": " << type << " " << x_location << " " << y_location << " " << x_size << " " << y_size << endl;
}
