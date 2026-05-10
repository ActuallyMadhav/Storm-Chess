#include "raylib.h"
#define BOARD_SIZE 8
#define SQUARE_SIZE 60

void drawBoard(){
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            Color squareColor = ((i + j) % 2) ? BLACK : WHITE;
            DrawRectangle(i * SQUARE_SIZE, j * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, squareColor);
        }
    }
}

int main(){

    InitWindow(BOARD_SIZE * SQUARE_SIZE, BOARD_SIZE * SQUARE_SIZE, "Chess Engine");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawBoard();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}