#ifndef RAYLIB_TEST_H
#define RAYLIB_TEST_H

#include "std.h"


    using std::string;

    // This header file contains all of the API wrapper data structures and function declarations (prototypes)
    
    /* WINDOW struct used to define and store open window data */
    typedef struct {

        float height;
        float width;
        const char* title;

    } WINDOW;

    // Shape structure listed below are all the shapes that can be drawn on the screen

    typedef struct {
        char* text;
        Font font;
    } Text;                                       // DS for Rendering texts on the screen

    typedef struct {
        
    } Line;                                       // DS for Rendering lines on the screen


    // SHAPE_ID enum is used to identify the shape type

    typedef enum {
        TEXT,
        LINE,
        RECTANGLE,
        CIRCLE,
        RING,
        ELLIPSE,
        TRIANGLE,
        POLYGON
    } SHAPE_ID;
    
    //  objRef contains a pointer to the shape

    typedef union {
        Text* text;
        Line* line;
        Rectangle* rectangle;
        // Circle* cirlce;
        // Ring* ring;
        // Ellipse* ellipse;
        // Triangle* triangle;
        // Polygon* polygon;
    } SHAPE_REF;

    // OBJMETADATA contains the metadata of the object 

    typedef struct {
        Vector2 objStartingPos;
        Vector2 objDimensions;
        Vector2 objCurrentPos;
        Color objColor;
        bool objMovementState;
        Vector2 objMovementSpeed;
    } OBJ_META_DATA;

    typedef struct {
        SHAPE_ID id;
        SHAPE_REF obj;
        OBJ_META_DATA meta_data;
    } SHAPE;

    struct ELEMENT;
    
    typedef struct {
        void (*initElement) (ELEMENT* elem, SHAPE_ID objType);
        void (*printElementToSTDO) (ELEMENT* elem);
        void (*printElementToScreen) (ELEMENT* elem);
    } SHAPEFUNC;

    typedef struct ELEMENT {
        SHAPE obj;
        SHAPEFUNC func;
    } ELEMENT;




#endif