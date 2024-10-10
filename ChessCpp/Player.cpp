#include "Player.h"

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
Player::Player(bool input)
{
    color = input;  // Set attribute for the current instance.
    // Set color of instance.
    if (color)
    {
       std::cout << "Player white has been created." << std::endl;
        createPieces(1);
        turn = 1;   // First move is for white player.
    } 
    else
    {
       std::cout << "Player black has been created." << std::endl;
        createPieces(0);
    }
}

/// <summary>
/// Public destructor.
/// </summary>
Player::~Player()
{
    
    if (color)
       std::cout << "Player white has been destroyed." << std::endl;
    else
       std::cout << "Player black has been destroyed." << std::endl;
}

/// <summary>
/// Helper for move method.
/// </summary>
bool Player::CheckMove(std::string movement)
{
    bool result = false;

    return result;
}

/// <summary>
/// Check if destination is occupied by a piece of the same player.
/// </summary>
/// <param name="movement">Destination case.</param>
/// <returns></returns>
bool Player::CheckOccupied(std::string movement)
{
    bool occupied = false;
    
    return occupied;
}

/// <summary>
/// // Check possibility of roque movement.
/// </summary>
/// <param name="movement">Short or long roque</param>
/// <returns></returns>
bool Player::checkRoque(std::string movement)
{
    bool result = false;

    return result;
}

// Vector to allocate the return values.
std::vector<std::string> movement{ "origin", "destination" };

/// <summary>
/// Method to perform a move.
/// </summary>
std::vector<std::string> Player::Move()
{
    std::string move = "none";   // String to allocate input movement of player.
    bool ok = false;    // Control flag for validity of movement. It helps to control logic of the function.

    while (!ok)
    {
       std::cout << movementText;
       std::cin >> move;
        
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
           std::cout << "Invalid format." << std::endl;
        }

        if (ok)
           std::cout << "OKey" << std::endl;
        else
           std::cout << "Something strange happening" << std::endl;
    }

   std::cout << "Movement is considered" << std::endl << std::endl;
   std::cout << movement[1] << std::endl;
    system("pause");

    return movement;
}

/* PRIVATE methods of the class Player. */

/// <summary>
/// Helper to simmplify Move method by checking in here the notation of the destination.
/// </summary>
/// <param name="movement">Movement that is given by the player</param>
/// <returns></returns>
bool Player::checkDestination(std::string move)
{
    bool ok = false;
    /* Check notation for the case of destination. */
    if (move[1] >= 'a' && move[1] <= 'h' && move[2] >= '1' && move[2] <= '8')
    {
        /* Only possible if the notation of the piece is valid. */
        ok = true;
        movement[1].assign(move.substr(1, 2));      // Take just the final position to be returned as a destination.
       std::cout << "Movement is consideredDD" << std::endl;
    }
    else
    {
        /* Either the notation for the position is false or we already knew that the notation for the piece was not good. */
        ok = false;
    }

    return ok;
}

/// <summary>
/// Helper to simmplify Move method by checking in here the notation of the piece.
/// </summary>
/// <param name="movement">Movement that is given by the player</param>
/// <returns></returns>
bool Player::checkPiece(std::string move)
{
    bool ok = false;    // Control flag for validity of movement. It helps to control logic of the function.

    for (unsigned int i = 0; i < piecesDefault.length(); ++i)
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
/// Method to create the proper pieces when player instance is created.
/// </summary>
/// <param name="color"></param>
void Player::createPieces(bool color)
{
}