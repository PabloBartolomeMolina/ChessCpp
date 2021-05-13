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
        createPieces(1);
        turn = 1;   // First move is for white player.
    } 
    else
    {
        cout << "Player black has been created." << endl;
        createPieces(0);
    }
}

/// <summary>
/// Public destructor.
/// </summary>
CPlayer::~CPlayer()
{
    
    
    cout << "Player white has been destroyed." << endl;
    
    
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
        CPawn pawn1(color, "a2", 1);
        pawns.push_back(pawn1);
        CPawn pawn2(color, "b2", 2);
        pawns.push_back(pawn2);
        CPawn pawn3(color, "c2", 3);
        pawns.push_back(pawn3);
        CPawn pawn4(color, "d2", 4);
        pawns.push_back(pawn4);
        CPawn pawn5(color, "e2", 5);
        pawns.push_back(pawn5);
        CPawn pawn6(color, "f2", 6);
        pawns.push_back(pawn6);
        CPawn pawn7(color, "g2", 7);
        pawns.push_back(pawn7);
        CPawn pawn8(color, "h2", 8);
        pawns.push_back(pawn8);

        cout << pawns[5].position << endl;
        cout << pawn6.position << endl;

    }
    else            // Black player pieces.
    {
        // Create eight pawns.
        
    }
}