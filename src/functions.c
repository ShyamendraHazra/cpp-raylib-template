#include "RAYLIB_TEST.h"
#include <raylib.h>

/*
 * This function initializes a ScreenLocationBuffer object which stores the value of a piece of text, its current x and y coordinates, and the amount to change the x and y coordinates when the text is moved.
 * The text is centered in the window by setting the x coordinate to the middle of the window minus half the width of the window with lenght of the string multiplied by 5 (each letter is asseumed to be 5 pixels wide ), and the y coordinate to the middle of the window plus 5 for line height.
 * The text is given a default movement of 1 in both the x and y directions.
 */


void init_window_data(WINDOW* win) {
    win->X = 1500;
    win->Y = 1000;
    win->CX = win->X/2;
    win->CY = win->Y/2;
}

void init_text_object(TEXT* text, char* string, uint8_t font_size, WINDOW win)  {
    text->val = string;
    text->length = strlen(string);
    text->X_change = 1;
    text->Y_change = 1;
    text->font_size = font_size;
    text->text_bound_x = MeasureText(text->val, text->font_size);
    text->text_bound_y = text->font_size;
    text->current_X1 = (win.CX - text->text_bound_x/2);
    text->current_X2 = text->current_X1 + text->text_bound_x;
    text->current_Y1 =(win.CY - text->text_bound_y/2);
    text->current_Y2 = text->current_Y1 + text->text_bound_y;
}

// Print the above structure data to stdout
void print_text_object(TEXT* text) {
    printf("val: %s\n", text->val);
    printf("length: %d\n", text->length);
    printf("X_change: %d\n", text->X_change);
    printf("Y_change: %d\n", text->Y_change);
    printf("font_size: %d\n", text->font_size);
    printf("text_bound_x: %d\n", text->text_bound_x);
    printf("text_bound_y: %d\n", text->text_bound_y);
    printf("current_X1: %d\n", text->current_X1);
    printf("current_X2: %d\n", text->current_X2);
    printf("current_Y1: %d\n", text->current_Y1);
    printf("current_Y2: %d\n", text->current_Y2);
}


void init_rectangle(RectangleData* rect, CoOrdinate coor, WINDOW win) {
    // code
}


 void print_font_meta(Font* font) {

    printf("Base Size :: %d\n", font->baseSize);

 }