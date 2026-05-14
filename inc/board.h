#pragma once
#include <cstdint>
#include "raylib.h"

// positive = white, negative = black
enum Piece{
    wpawn = 0, wknight = 1, wbishop = 2, wrook = 3, wqueen = 4, wking = 5,
    bpawn = 6, bknight = 7, bbishop = 8, brook = 9, bqueen = 10, bking = 11,
    empty = 12, white = 13, black = 14
};

struct boardState{
    // bitboards for each piece type
    uint64_t bitboards[12];
    // bitboard for en-passant
    uint64_t enPassantTarget;

    // castling availability
    bool whiteKingCastle;
    bool whiteQueenCastle;
    bool blackKingCastle;
    bool blackQueenCastle;

    // white or black turn
    uint8_t turn;

};

struct Move{
    // origin and destination square
    uint8_t fromSquare;
    uint8_t toSquare;

    // promotion validity;
    uint8_t promote;
};

class Board{
private:
    boardState* stateTracker;   // array of board states to track game
    int trackerIndex;
public:

    Texture2D pieceSprites[12];

    uint8_t getPiece(uint8_t square);
    void setPiece(uint8_t square, uint8_t piece);
    void loadSprites();

    // move methods
    void move(const Move& move);
    void undo();

    // constructor
    Board();
    
    // destructor
    ~Board();
};