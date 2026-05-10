#include "raylib.h"

int main(){

    InitWindow(600, 600, "test");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangle(200, 150, 100, 100, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}