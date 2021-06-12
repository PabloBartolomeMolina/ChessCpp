// ChessCpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <algorithm>
#include "CBoard.h"
#include "CPlayer.h"


/// <summary>
/// Function to manage the basic logic of the program.
/// </summary>
void basicLogic()
{
    bool mate = false;  // Variable to indicate the end of the game.

    // Creation of board and both players.
    CBoard board = CBoard();
    CPlayer whitePlayer = CPlayer(true);
    CPlayer blackPlayer = CPlayer(false);

    while (!mate)
    {
        // Show board.
        board.showBoard(1);     // Board view for white player.
        // White player moves.
        string movement = whitePlayer.Move();

        //board.showBoard(0);     // Board view for black player.
        // Black player moves.
        string movement = whitePlayer.Move();
    }
}

/// <summary>
/// Check if a string is numeric or not.
/// </summary>
/// <returns>True if number, False if not.</returns>
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

/// <summary>
/// Main function, the entry point of the program.
/// </summary>
/// <returns></returns>
int main()
{
    string input = "empty";
    cout << initialMessage << endl << endl;
    
    while (!isNumber(input) || (stoi(input) != 1 && stoi(input) != 2) )
    {
        cout << "Please, select an option by its number :" << endl << "     1. PLay a new game." << endl << "     2. Exit app." << endl;
        cin >> input;
    }

    if (stoi(input) == 1)
    {
        basicLogic();
    }
    else if (stoi(input) == 1)
    {
        cout << "See you next time!!" << endl;
    }
    
}