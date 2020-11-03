//
//  parser.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018-2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"

// This is the shape array, to be dynamically allocated
Shape** shapesArray;

// The number of shapes in the database, to be incremented
// everytime a shape is successfully created
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

void stringErrorCheck(stringstream& sin, string& var, bool checktype);
void intErrorCheck(stringstream& sin, int& var);
void errorInput(const string& errorMessage, int priorityOfError);
void maxShapesCommand(stringstream& sin);
void createCommand(stringstream& sin);
void moveCommand(stringstream& sin);
void rotateCommand(stringstream& sin);
void drawCommand(stringstream& sin);
void deleteCommand(stringstream& sin);
void errorReset();
bool existingInput(stringstream& sin);
bool errorExists();
int shapeIndex(const string & index);
string error;
int errorPriority = 0;

int main() {

    string line;
    string command;

    cout << "> ";
    getline(cin, line);   // Get a line from standard input

    while (!cin.eof()) {
        stringstream lineStream (line);
        
        errorReset();
        
        lineStream >> command;

        if (command == "maxShapes") {
            maxShapesCommand(lineStream);
        }

        else if (command == "create") {
            createCommand(lineStream);
        }

        else if (command == "move") {
            moveCommand(lineStream);
        }

        else if (command == "rotate") {
            rotateCommand(lineStream);
        }

        else if (command == "draw") {
            drawCommand(lineStream);
        }

        else if (command == "delete") {
            deleteCommand(lineStream);
        }

        else { 
            errorInput("invalid command", 1);
        }
        
        
        if (errorExists()) {
            cout << "Error: " << error << endl;
        }
        
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);   // Get the command line

    } 

    
    if (shapesArray != nullptr) {
        for (int i=0; i < max_shapes; i++) {
            if (shapesArray[i] != nullptr) {
                delete shapesArray[i];
                shapesArray[i] = nullptr;
            }
        }
        delete [] shapesArray;
    }
    return 0;
}

void maxShapesCommand(stringstream& sin) {
    sin >> max_shapes;
    shapesArray = new Shape*[max_shapes];
    cout << "New database: max shapes is " << max_shapes << endl;
    
    for (int i = 0; i < max_shapes; i++) {
        shapesArray[i] = nullptr;
    }
}
void createCommand(stringstream& sin) {
    string name, type;
    int x_loc, y_loc, x_size, y_size, shapePlace;


    stringErrorCheck(sin, name, false);


    shapePlace = shapeIndex(name);
    if (shapePlace >= 0) {
        errorInput( "shape " + name + " exists", 4); 
    }

    
    stringErrorCheck(sin, type, true);
    intErrorCheck(sin, x_loc);
    intErrorCheck(sin, y_loc);
    intErrorCheck(sin, x_size);
    intErrorCheck(sin, y_size);
    
    if(type == "circle"){
        if(x_size != y_size){
            errorInput("invalid value", 7);
        }
    }

    if (!errorExists() && existingInput(sin))
        errorInput("too many arguments", 8);
    if (!errorExists() && shapeCount >= max_shapes)
        errorInput("shape array is full", 10);

    if (!errorExists()) {
        shapesArray[shapeCount++] = new Shape(name, type, x_loc, x_size, y_loc, y_size);
        cout << "Created ";
        shapesArray[shapeCount-1]->draw();
    }
}

void moveCommand(stringstream& sin) {
    string name;
    int x_loc, y_loc, shapePlace;

    stringErrorCheck(sin, name, false);

    shapePlace = shapeIndex(name);
    
    if (!name.empty() && shapePlace < 0) {
        errorInput("shape " + name + " not found", 5); 
    }
    
    intErrorCheck(sin, x_loc);
    intErrorCheck(sin, y_loc);

    
    if (!errorExists() && existingInput(sin))
        errorInput("too many arguments", 8);

    
    if (!errorExists()) {
        
        shapesArray[shapePlace]->setXlocation(x_loc);
        shapesArray[shapePlace]->setYlocation(y_loc);
        cout << "Moved " << name << " to "
             << x_loc << " " << y_loc << endl;
    }
}

void rotateCommand(stringstream& sin) {
    string name;
    int angle, shapePlace;

    stringErrorCheck(sin, name, false);

    shapePlace = shapeIndex(name);
    
    if (!name.empty() && shapePlace < 0)
        errorInput("shape " + name + " not found", 5); 

    intErrorCheck(sin, angle);
    
    if (angle < 0 || angle > 360)
        
        errorInput("invalid value", 7);

    
    if (!errorExists() && existingInput(sin))
        errorInput("too many arguments", 8);

    
    if (!errorExists()) {
        
        shapesArray[shapePlace]->setRotate(angle);
        cout << "Rotated " << name << " by " << angle << " degrees" << endl;
    }
} 

