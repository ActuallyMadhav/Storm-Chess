#pragma once
#include <cstdint>
#include "raylib.h"

// positive = white, negative = black
enum Piece{
    wpawn = 0, wknight = 1, wbishop = 2, wrook = 3, wqueen = 4, wking = 5,
    bpawn = 6, bknight = 7, bbishop = 8, brook = 9, bqueen = 10, bking = 11,
    empty = 12
};

class Board{
private:
    uint64_t bitboards[12]; // one bitboard for each piece type. 1 - piece on square, 0 - piece not on square

public:

    Texture2D pieceSprites[12];

    uint8_t getPiece(uint8_t square);
    void setPiece(uint8_t square, uint8_t piece);
    void loadSprites();

    // constructor
    Board();
    
    // destructor
    ~Board();
};