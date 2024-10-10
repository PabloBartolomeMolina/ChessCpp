#include "Game.h"
#include <iostream>

// Constructor for Game class
Game::Game() : isWhiteTurn(true) {}

// Start the game and handle the game loop
void Game::startGame() {
    bool castlingPerformed = false;
    chessBoard.displayBoard();

    while (true) {
        playerMove();
        chessBoard.displayBoard();
        checkGameState();
        isWhiteTurn = !isWhiteTurn;
    }
}

// Handle player move input
void Game::playerMove() {
    int startX, startY, endX, endY;
    bool castlingPerformed = false;

    std::cout << (isWhiteTurn ? "White's move: " : "Black's move: ");
    std::cin >> startX >> startY >> endX >> endY;

    if (!chessBoard.movePiece(startX, startY, endX, endY, castlingPerformed)) {
        std::cout << "Invalid move, try again.\n";
        playerMove();
    }
}

// Check for check, checkmate, or stalemate after each move
void Game::checkGameState() {
    if (chessBoard.isCheckmate(isWhiteTurn)) {
        std::cout << (isWhiteTurn ? "White" : "Black") << " is in checkmate. Game over!\n";
        exit(0);
    }

    if (chessBoard.isStalemate(isWhiteTurn)) {
        std::cout << "It's a stalemate. Game over!\n";
        exit(0);
    }

    if (chessBoard.isInCheck(isWhiteTurn)) {
        std::cout << (isWhiteTurn ? "White" : "Black") << " is in check!\n";
    }
}
