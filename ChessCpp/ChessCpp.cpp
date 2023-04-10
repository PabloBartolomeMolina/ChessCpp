// ChessCpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <algorithm>
#include <conio.h>
#include <iostream>
#include <vector>

#include "color.h"

#include "CBoard.h"
#include "CPlayer.h"
#include "Movement.h"

using namespace std;


/// <summary>
/// Function to manage the basic logic of movements.
/// </summary>
/// <returns></returns>
bool Move()
{
    bool moved = false;
    /// <summary>
    ///  Expected format :
    /// movement_parts[0] : format ok / nok
    /// </summary>
    /// <returns></returns>
    string* movement_parts;
    movement_parts = Movement();
    if (movement_parts[0] == "True")
    {
        // Format is valid, so we can analyze the feasibility of the movement.

        // Is the position of destination empty ? Can we eat an enemy piece at that position ?
        // is the path until destination free ? Is the piece we want to move bloqued in his way there ?
    }
    else
    {
        // Format is not valid, so we need to ask again the user's input for the movement.
    }
    

    return moved;
}


/// <summary>
/// Function to manage the basic logic of the program.
/// </summary>
void basicLogic()
{
    bool mate = false;  // Variable to indicate the end of the game.

    // Creation of board and both players.
    CBoard board = CBoard();
    //_getch();     // Debugging purposes
    CPlayer whitePlayer = CPlayer(true);
    //_getch();     // Debugging purposes
    CPlayer blackPlayer = CPlayer(false);
    //_getch();     // Debugging purposes

    while (!mate)
    {
        // Show board.
        board.showBoard(1);     // Board view for white player.
        
        bool moved = Move();

/*
        // White player moves.
        vector<string> movement = whitePlayer.Move();
        cout << movement[0] << "   " << movement[1] << endl;
        movement = whitePlayer.Move();
        board.placePieces(movement[0], movement[1]);

        board.showBoard(0);     // Board view for black player.
        // Black player moves.
        movement = blackPlayer.Move();
        board.placePieces(movement[0], movement[1]);
*/
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
        cout << "Please, select an option by its number :" << endl << "     1. Play a new game." << endl << "     2. Exit app." << endl;
        cin >> input;
    }   // Rest in the loop until one of the 2 valid options is choosen.

    if (stoi(input) == 1)       // Play a new game option.
    {
        basicLogic();
        cout << "That was the end of the game..." << endl;  // End of a chess game.
        // Provisional behavior. Better to go to the initial menu to give option to reply a game.
        cout << "See you next time!!" << endl;
    }
    else if (stoi(input) == 2)  // Exit game option.
    {
        cout << "See you next time!!" << endl;
    }
}