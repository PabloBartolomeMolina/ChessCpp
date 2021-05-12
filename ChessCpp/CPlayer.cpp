#include "CPlayer.h"

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CPlayer::CPlayer(bool input)
{
    color = input;  // Set attribute for the current instance.
    // Set color of instance.
    if (color)
    {
        cout << "Player white has been created." << endl;
        turn = 1;   // First move is for white player.
    } 
    else
    {
        cout << "Player black has been created." << endl;
    }
}

/// <summary>
/// Public destructor.
/// </summary>
CPlayer::~CPlayer()
{
    if (color)
        cout << "Player white has been destroyed." << endl;
    else
        cout << "Player black has been destroyed." << endl;
}

/// <summary>
/// Method to perform a move.
/// </summary>
void CPlayer::Move()
{
    string move = " ";
    cout << movement;
    cin >> move;
}

/* PRIVATE methods of the class Player. */

/// <summary>
/// Method to create the proper pieces when player instance is created.
/// </summary>
/// <param name="color"></param>
void CPlayer::createPieces(bool color)
{
    if (color)      // White player pieces.
    {
        // Create eight pawns.
        for (int i = 0; i < 8; i++)
        {

        }
    }
    else            // Black player pieces.
    {
        // Create eight pawns.
        for (int i = 0; i < 8; i++)
        {

        }
    }
}