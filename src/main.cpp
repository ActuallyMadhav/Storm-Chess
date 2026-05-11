#include "raylib.h"
#include <iostream>
#define BOARD_SIZE 8
#define SQUARE_SIZE 60

Color boardBackground = CLITERAL(Color){90, 63, 47,255};
void drawBoard();

int main(){

    InitWindow(510, 510, "Chess Engine");
    SetTargetFPS(60);

    while(!WindowShouldClose()){

        Vector2 mousePos = GetMousePosition();
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            std::cout << "button clicked at [" << mousePos.x << ", " << mousePos.y << "]" << '\n';
        }

        if(IsKeyPressed(KEY_ESCAPE)){
            break;
        }
        BeginDrawing();
        ClearBackground(boardBackground);
        drawBoard();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void drawBoard(){
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            Color squareColor = ((i + j) % 2) ? BROWN : LIGHTGRAY;
            DrawRectangle(i * SQUARE_SIZE + 15, j * SQUARE_SIZE + 15, SQUARE_SIZE, SQUARE_SIZE, squareColor);
        }
    }
}