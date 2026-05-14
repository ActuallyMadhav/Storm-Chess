#include "board.h"

uint8_t Board::getPiece(uint8_t square){
    uint64_t mask = uint64_t(1) << square;
    for(int i = 0; i < 12; i++){
        if(stateTracker[trackerIndex].bitboards[i] & mask){
            return i;
        }
    }
    return empty;
}

void Board::setPiece(uint8_t square, uint8_t piece){
    uint64_t mask = uint64_t(1) << square;
    for(int i = 0; i < 12; i++){
        if(i == piece){
            stateTracker[trackerIndex].bitboards[i] |= mask;   // set bit
        }
        else{
            stateTracker[trackerIndex].bitboards[i] &= ~mask;  // clear bit
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

void Board::move(const Move& move){
    // add new state to state tracker
    stateTracker[trackerIndex + 1] = stateTracker[trackerIndex++];

    // to and from bitboards
    uint64_t fromBitboard = uint64_t(1) << move.fromSquare;
    uint64_t toBitboard = uint64_t(1) << move.toSquare;
    uint64_t moveBitboard = fromBitboard | toBitboard;

    // to move a piece
    uint8_t movedPiece = empty;
    int i, limit;
    if(stateTracker[trackerIndex].turn == white){
        i = 0;
        limit = 6;
    }
    else{
        i = 6;
        limit = 12;
    }

    for(i; i < limit; i++){
        if(stateTracker[trackerIndex].bitboards[i] & fromBitboard){
            stateTracker[trackerIndex].bitboards[i] ^= moveBitboard;
            movedPiece = i;
            break;  // continue from here
        }
    }
}

void Board::undo(){
    if(trackerIndex){
        trackerIndex--;
    }
}

Board::Board(){
    // allocating memory for entire game
    stateTracker = new  boardState[1000];
    trackerIndex = 0;
    // starting positions
    stateTracker[0].bitboards[bpawn] = 0x000000000000ff00;
    stateTracker[0].bitboards[bknight] = 0x0000000000000042;
    stateTracker[0].bitboards[bbishop] = 0x0000000000000024;
    stateTracker[0].bitboards[brook] = 0x0000000000000081;
    stateTracker[0].bitboards[bqueen] = 0x0000000000000008;
    stateTracker[0].bitboards[bking] = 0x0000000000000010;
    stateTracker[0].bitboards[wpawn] = 0x00ff000000000000;
    stateTracker[0].bitboards[wknight] = 0x4200000000000000;
    stateTracker[0].bitboards[wbishop] = 0x2400000000000000;
    stateTracker[0].bitboards[wrook] = 0x8100000000000000;
    stateTracker[0].bitboards[wqueen] = 0x0800000000000000;
    stateTracker[0].bitboards[wking] = 0x1000000000000000;

    // castling rights
    stateTracker[0].whiteKingCastle = true;
    stateTracker[0].whiteQueenCastle = true;
    stateTracker[0].blackKingCastle = true;
    stateTracker[0].blackQueenCastle = true;

    // en passant bitboard
    stateTracker[0].enPassantTarget = 0;

    // white moves first
    stateTracker[0].turn = white;
}

Board::~Board(){
    for(int i = 0; i < 12; i++){
        UnloadTexture(pieceSprites[i]);
    }

    delete[] stateTracker;
}