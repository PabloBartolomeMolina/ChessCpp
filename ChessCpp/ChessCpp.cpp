// ChessCpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CBoard.h"
#include "CPlayer.h"

/// <summary>
/// Function to manage the basic logic of the program.
/// </summary>
void basicLogic()
{
    // Creation of board and both players.
    CBoard board = CBoard();
    CPlayer whitePlayer = CPlayer(true);
    CPlayer blackPlayer = CPlayer(false);

    // Show board.
    board.showBoard(1);     // Board view for white player.
    board.showBoard(0);     // Board view for black player.
}

/// <summary>
/// Main function, the entry point of the program.
/// </summary>
/// <returns></returns>
int main()
{
    basicLogic();
}
