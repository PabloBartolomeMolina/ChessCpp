#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"

class Board {
    Piece* board[8][8];
    int lastPawnDoubleMove[2];  // To track en passant
    int whiteKingPos[2];        // White King position
    int blackKingPos[2];        // Black King position

public:
    Board();
    void initializeBoard();
    void displayBoard();
    bool movePiece(int startX, int startY, int endX, int endY, bool& castlingPerformed);
    bool isInCheck(bool isWhite);
    bool isCheckmate(bool isWhite);
    bool isStalemate(bool isWhite);
    bool hasValidMoves(bool isWhite);
    Piece* getPieceAt(int x, int y);
};

#endif