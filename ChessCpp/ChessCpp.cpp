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
        vector<string> movement = whitePlayer.Move();
        cout << movement[0] << "   " << movement[1] << endl;
        board.placePieces(movement[0], movement[1]);

        board.showBoard(0);     // Board view for black player.
        // Black player moves.
        movement = whitePlayer.Move();
        board.placePieces(movement[0], movement[1]);
    }   // Rest in the loop until one player plays a "check mate" movement.
}

/// <summary>
/// Check if a string is numeric or not.
/// </summary>
/// <returns>True if number, False if not.</returns>
bool isNumber(string s)
{
    for (string::size_type i = 0; i < s.length(); i++)
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
    }   // Rest in the loop until one of the 2 valid options is choosen.

    if (stoi(input) == 1)
    {
        basicLogic();
        cout << "That was the end of the game..." << endl;
        cout << "See you next time!!" << endl;
    }
    else if (stoi(input) == 1)
    {
        cout << "See you next time!!" << endl;
    }
}