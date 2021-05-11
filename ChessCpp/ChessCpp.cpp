// ChessCpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Board.h"
#include "Player.h"

int main()
{
    // Creation of board and both players.
    Board board = Board();
    Player whitePlayer = Player(true);
    Player blackPlayer = Player(false);

    // Show board.
    board.showBoard();
}
