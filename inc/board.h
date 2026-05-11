#pragma once
#include <cstdint>

// positive = white, negative = black
enum Piece{
    empty = 0, 
    wpawn = 1, wknight = 2, wbishop = 3, wrook = 4, wqueen = 5, wking = 9,
    bpawn = -1, bknight = -2, bbishop = -3, brook = -4, bqueen = -5, bking = -9
};

class Board{
private:
    uint64_t bitboards[12]; // one bitboard for each piece type. 1 - piece on square, 0 - piece not on square

public:

    uint8_t getPiece(uint8_t square);
    uint8_t setPiece(uint8_t square, uint8_t piece);

    // constructor
    Board();
    
};