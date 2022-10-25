#include "CBoard.h"


/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CBoard::CBoard()
{
    initPlace();

    int pieces[64] = {
        ROOK,  KNIGHT,BISHOP,QUEEN, KING,  BISHOP,KNIGHT,ROOK,
        PAWN,  PAWN,  PAWN,  PAWN,  PAWN,  PAWN,  PAWN,  PAWN,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        PAWN,  PAWN,  PAWN,  PAWN,  PAWN,  PAWN,  PAWN,  PAWN,
        ROOK,  KNIGHT,BISHOP,QUEEN, KING,  BISHOP,KNIGHT,ROOK
    };

    int color[64] = {
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
        WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE
    };

    board_index board[64]{
         {0, "a8"}, {1, "b8"}, {2, "c8"}, {3, "d8"}, {4, "e8"}, {5, "f8"}, {6, "g8"}, {7, "h8"},
         {8, "a7"}, {9, "b7"}, {10, "c7"}, {11, "d7"}, {12, "e7"}, {13, "f7"}, {14, "g7"}, {15, "h7"},
         {16, "a6"}, {17, "b6"}, {18, "c6"}, {19, "d6"}, {20, "e6"}, {21, "f6"}, {22, "g6"}, {23, "h6"},
         {24, "a5"}, {25, "b5"}, {26, "c5"}, {27, "d5"}, {28, "e5"}, {29, "f5"}, {30, "g5"}, {31, "h5"},
         {32, "a4"}, {33, "b4"}, {34, "c4"}, {35, "d4"}, {36, "e4"}, {37, "f4"}, {38, "g4"}, {39, "h4"},
         {40, "a3"}, {41, "b3"}, {42, "c3"}, {43, "d3"}, {44, "e3"}, {45, "f3"}, {46, "g3"}, {47, "h3"},
         {48, "a2"}, {49, "b2"}, {50, "c2"}, {51, "d2"}, {52, "e2"}, {53, "f2"}, {54, "g2"}, {55, "h2"},
         {56, "a1"}, {57, "b1"}, {58, "c1"}, {59, "d1"}, {60, "e1"}, {61, "f1"}, {62, "g1"}, {63, "h1"},
    };
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

    int pieces[64] = {
        ROOK,  KNIGHT,BISHOP,QUEEN, KING,  BISHOP,KNIGHT,ROOK,
        PAWN,  PAWN,  PAWN,  PAWN,  PAWN,  PAWN,  PAWN,  PAWN,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        PAWN,  PAWN,  PAWN,  PAWN,  PAWN,  PAWN,  PAWN,  PAWN,
        ROOK,  KNIGHT,BISHOP,QUEEN, KING,  BISHOP,KNIGHT,ROOK
    };

    int color[64] = {
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
        WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE
    };

    board_index board[64]{
         {0, "a8"}, {1, "b8"}, {2, "c8"}, {3, "d8"}, {4, "e8"}, {5, "f8"}, {6, "g8"}, {7, "h8"},
         {8, "a7"}, {9, "b7"}, {10, "c7"}, {11, "d7"}, {12, "e7"}, {13, "f7"}, {14, "g7"}, {15, "h7"},
         {16, "a6"}, {17, "b6"}, {18, "c6"}, {19, "d6"}, {20, "e6"}, {21, "f6"}, {22, "g6"}, {23, "h6"},
         {24, "a5"}, {25, "b5"}, {26, "c5"}, {27, "d5"}, {28, "e5"}, {29, "f5"}, {30, "g5"}, {31, "h5"},
         {32, "a4"}, {33, "b4"}, {34, "c4"}, {35, "d4"}, {36, "e4"}, {37, "f4"}, {38, "g4"}, {39, "h4"},
         {40, "a3"}, {41, "b3"}, {42, "c3"}, {43, "d3"}, {44, "e3"}, {45, "f3"}, {46, "g3"}, {47, "h3"},
         {48, "a2"}, {49, "b2"}, {50, "c2"}, {51, "d2"}, {52, "e2"}, {53, "f2"}, {54, "g2"}, {55, "h2"},
         {56, "a1"}, {57, "b1"}, {58, "c1"}, {59, "d1"}, {60, "e1"}, {61, "f1"}, {62, "g1"}, {63, "h1"},
    };
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

