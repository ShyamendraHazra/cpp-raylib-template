#ifndef RAYLIB_TEST_H
#define RAYLIB_TEST_H

#include "common.h"
#include "Test.h"


     
    // This header file contains all of the API wrapper data structures and function declarations (prototypes)
    
    /* WINDOW struct used to define and store open window data */
    typedef struct {

        float WinHeight;
        float WinWidth;

    } WINDOW;

    // Shape structure listed below are all the shapes that can be drawn on the screen

    typedef struct {
        char* text;
        Font font;
        Color color;
    } Text;                                       // DS for Rendering texts on the screen

    /* OBJMETADATA (OBJECT META DATA) will contain state and position of the object within the window */

    typedef struct {
        Vector2 objStartingPos;                    // The position on screen in the Window from where the object will be drawn
        bool objMovementState;                     // boolean value to track if the object is static or moving object
        Vector2 objMovementSpeed;                  // The movement speed of object if it is a moving object
    } OBJMETADATA;

    typedef enum {
        TEXT,
        RECTANGLE,
        CIRCLE,
        ELLIPSE,
        RING,
        LINE
    } SHAPE_ID;
    
    // typedef union {
    //     Line* shape;
    //     Rectangle* shape;
    //     Circle* shape;
    //     Ellipse* shape;
    //     Triangle* shape;
    //     Polygon* shape;
    // } objRef;

    // typedef struct {
    //     SHAPE_ID id;
    //     objRef obj;
    //     OBJMETADATA meta;
    // } SHAPE;

    // typedef struct {
    //     ELEMENT* this;
    //     SHAPE obj;
    //     SHAPEFUNC func;
    // } ELEMENT;

    // typedef struct {
    //     void (*initElement)(ELEMENT* elem, SHAPE_ID objType);
    //     void (*printElementToSTDO)(ELEMENT* elem);
    //     void (*printElementToScreen)(ELEMENT* elem);
    // } SHAPEFUNC;



#endif