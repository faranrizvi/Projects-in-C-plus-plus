//
//  ShapeNode.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the ShapeNode class below

#include <iostream>
#include "ShapeNode.h"

using namespace std;

ShapeNode::ShapeNode(){
    myShape = nullptr;
    next = nullptr;
}

ShapeNode::~ShapeNode(){
    delete myShape;
}

Shape* ShapeNode::getShape() const{
    return(myShape);
}

void ShapeNode::setShape(Shape* ptr){
    myShape = ptr;
}

ShapeNode* ShapeNode::getNext() const{
    return(next);
}

void ShapeNode::setNext(ShapeNode* ptr){
    next = ptr;
}

void ShapeNode::print() const{
    cout << myShape << endl;
}

