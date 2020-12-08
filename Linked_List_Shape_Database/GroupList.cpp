//
//  GroupList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the GroupList class below

#include <iostream>
#include "GroupNode.h"
#include "Shape.h"
#include "GroupList.h"


using namespace std;

GroupList::GroupList(){
    head = nullptr;
}
            
GroupList::~GroupList(){
    if(head == nullptr) return;
    
    while(head != nullptr){
        GroupNode *tptr = head;
        GroupNode *pptr = nullptr;
        
        while(tptr != nullptr){
            pptr = tptr;
            tptr = tptr ->getNext();
        }
        delete tptr;
        pptr = nullptr;
        return;
    }
    
}

GroupNode* GroupList::getHead() const{
    return(head);
}

void GroupList::setHead(GroupNode* ptr){
    head = ptr;
}

void GroupList::insert(GroupNode* s){
    GroupNode *tptr = head;
    
    if(head == nullptr){
        head = s;
        s ->setNext(nullptr);
    }
    else{
        while(tptr->getNext() != nullptr){
            tptr = tptr -> getNext();
        }
        tptr->setNext(s); 
        s ->setNext(nullptr);
    }
}

GroupNode* GroupList::remove(string name){
    if(head == nullptr) return nullptr;
    
    GroupNode *tptr = head;
    GroupNode *pptr = nullptr;
    
    while(tptr != nullptr){
        if(tptr ->getName() == name) break;
        pptr = tptr;
        tptr = tptr ->getNext();
    }
    if(tptr == nullptr) return nullptr;
    if(tptr == head){
        head = head ->getNext();
        delete tptr;
        return nullptr;
    }
    pptr->setNext(tptr ->getNext());
    return tptr;
}

void GroupList::print() const{
    GroupNode *tptr = head;
    
    while(tptr != nullptr){
        cout << tptr->getName() << ":" << endl;
        tptr = tptr ->getNext();
    }
}





