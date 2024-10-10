#ifndef PIECE_H
#define PIECE_H

class Piece {
    char type;
    bool isWhite;
    bool hasMoved;

public:
    Piece(char type, bool isWhite);

    bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8], bool isWhiteTurn, bool& castlingPerformed, int lastPawnDoubleMove[2]);
    char getType() const;
    bool isWhitePiece() const;
    bool hasPieceMoved() const;
    void markAsMoved();
};

#endif