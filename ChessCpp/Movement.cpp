#include "Movement.h"

/// <summary>
/// Function to receive the movement of the users. A check is launched for the format.
/// </summary>
/// <returns>
/// Returns TRUE if all good and FALSE if some issues found.
/// </returns>
std::string * Movement()
{
    bool res = false;
    std::string *result = NULL;
    bool checked = false;
    std::string move = "dummy";

    while (!res)
    {
       std::cout << "Please, insert your movement: ";
       std::cin >> move;

        checked = check_input(move);
    }
    if (move == "0-0" || move == "0-0-0") {
        result[0] = "Roque";    // Indicates movement is a roque.
        result[0] = move;       // Indicates if short or long roque.
    }        
    else {
        if (isalpha(move[0]) && isupper(move[0])) {
            result[0] = move[0];    // Indicates piece moving.
            if (move[1] == 'x')
                result[1] = move[1];
            else
                result[1] = move.substr(1, 2);  // Copy destination place.
        }
        else {
            result[0] = "pawn"; // Indicates the piece moving is a pawn.
            if (move[1] == 'x')
                result[1] = move[1];
            else
                result[1] = move.substr(1, 2);  // Copy destination place.
        }
    }
        
	return result;
}


/// <summary>
/// Check the format of the user's input according to international notation system. No check of feasibility of the movement is done here.
/// </summary>
/// <param name="move">
/// As parameter, we receive in the function the user's input.
/// </param>
/// <returns>
/// Returns TRUE if all good and FALSE if some issues found.
/// </returns>
bool check_input(std::string &move)
{
    bool ok = false;

    // Remove whote spaces from user's input to simplify checking the strings.
    // Letters to Uppercase or Lowercase depending on which letter we find in the string.
    move.erase(remove_if(move.begin(), move.end(), isspace), move.end());
    for (unsigned int i = 0; i < move.size(); i++)
    {
        if ((move[i] >= 'a' && move[i] <= 'z') || (move[i] >= 'A' && move[i] <= 'Z'))
            move[i] = tolower(move[i]);
        if (move[i] == 'x' || move[i] == 'X')
            move[i] = tolower(move[i]);
    }
    for (unsigned int i = 0; i < move.size(); i++)
    {
        // Letter of pieces is done separately to ensure it is set to Uppercase.
        if ((move[i] == 'k' || move[i] == 'q' || move[i] == 'r' || move[i] == 'n' || move[i] == 'b') && (move[i + 1] >= 'a' && move[i + 1] <= 'h'))
            move[i] = toupper(move[i]);
    }

    if (move.length() == 2 && isalpha(move[0]) && isdigit(move[1]))
    {
        // If length is 2, it can only be a pawn moving. Format must be LETTER - NUMBER.
        // Check if notation is according to the places in the board.
        if (move[0] >= 'a' && move[0] <= 'h' && move[1] >= '1' && move[1] <= '8')
            ok = true;
        else
            ok = false;
        // Need to add the check to at the piece at the destination.
        // Need to add the check of the path possibility.
    }
    else if (move.length() == 3 && isalpha(move[0]) && isalpha(move[1]) && isdigit(move[2]))
    {
        // If lenght is 3, it includes one piece. Make capital the letter of the piece.
        // Format neeeds to be LETTER - LETTER - NUMBER
        // Check if notation is according to the places in the board.
        if (move[1] >= 'a' && move[1] <= 'h' && move[2] >= '1' && move[2] <= '8')
            // Check if notation is according to the pieces abbreviations.
            if (move[0] == 'K' || move[0] == 'Q' || move[0] == 'R' || move[0] == 'N' || move[0] == 'B')
                ok = true;
        else
            ok = false;
        
        // Need to add the check to at the piece at the destination.
        // Need to add the check of the path possibility.
    }
    else if (move.length() == 4 && isalpha(move[0]) && (move[1] == 'x' || move[1] == 'X') && isalpha(move[2]) && isdigit(move[3]))     // Eat a piece.
    {
        // Format neeeds to be LETTER - x - LETTER - NUMBER

        // Check if notation is according to the places in the board.
        if (move[1] >= 'a' && move[1] <= 'h' && move[3] >= '1' && move[3] <= '8' && move[2] == 'x')
            ok = true;
        else
            ok = false;
        // Check if notation is according to the pieces abbreviations.
        if (move[0] == 'K' || move[0] == 'Q' || move[0] == 'R' || move[0] == 'N' || move[0] == 'B')
            ok = true;
        else
            ok = false;

        // Need to add the check to at the piece at the destination.
        // Need to add the check of the path possibility.
    }
    else if (move.length() == 5 && isalpha(move[0]) && isdigit(move[1]) && (move[2] == 'x' || move[1] == '2') && isalpha(move[3]) && isdigit(move[4]))     // Pawn eats a piece.
    {
        // Format neeeds to be LETTER - x - LETTER - NUMBER

        // Check if notation is according to the places in the board.
        if (move[0] >= 'a' && move[0] <= 'h' && move[1] >= '1' && move[1] <= '8' && move[3] >= 'a' && move[3] <= 'h' && move[4] >= '1' && move[4] <= '8')
            ok = true;
        else
            ok = false;
        // Check if notation is according to the pieces abbreviations and letter to eat is correct.
        if (move[0] == 'K' || move[0] == 'Q' || move[0] == 'R' || move[0] == 'N' || move[0] == 'B' && move[2] == 'x')
            ok = true;
        else
            ok = false;

        // Need to add the check to at the piece at the destination.
        // Need to add the check of the path possibility.
    }
    else if (move == "0-0" || move == "O-O")     // Short roque.
    {
        // Standarize the input for roque.
        if (move == "O-O")
            move = "0-0";
        ok = true;

        // Need to add the check to at the piece at the destination.
        // Need to add the check of the path possibility.
        // Need to check if rook and king already moved before.
    }
    else if (move == "0-0-0" || move == "O-O-O")     // Long roque.
    {
        move = "0-0-0";
        ok = true;

        // Need to add the check to at the piece at the destination.
        // Need to add the check of the path possibility.
        // Need to check if rook and king already moved before.
    }
    else if (move.length() == 4 && isalpha(move[0]) && isalpha(move[1]) && isdigit(move[2]) && move[3] == '+')     // Move and check.
    {
        // Format neeeds to be LETTER - x - LETTER - NUMBER

        // Check  if notation is according to the places in the board.
        if (move[1] >= 'a' && move[1] <= 'h' && move[2] >= '1' && move[2] <= '8' && move[3] == '+')
            ok = true;
        else
            ok = false;
        // Check if notation is according to the pieces abbreviations.
        if (move[0] == 'K' || move[0] == 'Q' || move[0] == 'R' || move[0] == 'N' || move[0] == 'B')
            ok = true;
        else
            ok = false;

        // Need to add the check to at the piece at the destination.
        // Need to add the check of the path possibility.
    }
    else if (move.length() == 3 && isalpha(move[0]) && isdigit(move[1]) && move[2] == '+')     // Move pawn and check.
    {
        // Format neeeds to be LETTER - NUMBER - +
        move[0] = tolower(move[0]);

        // Check if notation is according to the places in the board.
        if (move[0] >= 'a' && move[0] <= 'h' && move[1] >= '1' && move[1] <= '8' && move[2] == '+')
            ok = true;
        else
            ok = false;

        // Need to add the check to at the piece at the destination.
        // Need to add the check of the path possibility.
    }
    else if (move.length() == 5 && isalpha(move[0]) && (move[1] == 'x' || move[1] == 'X') && isalpha(move[2]) && isdigit(move[3]) && move[4] == '+') // Eat a piece and check.
    {
        // Format neeeds to be LETTER - x - LETTER - NUMBER - +
        
        // Check if notation is according to the places in the board.
        if (move[2] >= 'a' && move[2] <= 'h' && move[3] >= '1' && move[3] <= '8' && move[1] == 'x' && move[4] == '+')
            ok = true;
        else
            ok = false;
        // Check if notation is according to the pieces abbreviations.
        if (move[0] == 'K' || move[0] == 'Q' || move[0] == 'R' || move[0] == 'N' || move[0] == 'B')
            ok = true;
        else
            ok = false;

        // Need to add the check to at the piece at the destination.
        // Need to add the check of the path possibility.
    }
    else if (move.length() == 6 && isalpha(move[0]) && isdigit(move[1]) && (move[2] == 'x' || move[3] == '2') && isalpha(move[3]) && isdigit(move[4]) && move[5] == '+') // Eat a piece and check, with a pawn.
    {
    // Format neeeds to be LETTER - x - LETTER - NUMBER - +

    // Check if notation is according to the places in the board.
    if (move[0] >= 'a' && move[0] <= 'h' && move[1] >= '1' && move[1] <= '8' && move[2] == 'x' && move[5] == '+')
        ok = true;
    else
        ok = false;
    // Check if notation is according to the places in the board.
    if (move[3] >= 'a' && move[3] <= 'h' && move[4] >= '1' && move[4] <= '8')
        ok = true;
    else
        ok = false;

    // Need to add the check to at the piece at the destination.
    // Need to add the check of the path possibility.
    }
    else
    {
        // Do nothing, the format is not good and the user needs to insert another movement.
        
    }

    // Print message according to results of the checks.
    if (ok)
       std::cout << std::endl << "Movement: " << move << std::endl;
    else
       std::cout << std::endl << "Format of the movement is no correct, please insert a valid one..." << std::endl;

    return ok;
}