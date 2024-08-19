#ifndef RAYLIB_TEST_H
#define RAYLIB_TEST_H

    #include <raylib.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <string.h>


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

    void initialize_text_object(TEXT* text, char* string, uint8_t font_size, uint16_t WIN_WIDTH, uint16_t WIN_HEIGHT);
    void print_text_object(TEXT* text);

#endif