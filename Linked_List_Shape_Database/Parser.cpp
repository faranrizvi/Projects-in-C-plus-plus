#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"
#include "ShapeNode.h"
#include "ShapeList.h"
#include "GroupList.h"
#include "GroupNode.h"

// This is a pointer to the groups list
// The list itseld must be allocated
GroupList* gList;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here
void errorInput(const string& errorMessage, int priorityOfError);
void shapeCommand(stringstream& sin);
void groupCommand(stringstream& sin);
void drawCommand(stringstream& sin);
void moveCommand(stringstream& sin);
void deleteCommand(stringstream& sin);
int findShape(string arg);
int findGroup(string arg);
int findFuncForDelete(string arg);
void nameErrorCheck(stringstream& sin, string& var);
void errorReset();
bool errorExists();

string error;
int errorPriority = 0;

int main() {
    // Create the groups list
    
    gList = new GroupList();
    
    // Create the pool group and add it to the group list
    GroupNode* poolGroup = new GroupNode(keyWordsList[NUM_KEYWORDS-1]);
    gList->insert(poolGroup);
    
    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream (line);
        
        errorReset();
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        
        if (command == "shape") {
            shapeCommand(lineStream);
        }

        else if (command == "group") {
            groupCommand(lineStream);
        }

        else if (command == "draw") {
            drawCommand(lineStream);
        }

        else if (command == "move") {
            moveCommand(lineStream);
        }

        else if (command == "delete") {
            deleteCommand(lineStream);
        }
        
        if(errorExists()){
            cout << "error: " << error << endl;
        }
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    return 0;
}

void shapeCommand(stringstream& sin){
    string name, type;
    int x_loc, y_loc, x_size, y_size, shapeIndex;
    GroupNode* ttptr = gList->getHead();
    
    nameErrorCheck(sin, name);
    
    while(ttptr != nullptr){
        if(ttptr->getName() == name){
            errorInput("name " + name + " exists", 2);
        }
        ttptr = ttptr->getNext();
    }
    
    //findshape function
    shapeIndex = findShape(name);
    if(shapeIndex == 1){
        errorInput("name " + name + " exists", 2);
    }
    
    sin >> type >> x_loc >> y_loc >> x_size >> y_size;
    
    
    if(!errorExists()){
        ShapeNode* sNode = new ShapeNode();
        gList ->getHead()->getShapeList() ->insert(sNode);
        Shape* newShape = new Shape(name, type, x_loc, y_loc, x_size, y_size);
        sNode -> setShape(newShape);
        cout << name << ": " << type << " " << x_loc << " " << y_loc << " " << x_size << " " << y_size << endl; 
    }
}

void groupCommand(stringstream& sin){
    string name;
    int shapeIndex;
    GroupNode* tptr = gList->getHead();
    ShapeNode* rptr;
    
    nameErrorCheck(sin, name);
    
    if(tptr != nullptr){
            rptr =  tptr->getShapeList()->getHead();
    }
    
    while(tptr != nullptr){
        while(rptr != nullptr){
            if(rptr->getShape()->getName() == name){
                errorInput("name " + name + " exists", 2);
            }
            rptr = rptr->getNext();
        }
        tptr = tptr->getNext();
        if(tptr != nullptr){
            rptr =  tptr->getShapeList()->getHead();
        }
    }
    
    
    shapeIndex = findGroup(name);
    if(shapeIndex == 1){
        errorInput("name " + name + " exists", 2);
    }
    
    if(!errorExists()){
        GroupNode* newGroup = new GroupNode(name);
        gList ->insert(newGroup);
        cout << name << ": " << "group" << endl;
    }
    
}

void drawCommand(stringstream& sin){
    cout << "drawing: " << endl;
    GroupNode *tptr = gList->getHead();
    
    while(tptr != nullptr){
        tptr->print();
        tptr->getShapeList()->print();
        tptr = tptr->getNext();
    }
}

void moveCommand(stringstream& sin){
    string name, group;
    int shapeIndex;
    
    sin >> name;
    
    shapeIndex = findShape(name);
    
    if(shapeIndex == -1){
        errorInput("shape " + name + " not found", 3);
    }
    sin >> group;
   
    
    shapeIndex = findGroup(group);
    
    if(shapeIndex == -1){
        errorInput("group " + group + " not found", 4);
    }
    
    if(!errorExists()){
        string name1, type;
        int x_loc, y_loc, x_size, y_size;
        GroupNode *tptr = gList->getHead();
        ShapeNode *rptr;
        GroupNode* gptr = gList->getHead();
        
        if(tptr != nullptr){
            rptr =  tptr->getShapeList()->getHead();
        }
        while(tptr != nullptr){
            while(rptr != nullptr){
                if(rptr->getShape()->getName() == name){
                    name1 = rptr->getShape()->getName();
                    type = rptr->getShape()->getType();
                    x_loc = rptr->getShape()->getXlocation();
                    y_loc = rptr->getShape()->getYlocation();
                    x_size = rptr->getShape()->getXsize();
                    y_size = rptr->getShape()->getYsize();
                    
                    ShapeNode* deleteptr = tptr->getShapeList()->remove(name);
                
                    delete deleteptr;
                    break;
                }
                rptr = rptr->getNext();
            }
            tptr = tptr->getNext();
            if(tptr != nullptr){
                rptr =  tptr->getShapeList()->getHead();
            }
        }
        while(gptr != nullptr){
            if(gptr->getName() == group) break;
            gptr = gptr->getNext();
        }
        
        ShapeNode* sNode = new ShapeNode();//deallocate
        gptr->getShapeList()->insert(sNode);
        Shape* newShape = new Shape(name, type, x_loc, y_loc, x_size, y_size);
        sNode -> setShape(newShape);
        cout << "moved " << name << " to " << group << endl;
        
    }
}


