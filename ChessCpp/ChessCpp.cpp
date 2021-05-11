// ChessCpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CBoard.h"
#include "CPlayer.h"

int main()
{
    // Creation of board and both players.
    CBoard board = CBoard();
    CPlayer whitePlayer = CPlayer(true);
    CPlayer blackPlayer = CPlayer(false);

    // Show board.
    board.showBoard();
}
