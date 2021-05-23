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
/// Helper for move method.
/// </summary>
bool CPlayer::CheckMove(string movement)
{
    bool result = false;
    string move = movement.substr(1, 2);  // Get the displacement.

    if ((move[0] >= 'a' && move[0] <= 'h') && (move[1] >= '1' && move[8] <= '8'))
    {
        // Move is in the expected ranges for columns and rows, so continue wuth the checkings.
        result = true;

        // Check if movement can be done according to the type of piece to be moved.
        switch (movement[0])
        {
        case 'P':
            break;
        case 'R':
            break;
        case 'N':
            break;
        case 'B':
            break;
        case 'Q':
            break;
        case 'K':
            kings[0].move(kings[0].position, move);
            break;
        default:
            // Piece is not valid.
            result = false;
            break;
        }
    }
    else
    {
        // Move is in outside the expected ranges for columns and rows.
        result = false;
    }

    return result;
}

/// <summary>
/// Method to perform a move.
/// </summary>
string CPlayer::Move()
{
    string move = " ";
    while (1)
    {
        cout << movement;
        cin >> move;
        // Ensrure standard notation for movement input.
        move[0] = toupper(move[0]);
        move[1] = toupper(move[1]); 
        // Check movement validity.
        bool ok = CheckMove(move);
        if (ok)
        {
            move = "Check for intermediate way.";
            break;
        }
    }

    return move;
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