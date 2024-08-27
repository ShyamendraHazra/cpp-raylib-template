#include "RAYLIB_TEST.h"

int main(void)
{   
    WINDOW win;
    init_window_data(&win);
    uint8_t fonstSize = 25;
    TEXT heading;
    Rectangle Rect_One;


    InitWindow(win.X,win.Y, "RAYLIB MK I");
    
    init_text_object(&heading,\
        "Congrats! You created your first window!",\
        fonstSize,\
        win
    );

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawRectangleRounded(\
            (Rectangle){\
            (win.X - (win.X/2 + 10)),\
            (win.Y - (win.Y/2 + 10)),\
            200,\
            200},\
            0.08,100,RED\
        );
        
        DrawText(heading.val, heading.current_X1, heading.current_Y1, fonstSize, WHITE);

        heading.current_X1 += heading.X_change;
        heading.current_Y1 += heading.Y_change;

        heading.current_X2 += heading.X_change;
        heading.current_Y2 += heading.Y_change;

        if (heading.current_X1 <= 0 || heading.current_X2 >=  win.X) {
            heading.X_change = - heading.X_change;
        }
        
        if (heading.current_Y1 <= 0 || heading.current_Y2 >=  win.Y) {
            heading.Y_change = - heading.Y_change;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}