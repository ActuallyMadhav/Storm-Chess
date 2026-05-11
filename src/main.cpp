#include "raylib.h"
#include <iostream>

// window params
int width = 640;
int height = 640;

double boardX = 0.5 * (width - height);
double boardY = 0;
double boardSize = height;

double squareSize = boardSize * 0.9 * 0.125;
double squareX = boardX + boardSize*0.05;
double squareY = boardY + boardSize*0.05;

// board color
Color boardBackground = CLITERAL(Color){90, 63, 47,255};

// draw chess board
void drawBoard();

// coordinates to track selected square
int selectX = -1;
int selectY = -1;

int main(){

    InitWindow(width, height, "Chess Engine");
    SetTargetFPS(60);

    while(!WindowShouldClose()){

        Vector2 mousePos = GetMousePosition();
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            selectX = floor((mousePos.x - squareX) / squareSize);
            selectY = floor((mousePos.y - squareY) / squareSize);
        }

        if(IsKeyPressed(KEY_ESCAPE)){
            break;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawBoard();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void drawBoard(){
    //draw background
    DrawRectangle(boardX, boardY, boardX + boardSize, boardY + boardSize, boardBackground);

    // draw squares
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            Color squareColor = ((i + j) % 2) ? BROWN : LIGHTGRAY;
            DrawRectangle(squareX + squareSize * i, squareY + squareSize * j, squareSize, squareSize, squareColor);
        }
    }

    // highlight selected square
    if(selectX >= 0 && selectY >= 0 && selectX <= 8 && selectY <= 8){
        DrawRectangle(squareX + squareSize*selectX, squareY + squareSize*selectY, squareSize, squareSize, GREEN);
    }
}