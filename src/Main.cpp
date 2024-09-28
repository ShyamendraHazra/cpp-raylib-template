#include "app.h"

using namespace std;

int detectCollision();
void handleCollision();
int main() {

    const WINDOW window = {
        .height = 600,
        .width = 800,
        .title = "raylib [core] example - basic window"
    };

    initWindow(window);

    while (!WindowShouldClose())
    {   
        BeginDrawing();
        ClearBackground((Color) {0, 31, 63,1});
        DrawRectangleV((Vector2) {100,100}, (Vector2) {20,20}, (Color){255, 207, 179,255});
        EndDrawing();
    }

    CloseWindow();


    return 0;
}