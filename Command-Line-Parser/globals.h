#ifndef globals_h
#define globals_h
#include<string>

// These arrays should make it easier to check that a name is not a reserved word
// and that an entered shape type is valid
#define NUM_KEYWORDS 7
string keyWordsList[7]={"all", "maxShapes", "create", "move", "rotate", "draw", "delete"};

#define NUM_TYPES 4
string shapeTypesList[4]={"circle", "ellipse", "rectangle","triangle"};

#endif /* globals_h */
