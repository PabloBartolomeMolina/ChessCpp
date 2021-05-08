#include "Board.h"


/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
Board::Board()
{
    /* Two pieces of each type, following the next code:
    * b = black piece   //   w = white piece
    * p = pawn   //   R = Rook   //  N = Knight
    * B = Bishop   //   Q = Queen   //  K = King */
    string pieces[12] = { "pw", "pb", "Rw", "Rb", "Nw", "Nb", "Bw", "Bb", "Qw", "Qb", "Kw", "Kb" };
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

}