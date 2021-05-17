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

    // Check if player is moving a tower.
    if (movement[0] == 'T' || movement[0] == 't')
    {
        // Check if movement is possible for this piece.
        if (rooks[0].position[0] == move[0] || rooks[0].position[1] == move[1])         // Same row or same columns for the first ROOK.
            result = rooks[0].move(movement);
        else if (rooks[1].position[0] == move[0] || rooks[1].position[1] == move[1])    // Same row or same columns for the second ROOK.
            result = rooks[0].move(movement);
        else     // Movement is nos possible.
            result = false;
    }
    else if (movement[0] == 'N' || movement[0] == 'n')
    {

    }
    else if (movement[0] == 'B' || movement[0] == 'b')
    {

    }
    else if (movement[0] == 'Q' || movement[0] == 'q')
    {
        if (queens[0].position[0] == move[0] || queens[0].position[1] == move[1])       // Same row or same columns.
            result = queens[0].move(movement);
        /*else if (queens[1].position[0] == move[0] || queens[1].position[1] == move[1])    // Diagonal.
            result = queens[0].move(movement);*/
        else     // Movement is nos possible.
            result = false;
    }
    else if (movement[0] == 'K' || movement[0] == 'k')
    {
        kings[0].move(kings[0].position, move);
    }
    else if (movement[0] == 'P' || movement[0] == 'p')
    {
        for (int i = 0; i < 8; i++)
        {
            // Fisrt move may be simple or double (white pawn).
            if (((pawns[i].position[1] == (move[1] - 1)) || ((pawns[i].position[1] == (move[1] - 2)) && pawns[i].position[1] == '2')) && (this->color == 1))
            {
                if ((pawns[i].position[1] == (move[1] - 2)))
                    result = pawns[i].move(movement, 2);
                else
                    result = pawns[i].move(movement, 1);
            }
            // Fisrt move may be simple or double (black pawn).
            else if (((pawns[i].position[1] == (move[1] + 1)) || ((pawns[i].position[1] == (move[1] + 2)) && pawns[i].position[1] == '7')) && (this->color == 0))
            {
                if ((pawns[i].position[1] == (move[1] + 2)))
                    result = pawns[i].move(movement, 2);
                else
                    result = pawns[i].move(movement, 1);
            }  
            // Eat piece (white pawn).
            else if (((pawns[i].position[1] == (move[1] - 1)) && (this->color == 1) && ((pawns[i].position[0] == (move[0] - 1)) || pawns[i].position[0] == (move[0] - 1))))
            {
                result = pawns[i].move(movement, 3);
            }
            // Eat piece (black pawn).
            else if (((pawns[i].position[1] == (move[1] + 1)) && (this->color == 1) && ((pawns[i].position[0] == (move[0] + 1)) || pawns[i].position[0] == (move[0] - 1))))
            {
                result = pawns[i].move(movement, 3);
            }
            else     // Movement is nos possible.
                result = false;
        }
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