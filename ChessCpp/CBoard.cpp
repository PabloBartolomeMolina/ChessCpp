#include "CBoard.h"


/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CBoard::CBoard()
{
    initPlace();
    cout << "Board object has been created." << endl;
}

/// <summary>
/// Public destructor.
/// </summary>
CBoard::~CBoard()
{
    cout << "Board object has been desctructed." << endl;
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

/// <summary>
/// Method to place all the pieces on the board before showing it, with the current informations.
/// </summary>
void CBoard::placePieces()
{

}

/// <summary>
/// Method to show the board with the current informations.
/// </summary>
void CBoard::showBoard()
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