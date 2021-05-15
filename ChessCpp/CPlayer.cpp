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
    this->color = color;
    if (color)      // White player pieces.
    {
        this->turn = 1;     // White player starts playing.
        // Create eight pawns.
        for (int i = 0; i < 8; i++)
        {
            CPawn pawn(color, whiteInitialPawns[i], 1);
            pawns.push_back(pawn);
        }
        CRook rook(color, whiteInitialPieces[0], 1);
        CKnight knight(color, whiteInitialPieces[1], 1);
        CBishop bishop(color, whiteInitialPieces[2], 1);
        CQueen queen(color, whiteInitialPieces[3], 1);
        CKing king(color, whiteInitialPieces[4], 1);
        CRook rook(color, whiteInitialPieces[5], 1);
        CKnight knight(color, whiteInitialPieces[6], 1);
        CBishop bishop(color, whiteInitialPieces[7], 1);
    }
    else            // Black player pieces.
    {
        this->turn = 0;     // White player starts playing.
        // Create eight pawns.
        for (int i = 0; i < 8; i++)
        {
            CPawn pawn(color, blackInitialPawns[i], 1);
            pawns.push_back(pawn);
        }
        CRook rook(color, blackInitialPieces[0], 1);
        CKnight knight(color, blackInitialPieces[1], 1);
        CBishop bishop(color, blackInitialPieces[2], 1);
        CQueen queen(color, blackInitialPieces[3], 1);
        CKing king(color, blackInitialPieces[4], 1);
        CRook rook(color, blackInitialPieces[5], 1);
        CKnight knight(color, blackInitialPieces[6], 1);
        CBishop bishop(color, blackInitialPieces[7], 1);
    }
}