#include "board.h"

uint8_t Board::getPiece(uint8_t square){
    uint64_t mask = uint64_t(1) << square;
    for(int i = 0; i < 12; i++){
        if(bitboards[i] & mask){
            return i;
        }
    }
    return empty;
}

void Board::setPiece(uint8_t square, uint8_t piece){
    uint64_t mask = uint64_t(1) << square;
    for(int i = 0; i < 12; i++){
        if(i == piece){
            bitboards[i] |= mask;   // set bit
        }
        else{
            bitboards[i] &= ~mask;  // clear bit
        }
    }
}

void Board::loadSprites(){
    pieceSprites[wpawn] = LoadTexture("sprites/white/whitePawn.png");
    SetTextureFilter(pieceSprites[wpawn], TEXTURE_FILTER_POINT);
    
    pieceSprites[wknight] = LoadTexture("sprites/white/whiteKnight.png");
    SetTextureFilter(pieceSprites[wpawn], TEXTURE_FILTER_POINT);    
    
    pieceSprites[wbishop] = LoadTexture("sprites/white/whiteBishop.png");
    SetTextureFilter(pieceSprites[wpawn], TEXTURE_FILTER_POINT);
    
    pieceSprites[wrook] = LoadTexture("sprites/white/whiteRook.png");
    SetTextureFilter(pieceSprites[wpawn], TEXTURE_FILTER_POINT);
    
    pieceSprites[wqueen] = LoadTexture("sprites/white/whiteQueen.png");
    SetTextureFilter(pieceSprites[wpawn], TEXTURE_FILTER_POINT);
    
    pieceSprites[wking] = LoadTexture("sprites/white/whiteKing.png");
    SetTextureFilter(pieceSprites[wpawn], TEXTURE_FILTER_POINT);    
    
    pieceSprites[bpawn] = LoadTexture("sprites/black/blackPawn.png");
    SetTextureFilter(pieceSprites[wpawn], TEXTURE_FILTER_POINT);    
    
    pieceSprites[bknight] = LoadTexture("sprites/black/blackKnight.png");
    SetTextureFilter(pieceSprites[wpawn], TEXTURE_FILTER_POINT);
    
    pieceSprites[bbishop] = LoadTexture("sprites/black/blackBishop.png");
    SetTextureFilter(pieceSprites[wpawn], TEXTURE_FILTER_POINT);
    
    pieceSprites[brook] = LoadTexture("sprites/black/blackRook.png");
    SetTextureFilter(pieceSprites[wpawn], TEXTURE_FILTER_POINT);
    
    pieceSprites[bqueen] = LoadTexture("sprites/black/blackQueen.png");
    SetTextureFilter(pieceSprites[wpawn], TEXTURE_FILTER_POINT);
    
    pieceSprites[bking] = LoadTexture("sprites/black/blackKing.png");
    SetTextureFilter(pieceSprites[wpawn], TEXTURE_FILTER_POINT);
}

Board::Board(){
    bitboards[bpawn] = 0x000000000000ff00;
    bitboards[bknight] = 0x0000000000000042;
    bitboards[bbishop] = 0x0000000000000024;
    bitboards[brook] = 0x0000000000000081;
    bitboards[bqueen] = 0x0000000000000008;
    bitboards[bking] = 0x0000000000000010;
    bitboards[wpawn] = 0x00ff000000000000;
    bitboards[wknight] = 0x4200000000000000;
    bitboards[wbishop] = 0x2400000000000000;
    bitboards[wrook] = 0x8100000000000000;
    bitboards[wqueen] = 0x0800000000000000;
    bitboards[wking] = 0x1000000000000000;
}

Board::~Board(){
    for(int i = 0; i < 12; i++){
        UnloadTexture(pieceSprites[i]);
    }
}