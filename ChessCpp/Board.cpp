#include "Board.h"

class Board
{
private:
    char piecePlacement[8] = {};
    /* Two pieces of each type, following the next code:
     * b = black piece   //   w = white piece 
     * p = pawn   //   R = Rook   //  N = Knight
     * B = Bishop   //   Q = Queen   //  K = King */
    string pieces[12] = { "pw", "pb", "Rw", "Rb", "Nw", "Nb", "Bw", "Bb", "Qw", "Qb", "Kw", "Kb" };

public:
    // Public constructor to set up basic elements of the Board objects.
    Board()
    {
        cout << "Board object has been created." << endl;
    }

    // Public destructor.
    ~Board()
    {
        cout << "Board object has been desctructed." << endl;
    }
};