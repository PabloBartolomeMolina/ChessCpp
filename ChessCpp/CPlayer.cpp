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
    
    if (color)
        cout << "Player white has been destroyed." << endl;
    else
        cout << "Player black has been destroyed." << endl;
}

/// <summary>
/// Check if destination is occupied by a piece of the same player.
/// </summary>
/// <param name="movement">Destination case.</param>
/// <returns></returns>
bool CPlayer::CheckOccupied(string movement)
{
    bool occupied = false;
    
    // Check if queen or king are in that position.
    if (kings[0].position == movement || queens[0].position == movement)
    {
        occupied = true;
    }

    // Check if a rook, a knight or a bishop are in that position.
    for (int i = 0; i < 2; i++)
    {
        // If already one piece is in the objective case, it is not needed to keep checking.
        if (occupied)
            break;

        if (rooks[i].position == movement || knights[i].position == movement || bishops[i].position == movement)
        {
            occupied = true;
            break;
        }
    }

    // Check if a pawn is in that position.
    for (int i = 0; i < 8; i++)
    {
        // If already one piece is in the objective case, it is not needed to keep checking.
        if (occupied)
            break;
        if (pawns[i].position == movement)
        {
            occupied = true;
            break;
        }
    }

    return occupied;
}

/// <summary>
/// Helper for move method.
/// </summary>
bool CPlayer::CheckMove(string movement)
{
    bool result = false;
    string move = movement;     // Use local variable.

    // First, check if the destination is already occupied by a piece of the same player.
    bool occupied = CheckOccupied(move);

    if (!occupied)      // Not occupied by a piece of the same player.
    {
        // Check if movement can be done according to the type of piece to be moved. If possible, the movement will be done.
        switch (movement[0])
        {
        case 'p':
            for (int i = 0; i < 8; i++)
            {
                result = pawns[i].move(pawns[i].position, move);
                if (result)
                    break;
            }
            break;
        case 'R':
            for (int i = 0; i < 2; i++)
            {
                result = rooks[i].move(rooks[i].position, move);
                if (result)
                    break;
            }
            break;
        case 'N':
            for (int i = 0; i < 2; i++)
            {
                result = knights[i].move(knights[i].position, move);
                if (result)
                    break;
            }
            break;
        case 'B':
            for (int i = 0; i < 2; i++)
            {
                result = bishops[i].move(bishops[i].position, move);
                if (result)
                    break;
            }
            break;
        case 'Q':
            queens[0].move(queens[0].position, move);
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
        // Destination is already occupied by a piece of the same player.
        result = false;
    }

    return result;
}

/// <summary>
/// // Check possibility of roque movement.
/// </summary>
/// <param name="movement">Short or long roque</param>
/// <returns></returns>
bool CPlayer::checkRoque(string movement)
{
    bool result = false;
    string move = "";
    // Normalice notation.
    for (char& c : movement) {
        if (c == 'o' || c == 'O')       // Left only version with 0 (zeros).
            move += '0';
        else if (c == '-')
            move += '-';   // Erase empty spaces.
    }

    /* Once format it standarized, need to check if king has already moved before or not. */
    result = kings[0].firstMovement();

    /* Only if king has not yet moved, we check if the corresponding tower has already moved before or not. */
    if (result)
    {
        result = rooks[0].firstMovement(move, this->color);
        if (!result)    // If the first rook is not good, check the second one.
            result = rooks[1].firstMovement(move, this->color);
    }
    else
    {
        result = false;
    }

    /* Only if both pieces are still on place, we will check the free way to proceed with the movement. */
    if (result)
    {
        /* Proceed. */

    }
    else {
        /* NOPE */
    }

    return result;
}

vector<string> movement{ "origin", "destination" };   // Vector to allocate the return values.

/// <summary>
/// Method to perform a move.
/// </summary>
vector<string> CPlayer::Move()
{
    string move = "none";   // String to allocate input movement of player.
    bool ok = false;    // Control flag for validity of movement. It helps to control logic of the function.

    while (!ok)
    {
        cout << movementText;
        cin >> move;
        
        // Check if format is correct.
        if (move.length() == 3 && isalpha(move[0]) && isalpha(move[1]) && isdigit(move[2]))     // Simple move.
        {
            // Ensrure standard notation for movement input.
            ok = checkPiece(move);

            if (ok)
            {
                /* The notation of the case is always in lowercase. Conversion is done before validity check to facilitate the comparison. */
                move[1] = tolower(move[1]);
                ok = checkDestination(move.substr(1, 2));   // Pass just the destination.

                /* UP TO HERE, THE OPTIMAL IMPLEMENTATION IS DONE. NEED TO CHECK THE REST TO OPTIMIZE IT. */

                /* Now, it depends on the piece to move to check if it is possible to make the movement or not. */

                // Check movement validity.
                if (ok)
                {
                    ok = CheckMove(move);
                    move = "Check for intermediate way.";
                    break;
                }
            }
            else
            {
                // Since piece is not valid, it does not make sense to continue checkings.
            }
        }
        else if (move.length() == 4 && isalpha(move[0]) && (move[1] == 'x' || move[1] == 'X') && isalpha(move[2]) && isdigit(move[3]))     // Eat a piece.
        {
            // Ensrure standard notation for movement input.
            ok = checkPiece(move);

            if (ok)
            {
                /* The notation for eating a piece is always lowercase. */
                move[1] = tolower(move[1]);
                /* The notation of the case is always in lowercase. Conversion is done before validity check to facilitate the comparison. */
                move[2] = tolower(move[2]);
                ok = checkDestination(move.substr(2, 2));   // Pass just the destination.

                // Check movement validity.
                ok = CheckMove(move);
                if (ok)
                {
                    move = "Check for intermediate way.";
                    break;
                }
            }
            else
            {
                // Since piece is not valid, it does not make sense to continue checkings.
            }
        }
        else if (move.length() == 4 && isalpha(move[0]) && isalpha(move[1]) && isdigit(move[2]) && move[3] == '+')     // Move and check.
        {
            // Ensrure standard notation for movement input.
            ok = checkPiece(move);

            if (ok)
            {
                /* The notation of the case is always in lowercase. Conversion is done before validity check to facilitate the comparison. */
                move[1] = tolower(move[1]);
                ok = checkDestination(move.substr(1, 2));   // Pass just the destination.

                // Check movement validity.
                ok = CheckMove(move);
                if (ok)
                {
                    move = "Check for intermediate way.";
                    break;
                }
            }
            else
            {
                // Since piece is not valid, it does not make sense to continue checkings.
            }
        }
        else if (move.length() == 5 && isalpha(move[0]) && (move[1] == 'x' || move[1] == 'X') && isalpha(move[2]) && isdigit(move[3]) && move[4] == '+') // Eat a piece and check.
        {
            // Ensrure standard notation for movement input.
            ok = checkPiece(move);

            if (ok)
            {
                /* The notation for eating a piece is always lowercase. */
                move[1] = tolower(move[1]);
                /* The notation of the case is always in lowercase. Conversion is done before validity check to facilitate the comparison. */
                move[2] = tolower(move[2]);
                ok = checkDestination(move.substr(2, 2));   // Pass just the destination.

                // Check movement validity.
                ok = CheckMove(move);
                if (ok)
                {
                    move = "Check for intermediate way.";
                    break;
                }
            }
            else
            {
                // Since piece is not valid, it does not make sense to continue checkings.
            }
        }
        else if (move == "0 - 0" || move == "0-0" || move == "O - O" || move == "O-O")     // Short roque.
        {
            // Ensrure standard notation for movement input.
            // No need to check piece notation, since no piece is indicated.

            // Check possility or roque.
            ok = checkRoque(move);
        }
        else if (move == "0 - 0 - 0" || move == "0-0-0" || move == "O - O - O" || move == "O-O-O")     // Long roque.
        {
            // Ensrure standard notation for movement input.
            // No need to check piece notation, since no piece is indicated.

            // Check possility or roque.
            ok = checkRoque(move);
        }
        else
        {
            /* Format is not valid. */
            ok = false;
            cout << "Invalid format." << endl;
        }

        if (ok)
            cout << "OKey" << endl;
        else
            cout << "Something strange happening" << endl;
    }

    cout << "Movement is considered" << endl << endl;
    cout << movement[1] << endl;
    system("pause");

    return movement;
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

/// <summary>
/// Helper to simmplify Move method by checking in here the notation of the piece.
/// </summary>
/// <param name="movement">Movement that is given by the player</param>
/// <returns></returns>
bool CPlayer::checkPiece(string move)
{
    bool ok = false;    // Control flag for validity of movement. It helps to control logic of the function.

    for (int i = 0; i < piecesDefault.length(); ++i)
    {
        /* Check notation for the piece*/
        if (toupper(move[0]) == toupper(piecesDefault[i]))      // toUpper helps to compare two chars quicker with a cleaner code.
        {
            switch (move[0])
            {
            case 'p':
            case 'P':
                move[0] = tolower(move[0]);     // Pawn notation is in lowercase.
                ok = true;  // It can retake FALSE value if the notation of the case of destination is not good.
                break;
            case 'r':
            case 'R':
            case 'n':
            case 'N':
            case 'b':
            case 'B':
            case 'q':
            case 'Q':
            case 'k':
            case 'K':
                move[0] = toupper(move[0]);     // Notation for these pieces is in uppercase.
                ok = true;  // It can retake FALSE value if the notation of the case of destination is not good.
                break;
            default:        // Not a valid piece, safety case. Normally, this will go in the ELSE.
                ok = false;
                break;
            }
        }
        else
        {
            /* Letter is not valid.*/
            ok = false;
        }
    }

    return ok;
}

/// <summary>
/// Helper to simmplify Move method by checking in here the notation of the destination.
/// </summary>
/// <param name="movement">Movement that is given by the player</param>
/// <returns></returns>
bool CPlayer::checkDestination(string move)
{
    bool ok = false;
    /* Check notation for the case of destination. */
    if (move[1] >= 'a' && move[1] <= 'h' && move[2] >= '1' && move[2] <= '8')
    {
        /* Only possible if the notation of the piece is valid. */
        ok = true;
        movement[1].assign(move.substr(1, 2));      // Take just the final position to be returned as a destination.
        cout << "Movement is consideredDD" << endl;
    }
    else
    {
        /* Either the notation for the position is false or we already knew that the notation for the piece was not good. */
        ok = false;
    }

    return ok;
}