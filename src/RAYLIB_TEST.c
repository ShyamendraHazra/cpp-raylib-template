#include "RAYLIB_TEST.h"

int main(void)
{   
    uint8_t FPS = 120;
    uint16_t WIN_WIDTH = 1500;
    uint16_t WIN_HEIGHT = 1000;
    uint8_t fonstSize = 25;
    TEXT heading;
    char StringPos[64];




    InitWindow(WIN_WIDTH,WIN_HEIGHT, "RAYLIB MK I");
    
    initialize_text_object(&heading,\
        "Congrats! You created your first window!",\
        fonstSize,\
        WIN_WIDTH,\
        WIN_HEIGHT\
    );

    while (!WindowShouldClose())
    {
        BeginDrawing();
        SetTargetFPS(FPS);
        DrawFPS(20, 20);
        ClearBackground(BLACK);
        
        sprintf(\
            StringPos,\
            "X1 : %d, X2: %d, Y1: %d, Y2: %d",\
            heading.current_X1,\
            heading.current_X2,\
            heading.current_Y1,\
            heading.current_Y2\
        );
        
        DrawText(StringPos, 20, 50,25, WHITE);
        
        DrawText(heading.val, heading.current_X1, heading.current_Y1, fonstSize, WHITE);

        heading.current_X1 += heading.X_change;
        heading.current_Y1 += heading.Y_change;

        heading.current_X2 += heading.X_change;
        heading.current_Y2 += heading.Y_change;

        if (heading.current_X1 <= 0 || heading.current_X2 >=  WIN_WIDTH) {
            heading.X_change = - heading.X_change;
        }
        
        if (heading.current_Y1 <= 0 || heading.current_Y2 >=  WIN_HEIGHT) {
            heading.Y_change = - heading.Y_change;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}