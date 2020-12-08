#include <iostream>
using namespace std;
#include <sstream>

#include "Shape.h"
#include "ShapesDB.h"

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

#define MAX_SHAPES 1000
#define MAX_SHAPE_TYPES 10

// Create a database instance; making it global to simplify student code
ShapesDB sdb(MAX_SHAPES,MAX_SHAPE_TYPES);

// ECE244 Student: add your parser function prototypes here
Shape* parseCircleCommand(stringstream& line);
Shape* parseTriangleCommand(stringstream& line);
Shape* parseRectangleCommand(stringstream& line);

int main () {

    // Register the command parser call back functions
    sdb.registerShapeType("circle", &parseCircleCommand);
    sdb.registerShapeType("triangle", &parseTriangleCommand);
    sdb.registerShapeType("rectangle", &parseRectangleCommand);
    
    // Invoke the parser of the DB
    // No new commands should be registered after this
    sdb.parseCommands();
    
    // Done
    return (0);
}

Shape* parseCircleCommand(stringstream& line) {
    string name;
    float xcent;
    float ycent;
    float radius;
    line >> name >> xcent >> ycent >> radius;
    
    // Do a simple error check
    if (line.fail()) {
        cout << "Error: invalid input" << endl;
        return nullptr;
    }
    
    // Check to see if name is a reserved word
    if (sdb.isReserved(name)) {
        cout << "Error: " << name << " is a reserved word" << endl;
        return nullptr;
    }
    
    // Check if a shape with this name already exists
    if (sdb.shapeExists(name)) {
        cout << "Error: a shape with the name " << name << " already exists" << endl;
        return nullptr;
    }

    // Create the shape object and return a pointer to it
    Shape* myShape = (Shape*) new Circle(name, xcent, ycent, radius);
    cout << "created circle" << endl;
    return myShape;
}

Shape* parseTriangleCommand(stringstream& line){
    string name;
    float x1, y1, x2, y2, x3, y3;
    line >> name >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    // Do a simple error check
    if (line.fail()) {
        cout << "Error: invalid input" << endl;
        return nullptr;
    }
    
    // Check to see if name is a reserved word
    if (sdb.isReserved(name)) {
        cout << "Error: " << name << " is a reserved word" << endl;
        return nullptr;
    }
    
    // Check if a shape with this name already exists
    if (sdb.shapeExists(name)) {
        cout << "Error: a shape with the name " << name << " already exists" << endl;
        return nullptr;
    }

    // Create the shape object and return a pointer to it
    Shape* myShape = (Shape*) new Triangle(name, 0, 0, x1, y1, x2, y2, x3, y3);
    cout << "created triangle" << endl;
    return myShape;
}

Shape* parseRectangleCommand(stringstream& line){
    string name;
    float xcent, ycent, width, height;
    line >> name >> xcent >> ycent >> width >> height;
    
    // Do a simple error check
    if (line.fail()) {
        cout << "Error: invalid input" << endl;
        return nullptr;
    }
    
    // Check to see if name is a reserved word
    if (sdb.isReserved(name)) {
        cout << "Error: " << name << " is a reserved word" << endl;
        return nullptr;
    }
    
    // Check if a shape with this name already exists
    if (sdb.shapeExists(name)) {
        cout << "Error: a shape with the name " << name << " already exists" << endl;
        return nullptr;
    }

    // Create the shape object and return a pointer to it
    Shape* myShape = (Shape*) new Rectangle(name, xcent, ycent, width, height);
    cout << "created rectangle" << endl;
    return myShape;
}