void drawCommand(stringstream& sin) {
    string arg;
    int shapePlace;

    
    stringErrorCheck(sin, arg, false);

    if (error == "invalid shape name" && arg == "all")
        errorReset(); 

    shapePlace = shapeIndex(arg);
    if (!arg.empty() && arg != "all" && shapePlace < 0)
        errorInput("shape " + arg + " not found", 5); 

    if (!errorExists() && existingInput(sin))
        errorInput("too many arguments", 8);

    
    if (!errorExists()) {
        if (arg == "all") {
            cout << "Drew all shapes" << endl;
            for (int i = 0; i < max_shapes; i++) {
                if (shapesArray[i] == nullptr) { 
                    continue; 
                }
                shapesArray[i]->draw();
            }
        } else {
            cout << "Drew ";
            shapesArray[shapePlace]->draw();
        }
    }
} 

void deleteCommand(stringstream& sin) {
    string arg;
    int shapePlace;
    
    stringErrorCheck(sin, arg, false);

    if (error == "invalid shape name" && arg == "all")
        errorReset(); 

    shapePlace = shapeIndex(arg);
    if (!arg.empty() && arg != "all" && shapePlace < 0)
        errorInput("shape " + arg + " not found", 5); 

    if (!errorExists() && existingInput(sin))
        errorInput("too many arguments", 8);


    if (!errorExists()) {
        if (arg == "all") {
            
            cout << "Deleted: all shapes" << endl;
            for (int i = 0; i < max_shapes; i++) {
                if (shapesArray[i] == nullptr){
                    continue; 
                }
                delete shapesArray[i];
                shapesArray[i] = nullptr;
                
            }
            shapeCount = 0;
        } 
        else {
            cout << "Deleted shape " << shapesArray[shapePlace]->getName() << endl;
            delete shapesArray[shapePlace];
            shapesArray[shapePlace] = nullptr;
            shapeCount--;
            
        }
    }
}


void intErrorCheck(stringstream& sin, int& var) {
    if (errorExists()) {
        return;
    }
    
    if (!existingInput(sin)) {
        errorInput("too few arguments", 9);
        return;
    }

    sin >> var;

    
    char l = (char) sin.peek();
    bool ws = l == ' ' || l == '\n' || l == '\r' ||
                        l == '\t' || l == '\f' || l == '\v';

    if (!sin.eof() && (sin.fail() || !ws)) {
        errorInput("invalid argument", 2);
    }


    if (var < 0) {
        errorInput("invalid value", 7);
    }
}

void stringErrorCheck(stringstream& sin, string& var, bool checktype){

    if (errorExists()) {
        return;
    }

    if (!existingInput(sin)) {
        errorInput("too few arguments", 9);
        return;
    }

    sin >> var;
    
    if (checktype) {
        
        bool typeOfShape = false;
        for (int i = 0; i < NUM_TYPES; i++) {
            if (var == shapeTypesList[i]) {
                typeOfShape = true;
                break;
            }
        }
        if (!typeOfShape) {
            errorInput("invalid shape type", 6);
            return;
        }

    } 
    else {
        int num = NUM_KEYWORDS > NUM_TYPES ? NUM_KEYWORDS : NUM_TYPES;
        for (int i = 0; i < num; i++) {
            if ((i < NUM_KEYWORDS && var == keyWordsList[i]) || (i < NUM_TYPES && var == shapeTypesList[i])) {
                errorInput("invalid shape name", 3);
                return;
            }
        }
    }
}


void errorInput(const string& erMes, int pr) {
    if (errorPriority <= 0 || pr < errorPriority) {
        error = erMes;
        if (pr > 0) {
            errorPriority = pr;
        }
    }
}


void errorReset() {
    errorPriority = 0;
    error = "";
}


bool existingInput(stringstream& sin) {
    sin >> std::ws; 
    return sin.peek() != EOF;
}

int shapeIndex(const string& index) {
    if (index == "all") {
        return -1;
    }
    
    for (int i = 0; i < max_shapes; i++) {
        if (shapesArray[i] != nullptr && shapesArray[i]->getName() == index) {
            return i;
        }
    }
    return -1;
}

bool errorExists() {
    return !error.empty();
}






