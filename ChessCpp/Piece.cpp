#include "Piece.h"
#include <cmath>

// Constructor for Piece class
Piece::Piece(char type, bool isWhite) : type(type), isWhite(isWhite), hasMoved(false) {}

// Get the type of the piece
char Piece::getType() const {
    return type;
}

// Check if the piece is white
bool Piece::isWhitePiece() const {
    return isWhite;
}

// Check if the piece has moved
bool Piece::hasPieceMoved() const {
    return hasMoved;
}

// Mark the piece as moved
void Piece::markAsMoved() {
    hasMoved = true;
}

// Implement piece movement validation including en passant and castling
bool Piece::isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8], bool isWhiteTurn, bool& castlingPerformed, int lastPawnDoubleMove[2]) {
    if (startX == endX && startY == endY) return false;

    Piece* target = board[endX][endY];
    if (target != nullptr && target->isWhitePiece() == this->isWhitePiece()) return false;

    int deltaX = abs(endX - startX);
    int deltaY = abs(endY - startY);

    // Logic for movement validation (pawns, rook, knight, bishop, queen, king, en passant, castling)
    // Add castling and en passant logic here based on the previous implementation
    //...

    return false; // Return false by default if no valid move is found
}