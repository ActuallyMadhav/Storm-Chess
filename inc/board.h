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

public:
    int boardSetup[64] = {
        brook, bknight, bbishop, bqueen, bking, bbishop, bknight, brook,
        bpawn, bpawn, bpawn, bpawn, bpawn, bpawn, bpawn, bpawn,
        empty, empty, empty, empty, empty, empty, empty, empty,
        empty, empty, empty, empty, empty, empty, empty, empty,
        empty, empty, empty, empty, empty, empty, empty, empty,
        empty, empty, empty, empty, empty, empty, empty, empty,
        wpawn, wpawn, wpawn, wpawn, wpawn, wpawn, wpawn, wpawn,
        wrook, wknight, wbishop, wqueen, wking, wbishop, wknight, wrook
    };

    inline int convert2Dto1D(uint8_t x, uint8_t y) const{
        return y*8 + x;
    }

};