void deleteCommand(stringstream& sin){
    string arg;
    int index;
    
    nameErrorCheck(sin,arg);
    
    index = findFuncForDelete(arg);
    
    
    
    if(index == -1){
        errorInput("shape " + arg + " not found", 3);
    }
    
    
    if(!errorExists()){
        string name, type;
        int x_loc, y_loc, x_size, y_size;
        
        GroupNode *tptr = gList->getHead();
        GroupNode *poolptr = gList->getHead();
        GroupNode *trptr = gList->getHead();
        ShapeNode* rptr;
        
        if(tptr != nullptr){
            rptr =  tptr->getShapeList()->getHead();
        }
        
        while(tptr != nullptr){
            if(tptr->getName() == arg){
                cout << arg << ": deleted" << endl;
                
                if(tptr->getShapeList()->getHead() == nullptr){
                    
                    GroupNode* delgptr = gList->remove(arg);
                    delete delgptr;
                }
                else{
                    while(rptr != nullptr){
                        name = rptr->getShape()->getName();
                        type = rptr->getShape()->getType();
                        x_loc = rptr->getShape()->getXlocation();
                        y_loc = rptr->getShape()->getYlocation();
                        x_size = rptr->getShape()->getXsize();
                        y_size = rptr->getShape()->getYsize();
                        
                        delete rptr->getShape();
                        
                        ShapeNode* sNode = new ShapeNode();
                        poolptr->getShapeList()->insert(sNode);
                        Shape* newShape = new Shape(name, type, x_loc, y_loc, x_size, y_size);
                        sNode -> setShape(newShape);
                        rptr = rptr->getNext();
                    }
                    
                    GroupNode* delgptr1 = gList->remove(arg);
                    delete delgptr1;
                    break;    
                }
                
            }
            while(rptr != nullptr){
                if(rptr->getShape()->getName() == arg){
                    ShapeNode* delptr = tptr->getShapeList()->remove(arg);
                    delete delptr;
                    cout << arg << ": deleted" << endl;
                    break;
                }
                rptr = rptr->getNext(); 
            }
            tptr = tptr->getNext();      
            
            if(tptr != nullptr){
                rptr = tptr->getShapeList()->getHead();
            }
        }
    }
}    


void nameErrorCheck(stringstream& sin, string& var){
    if(errorExists()){
        return;
    }
    
    sin >> var;
    
    int num = NUM_KEYWORDS > NUM_TYPES ? NUM_KEYWORDS : NUM_TYPES;
    for (int i = 0; i < num; i++) {
        if ((i < NUM_KEYWORDS && var == keyWordsList[i]) || (i < NUM_TYPES && var == shapeTypesList[i])) {
            errorInput("invalid name", 1);
            return;
        }
    }
}

int findShape(string arg){
   
    GroupNode *tptr = gList->getHead();
    ShapeNode *rptr;
    if(tptr != nullptr){
        rptr =  tptr->getShapeList()->getHead();
    }
    
    while(tptr != nullptr){
        while(rptr != nullptr){
            if(rptr->getShape()->getName() == arg){
                return 1;
            }
            rptr = rptr->getNext();
        }
        tptr = tptr->getNext();
        if(tptr != nullptr){
            rptr =  tptr->getShapeList()->getHead();
        }
    }
    return -1;
    
    
}

int findGroup(string arg){
    GroupNode *gptr = gList->getHead();
    
    while(gptr != nullptr){
        if(gptr->getName() == arg){
            return 1;
        }
        gptr = gptr ->getNext();
    }
    return -1;   
}

int findFuncForDelete(string arg){
    GroupNode *tptr = gList->getHead();
    GroupNode *gptr = gList->getHead();
    ShapeNode *rptr = tptr->getShapeList()->getHead();
    
    while(gptr != nullptr){
        if(gptr->getName() == arg){
            return 1;
        }
        gptr = gptr ->getNext();
    }
    
 
    if(tptr != nullptr){
        rptr =  tptr->getShapeList()->getHead();
    }
    
    while(tptr != nullptr){
        while(rptr != nullptr){
            if(rptr->getShape()->getName() == arg){
                return 1;
            }
            rptr = rptr->getNext();
        }
        tptr = tptr->getNext();
        if(tptr != nullptr){
            rptr =  tptr->getShapeList()->getHead();
        }
    }
    return -1;
    
    
    if(tptr == nullptr || gptr == nullptr){
        return -1;
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

bool errorExists() {
    return !error.empty();
}
