#include "app.h"

using namespace std;

int detectCollision();
void handleCollision();
WINDOW initiate_window();
void start_gameloop();
void showWindow();

int main() {

    
    showWindow();

    return 0;
}


WINDOW initiate_window() {

    const WINDOW window = {
        .height = 640,
        .width = 800,
        .title = "raylib [core] example - basic window"
    };

    return window;
}

void start_gameloop() {

     while (!WindowShouldClose())
    {   
        BeginDrawing();
        ClearBackground(hexToRGBA("151515"));
        DrawRectangleV((Vector2) {100,100}, (Vector2) {100,100}, hexToRGBA("C73659"));
        EndDrawing();
    }

}

void showWindow() {
    const WINDOW window = initiate_window();
    initWindow(window);
    start_gameloop();
    CloseWindow();
}

