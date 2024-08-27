#ifndef RAYLIB_TEST_H
#define RAYLIB_TEST_H

    #include <raylib.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <string.h>


    typedef struct {
        uint16_t X;
        uint16_t Y;
        uint16_t CX;
        uint16_t CY;
    } WINDOW;

    typedef struct {
        char* val;
        uint8_t length;
        uint16_t current_X1;
        uint16_t current_X2;
        uint16_t current_Y1;
        uint16_t current_Y2;
        int8_t X_change;
        int8_t Y_change;
        uint8_t font_size;
        uint16_t text_bound_x;
        uint16_t text_bound_y;
    } TEXT;


    typedef struct{
        Rectangle* rectp;
        uint16_t border_radius;
        int8_t X_change;
        int8_t Y_change;
    }RectangleData;

    typedef struct{
        uint16_t X;
        uint16_t Y;
    } CoOrdinate;


    void init_window_data(WINDOW* win);
    void init_text_object(TEXT* text, char* string, uint8_t font_size, WINDOW win);
    void print_text_object(TEXT* text);
    void init_rectangle(RectangleData* rect, CoOrdinate coor, WINDOW win);
    void print_font_meta(Font* font);
#endif