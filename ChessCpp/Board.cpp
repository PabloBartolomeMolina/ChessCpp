#include "Board.h"


/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
Board::Board()
{
    cout << "Board object has been created." << endl;
}

/// <summary>
/// Public destructor.
/// </summary>
Board::~Board()
{
    cout << "Board object has been desctructed." << endl;
}

/* PRIVATE methods of the class Board. */

/// <summary>
/// Method to place all the pieces on the board before showing it, with the current informations.
/// INPUT Paramenters:
///     * bool initial - When set to TRUE, it indicates if the initial position should be set up. Else, we need to check other informations.
/// </summary>
void placePieces(bool initial)
{
    if (initial)
    {
        /* Initial position. */
    }
    else
    {
        /* Position after a movement. */
    }
}

/// <summary>
/// Method to show the board with the current informations.
/// </summary>
void Board::showBoard()
{
    for (int r = 0; r < 8; r++)
    {
        if (r != 7)
        {
            cout << "    _____ _____ _____ _____ _____ _____ _____ _____ " << endl << endl;
            cout << r + 1 << "  |     |     |     |     |     |     |     |     |" << endl;
        }
        else 
        {
            cout << "    _____ _____ _____ _____ _____ _____ _____ _____ " << endl << endl;
            cout << r + 1 << "  |     |     |     |     |     |     |     |     |" << endl;
            cout << "    _____ _____ _____ _____ _____ _____ _____ _____ " << endl << endl;
        }


        for (int c = 0; c < 8; c++)
        {

        }
    }
}