#include "CBoard.h"


/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CBoard::CBoard()
{
    initPlace();
    cout << "Board object has been created." << endl;       // Debugging purposes.
}

/// <summary>
/// Public destructor.
/// </summary>
CBoard::~CBoard()
{
    cout << "Board object has been destroyed." << endl;     // Debugging purposes.
}

/* PRIVATE methods of the class Board. */

/// <summary>
/// Method to places the initial position of the pieces on the board.
/// </summary>
void CBoard::initPlace()
{
    // Pawn rows.
    row2 = "2" + dSpace;
    row7 = "7" + dSpace;
    for (int i = 0; i < 8; i++)
    {
        row2 += "  pw" + dSpace;
        row7 += "  pb" + dSpace;
    }

    // Pieces rows.
    row1 = "1" + dSpace;
    row8 = "8" + dSpace;
    for (int i = 0; i < 8; i++)
    {
        row1 += "  " + whitePieces[i] + dSpace;
        row8 += "  " + blackPieces[i] + dSpace;
    }

    // Empty rows.
    row3 = "3  " + rowEmpty;
    row4 = "4  " + rowEmpty;
    row5 = "5  " + rowEmpty;
    row6 = "6  " + rowEmpty;
}



/* PUBLIC methods of the class Board. */

/// <summary>
/// Helper method to check if the way for a given movement is free or blocked. Need to be called for each intermediate position.
/// </summary>
/// <param name="position">Position to check.</param>
/// <returns>True if some intermediate position is occupied, False if free path.</returns>
bool CBoard::CheckPosition(string position)
{
    bool returned = false;

    for (int i = 0; sizeof(whitePositions); i++)
    {
        // Since both arrays have same size, we can compare at the same time.
        if (whitePositions[i] == position || BlackPositions[i] == position)
        {
            returned = true;
            break;              // As soon as one postition on the path is not free, it does not matter the status of the rest.
        }
        else
        {
            returned = false;
        }
    }
    return returned;
}

/// <summary>
/// Method to place all the pieces on the board before showing it, with the current informations.
/// </summary>
string CBoard::placePieces(string origin, string destination)
{
    /* To be populated with real code. */
    return "TOTO";
}

/// <summary>
/// Method to show the board with the current informations.
/// </summary>
void CBoard::showBoard(bool player)
{
    if (player)     // White player.
    {
        // Set the columns letter.
        cout << endl << colsWhite << endl;

        // Print out the board.
        cout << horizontal << endl << endl;
        cout << row8 << endl;
        cout << horizontal << endl << endl;
        cout << row7 << endl;
        cout << horizontal << endl << endl;
        cout << row6 << endl;
        cout << horizontal << endl << endl;
        cout << row5 << endl;
        cout << horizontal << endl << endl;
        cout << row4 << endl;
        cout << horizontal << endl << endl;
        cout << row3 << endl;
        cout << horizontal << endl << endl;
        cout << row2 << endl;
        cout << horizontal << endl << endl;
        cout << row1 << endl;
        cout << horizontal << endl << endl;
    }
    else            // Black player.
    {
        // Set the columns letter.
        cout << endl << colsBlack << endl;

        // Print out the board.
        cout << horizontal << endl << endl;
        cout << row1 << endl;
        cout << horizontal << endl << endl;
        cout << row2 << endl;
        cout << horizontal << endl << endl;
        cout << row3 << endl;
        cout << horizontal << endl << endl;
        cout << row4 << endl;
        cout << horizontal << endl << endl;
        cout << row5 << endl;
        cout << horizontal << endl << endl;
        cout << row6 << endl;
        cout << horizontal << endl << endl;
        cout << row7 << endl;
        cout << horizontal << endl << endl;
        cout << row8 << endl;
        cout << horizontal << endl << endl;
    }
}

