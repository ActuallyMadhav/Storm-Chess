#include "raylib.h"
#include "board.h"
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
void drawPiece(int x, int y, int size, int piece);
bool flipped = false;   // tracks whether board is flipped or not
std::pair<int, int> getScreenCoords(int x, int y);    // gives the flipped coordinates if board is flipped. gives normal if not

// input handling
void mouse();
void keyboard();

// coordinates to track selected square
int selectX = -1;
int selectY = -1;

// game state
Board game;

int main(){

    InitWindow(width, height, "Chess Engine");
    game.loadSprites();
    SetTargetFPS(60);

    while(!WindowShouldClose()){

        mouse();
        keyboard();

        BeginDrawing();
        GetWorkingDirectory();
        ClearBackground(RAYWHITE);
        drawBoard();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

std::pair<int, int> getScreenCoords(int x, int y){
    int screenX, screenY;
    if(flipped){
        screenX = squareX + squareSize * (7 - x);
        screenY = squareY + squareSize * (7 - y);
    }
    else{
        // not flipped
        screenX = squareX + squareSize * x;
        screenY = squareY + squareSize * y;
    }
    return {screenX, screenY};
}

void mouse(){
    Vector2 mousePos = GetMousePosition();
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        // get click coordinates
        int clickX = floor((mousePos.x - squareX) / squareSize);
        int clickY = floor((mousePos.y - squareY) / squareSize);

        if(flipped){
            clickX = 7 - clickX;
            clickY = 7 - clickY;
        }
        // move selected piece if selected square has piece
        if(selectX >= 0 && selectX < 8 && selectY >= 0 && selectY < 8 && game.getPiece(selectX + 8 * selectY) != empty){
            if(clickX >= 0 && clickX < 8 && clickY >= 0 && clickY < 8){
                game.setPiece(clickX + 8 * clickY, game.getPiece(selectX + 8 * selectY));
                game.setPiece((selectX + 8 * selectY), empty);
            }

            selectX = -1;
            selectY = -1;
        }
        else{
            // select square that was clicked
            selectX = clickX;
            selectY = clickY;
        }
    }
}

void keyboard(){
    // close on 'esc' key
    if(IsKeyPressed(KEY_ESCAPE)){
        CloseWindow();
    }

    // flip board on 'space' key
    if(IsKeyPressed(KEY_SPACE)){
        flipped = !flipped;
    }
}

void drawBoard(){
    //draw background
    DrawRectangle(boardX, boardY, boardX + boardSize, boardY + boardSize, boardBackground);

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            std::pair<int, int> screenCoords = getScreenCoords(i, j);
            Color squareColor = ((i + j) % 2) ? BROWN : LIGHTGRAY;
            DrawRectangle(screenCoords.first, screenCoords.second, squareSize, squareSize, squareColor);
        }
    }

    // highlight selected square
    std::pair<int, int> highlightCoords = getScreenCoords(selectX, selectY);
    if(selectX >= 0 && selectX < 8 && selectY >= 0 && selectY < 8){
        DrawRectangle(highlightCoords.first, highlightCoords.second, squareSize, squareSize, GREEN);
    }

    // draw pieces
    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            std::pair<int, int> screenCoords = getScreenCoords(x, y);
            uint8_t square = y * 8 + x;
            drawPiece(screenCoords.first + 0.5 * squareSize, screenCoords.second + 0.5 * squareSize, squareSize, game.getPiece(square));
        }
    }
}

// draw piece func
void drawPiece(int x, int y, int size, int piece){
    if(piece != empty){
        Texture2D sprite = game.pieceSprites[piece];

        // scale to match square size and center accordingly
        float scaleX = (float)squareSize / sprite.width;
        float scaleY = (float)squareSize / sprite.height;
        float scale = fmin(scaleX, scaleY);

        Vector2 pos = {
            x - (sprite.width * scale) / 2,
            y - (sprite.height * scale) / 2
        };

        DrawTextureEx(sprite, pos, 0.0f, scale, WHITE);
    }
}