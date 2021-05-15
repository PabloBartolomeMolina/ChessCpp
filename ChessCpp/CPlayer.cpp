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
            CPawn pawn(color, whiteInitialPawns[i], i);
            pawns.push_back(pawn);
        }
        CRook rook1(color, whiteInitialPieces[0], 1);
        rooks.push_back(rook1);
        CKnight knight1(color, whiteInitialPieces[1], 1);
        knights.push_back(knight1);
        CBishop bishop1(color, whiteInitialPieces[2], 1);
        bishops.push_back(bishop1);
        CQueen queen(color, whiteInitialPieces[3], 1);
        queens.push_back(queen);
        CKing king(color, whiteInitialPieces[4], 1);
        kings.push_back(king);
        CRook rook2(color, whiteInitialPieces[5], 2);
        rooks.push_back(rook1);
        CKnight knight2(color, whiteInitialPieces[6], 2);
        knights.push_back(knight1);
        CBishop bishop2(color, whiteInitialPieces[7], 2);
        bishops.push_back(bishop1);
    }
    else            // Black player pieces.
    {
        this->turn = 0;     // White player starts playing.
        // Create eight pawns.
        for (int i = 0; i < 8; i++)
        {
            CPawn pawn(color, blackInitialPawns[i], i);
            pawns.push_back(pawn);
        }
        CRook rook1(color, blackInitialPieces[0], 1);
        rooks.push_back(rook1);
        CKnight knight1(color, blackInitialPieces[1], 1);
        knights.push_back(knight1);
        CBishop bishop1(color, blackInitialPieces[2], 1);
        bishops.push_back(bishop1);
        CQueen queen(color, blackInitialPieces[3], 1);
        queens.push_back(queen);
        CKing king(color, blackInitialPieces[4], 1);
        kings.push_back(king);
        CRook rook2(color, blackInitialPieces[5], 2);
        rooks.push_back(rook1);
        CKnight knight2(color, blackInitialPieces[6], 2);
        knights.push_back(knight1);
        CBishop bishop2(color, blackInitialPieces[7], 2);
        bishops.push_back(bishop1);
    }
}