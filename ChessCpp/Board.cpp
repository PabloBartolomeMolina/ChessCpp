#include "Board.h"
#include <iostream>

// Initialize the chess board with pieces in starting positions
Board::Board() {
    initializeBoard();
}

// Initialize the board with the default starting positions of pieces
void Board::initializeBoard() {
    // Initialize white and black pieces
    // Set initial positions of pawns, rooks, knights, bishops, queen, king
    // Set positions for whiteKingPos and blackKingPos
    //...

    lastPawnDoubleMove[0] = -1;  // No en passant initially
    lastPawnDoubleMove[1] = -1;
}

// Display the current board in the console
void Board::displayBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == nullptr) {
                std::cout << ". ";
            }
            else {
                std::cout << board[i][j]->getType() << ' ';
            }
        }
        std::cout << std::endl;
    }
}

// Move a piece on the board, handling en passant and castling
bool Board::movePiece(int startX, int startY, int endX, int endY, bool& castlingPerformed) {
    Piece* piece = board[startX][startY];
    if (piece != nullptr && piece->isValidMove(startX, startY, endX, endY, board, piece->isWhitePiece(), castlingPerformed, lastPawnDoubleMove)) {
        // Update King's position if the King moves
        if (piece->getType() == 'K') {
            if (piece->isWhitePiece()) {
                whiteKingPos[0] = endX;
                whiteKingPos[1] = endY;
            }
            else {
                blackKingPos[0] = endX;
                blackKingPos[1] = endY;
            }
        }
        // The rest of pieces are to be added.
        //...

        // Perform the move
        board[endX][endY] = piece;
        board[startX][startY] = nullptr;
        piece->markAsMoved();

        return true;
    }
    return false;
}

// Check if the current player's King is in check
bool Board::isInCheck(bool isWhite) {
    // Check if the opponent's pieces are threatening the current player's King
    //...
    return false;
}

// Check if the current player is in checkmate
bool Board::isCheckmate(bool isWhite) {
    return isInCheck(isWhite) && !hasValidMoves(isWhite);
}

// Check if the current player is in stalemate
bool Board::isStalemate(bool isWhite) {
    return !isInCheck(isWhite) && !hasValidMoves(isWhite);
}

// Check if the current player has valid moves
bool Board::hasValidMoves(bool isWhite) {
    // Iterate over all pieces to check if there are any valid moves
    //...
    return false;
}
