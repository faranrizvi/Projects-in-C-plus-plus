//
//  ShapeList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the ShapeList class below

#include <iostream>
#include "ShapeList.h"
#include "ShapeNode.h"
#include "Shape.h"

using namespace std;

ShapeList::ShapeList(){
    head = nullptr;
}

ShapeList::~ShapeList(){
    if(head == nullptr){ 
        return;
    }
    while(head != nullptr){
        ShapeNode *tptr = head;
        ShapeNode *pptr = nullptr;
        
        while(tptr != nullptr){
            pptr = tptr;
            tptr = tptr -> getNext();
        }
        delete tptr;
        pptr = nullptr;
        return;
    }
}

ShapeNode* ShapeList::getHead() const{
    return(head);
}

void ShapeList::setHead(ShapeNode* ptr){
    head = ptr;
}

ShapeNode* ShapeList::find(string name) const{
    ShapeNode *tptr = head;
    
    while(tptr != nullptr){
        if(tptr->getShape()-> getName() == name) break;
        tptr = tptr ->getNext();
    }
    return tptr;
}

void ShapeList::insert(ShapeNode* s){
    ShapeNode *tptr = head;
    
    if(head == nullptr){
        head = s;
        s -> setNext(nullptr);
    }
    else{
        while(tptr->getNext() != nullptr){
            tptr = tptr -> getNext();
        }
        tptr -> setNext(s);
        s -> setNext(nullptr);
    }
}

ShapeNode* ShapeList::remove(string name){
    if(head == nullptr) return nullptr;
    ShapeNode *tptr = head;
    ShapeNode *pptr = nullptr;
    
    while(tptr != nullptr){
        if(tptr -> getShape() -> getName() == name) break;
        pptr = tptr;
        tptr = tptr -> getNext();
    }
    if(tptr == nullptr) return nullptr;
    if(tptr == head){
        head = head -> getNext();
        delete tptr;
        return nullptr;
    }
    pptr -> setNext(tptr -> getNext());
    return tptr;
}

void ShapeList::print() const{
    ShapeNode* tptr = head;
    
    while(tptr != nullptr){
        tptr ->getShape()->draw();
        tptr = tptr ->getNext();
    }   
}

            
            
        
 










