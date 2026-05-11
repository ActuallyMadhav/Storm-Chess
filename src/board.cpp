#include "board.h"

uint8_t Board::getPiece(uint8_t square){
    uint64_t mask = uint64_t(1) << square;
    for(int i = 0; i < 12; i++){
        if(bitboards[i] && mask){
            return i;
        }
    }
    return empty;
}

uint8_t Board::setPiece(uint8_t square, uint8_t piece){

}