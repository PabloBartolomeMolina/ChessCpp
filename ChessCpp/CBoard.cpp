#include "CBoard.h"
#include "color.h"

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
    std::cout << "Board object has been created." << std::endl;       // Debugging purposes.
}

/// <summary>
/// Public destructor.
/// </summary>
CBoard::~CBoard()
{
    std::cout << "Board object has been destroyed." << std::endl;     // Debugging purposes.
}

/* PRIVATE methods of the class Board. */

/// <summary>
/// Method to places the initial position of the pieces on the board.
/// </summary>
void CBoard::initPlace()
{
    square[0][7].setPieceAndColor(ROOK, WHITE);
    square[1][7].setPieceAndColor(KNIGHT, WHITE);
    square[2][7].setPieceAndColor(BISHOP, WHITE);
    square[3][7].setPieceAndColor(QUEEN, WHITE);
    square[4][7].setPieceAndColor(KING, WHITE);
    square[5][7].setPieceAndColor(BISHOP, WHITE);
    square[6][7].setPieceAndColor(KNIGHT, WHITE);
    square[7][7].setPieceAndColor(ROOK, WHITE);

    square[0][0].setPieceAndColor(ROOK, BLACK);
    square[1][0].setPieceAndColor(KNIGHT, BLACK);
    square[2][0].setPieceAndColor(BISHOP, BLACK);
    square[3][0].setPieceAndColor(QUEEN, BLACK);
    square[4][0].setPieceAndColor(KING, BLACK);
    square[5][0].setPieceAndColor(BISHOP, BLACK);
    square[6][0].setPieceAndColor(KNIGHT, BLACK);
    square[7][0].setPieceAndColor(ROOK, BLACK);

    for (int i = 0; i < 8; i++) {
        square[i][1].setPieceAndColor(PAWN, BLACK);
        square[i][6].setPieceAndColor(PAWN, WHITE);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 2; j < 6; j++) {
            square[i][j].setPieceAndColor(EMPTY, NONE);
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            square[i][j].setX(i);
            square[i][j].setY(j);
        }
    }
}

/* PUBLIC methods of the class Board. */

/// <summary>
/// Helper method to check if the way for a given movement is free or blocked. Need to be called for each intermediate position.
/// </summary>
/// <param name="position">Position to check.</param>
/// <returns>True if some intermediate position is occupied, False if free path.</returns>
bool CBoard::CheckPosition(std::string position)
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
std::string CBoard::placePieces(std::string origin, std::string destination)
{
    /* To be populated with real code. */
    return "TOTO";
}

// Helper to print squares with proper background.
void printSquare(int indexParity, int piece, int color)
{
    int combiPiece = 0;

    switch (piece)
    {
    case KING: (color == WHITE) ? combiPiece = KING_WHITE : combiPiece = KING_BLACK;
        break;
    case QUEEN: (color == WHITE) ? combiPiece = QUEEN_WHITE : combiPiece = QUEEN_BLACK;
        break;
    case ROOK: (color == WHITE) ? combiPiece = ROOK_WHITE : combiPiece = ROOK_BLACK;
        break;
    case KNIGHT: (color == WHITE) ? combiPiece = KNIGHT_WHITE : combiPiece = KNIGHT_BLACK;
        break;
    case BISHOP: (color == WHITE) ? combiPiece = BISHOP_WHITE : combiPiece = BISHOP_BLACK;
        break;
    case PAWN: (color == WHITE) ? combiPiece = PAWN_WHITE : combiPiece = PAWN_BLACK;
        break;
    case EMPTY:
    default: combiPiece = EMPTY_NULL;
        break;
    }

    switch (indexParity)
    {
    case EVEN:
    case ODD:
        switch (combiPiece)
        {
        case KING_WHITE:
            std::cout << dye::black_on_white("K");
            break;
        case KING_BLACK:
            std::cout << dye::black_on_white("k");
            break;
        case QUEEN_WHITE:
            std::cout << dye::black_on_white("Q");
            break;
        case QUEEN_BLACK:
            std::cout << dye::black_on_white("q");
            break;
        case ROOK_WHITE:
            std::cout << dye::black_on_white("R");
            break;
        case ROOK_BLACK:
            std::cout << dye::black_on_white("r");
            break;
        case KNIGHT_WHITE:
            std::cout << dye::black_on_white("N");
            break;
        case KNIGHT_BLACK:
            std::cout << dye::black_on_white("n");
            break;
        case BISHOP_WHITE:
            std::cout << dye::black_on_white("B");
            break;
        case BISHOP_BLACK:
            std::cout << dye::black_on_white("b");
            break;
        case PAWN_WHITE:
            std::cout << dye::black_on_white("P");
            break;
        case PAWN_BLACK:
            std::cout << dye::black_on_white("p");
            break;
        case EMPTY_NULL:
        default:  std::cout << dye::black_on_white(" ");;
            break;
        }
        break;
    case DIFF: 
        switch (combiPiece)
        {
        case KING_WHITE:
            std::cout << dye::white_on_black("K");
            break;
        case KING_BLACK:
            std::cout << dye::white_on_black("k");
            break;
        case QUEEN_WHITE:
            std::cout << dye::white_on_black("Q");
            break;
        case QUEEN_BLACK:
            std::cout << dye::white_on_black("q");
            break;
        case ROOK_WHITE:
            std::cout << dye::white_on_black("R");
            break;
        case ROOK_BLACK:
            std::cout << dye::white_on_black("r");
            break;
        case KNIGHT_WHITE:
            std::cout << dye::white_on_black("N");
            break;
        case KNIGHT_BLACK:
            std::cout << dye::white_on_black("n");
            break;
        case BISHOP_WHITE:
            std::cout << dye::white_on_black("B");
            break;
        case BISHOP_BLACK:
            std::cout << dye::white_on_black("b");
            break;
        case PAWN_WHITE:
            std::cout << dye::white_on_black("P");
            break;
        case PAWN_BLACK:
            std::cout << dye::white_on_black("p");
            break;
        case EMPTY_NULL:
            std::cout << dye::white_on_black(" ");
            break;
        default: std::cout << dye::white_on_black(" ");
            break;
        }
        break;
    default:
        break;
    }
}

/// <summary>
/// Method to show the board with the current informations.
/// </summary>
void CBoard::showBoard(bool player)
{
    int indexParity= 0;

    if (player)     // White player.
    {
        // Set the columns letter.
        std::cout << std::endl << dye::black_on_aqua(colsWhite);
        std::cout << dye::black_on_aqua("    ") << std::endl;
        std::cout << dye::black_on_aqua("    ") << dye::black_on_aqua(horizontal);
        std::cout << dye::black_on_aqua("    ") << std::endl;

        // Print out the board.
        for (int i = 0; i < 8; i++)
        {
            std::cout << dye::black_on_aqua(" ") << dye::black_on_aqua(8-i) << dye::black_on_aqua("  ");

            if (i % 2 == 0)
            {
                std::cout << dye::black_on_aqua("|");
                std::cout << dye::black_on_white(" ");
            }
            else
            {
                std::cout << dye::black_on_aqua("|");
                std::cout << dye::white_on_black(" ");
            }

            for (int j = 0; j < 8; j++)
            {
                int p = square[j][i].getPiece();
                int c = square[j][i].getColor();

                if (i % 2 == 0 && j % 2 == 0)
                {
                    indexParity = EVEN;    // both even
                    std::cout << dye::black_on_white(" ");
                }
                else if (i % 2 == 1 && j % 2 == 1)
                {
                    indexParity = ODD;    // both odd
                    std::cout << dye::black_on_white(" ");
                }
                else
                {
                    indexParity = DIFF;    // one even and one odd
                    std::cout << dye::white_on_black(" ");
                }
                printSquare(indexParity, p, c);

                // After last square of the line, less space with black background.
                switch (indexParity)
                {
                case 0:
                case 1:
                    (j == 7) ? std::cout << dye::black_on_white("  ") << dye::black_on_aqua("|") : std::cout << dye::black_on_white("  ") << dye::black_on_aqua("|") << dye::white_on_black(" ");
                    break;
                case 2:
                    (j == 7) ? std::cout << dye::white_on_black("  ") << dye::black_on_aqua("|") : std::cout << dye::white_on_black("  ") << dye::black_on_aqua("|") << dye::black_on_white(" ");
                    break;
                default:
                    break;
                }
                
            }
            std::cout << dye::black_on_aqua("  ") << dye::black_on_aqua(8 - i) << dye::black_on_aqua(" ");
            std::cout << std::endl;
            std::cout << dye::black_on_aqua("    ") << dye::black_on_aqua(horizontal);
            std::cout << dye::black_on_aqua("    ");
            (i == 7) ? std::cout << "" : std::cout << std::endl;
        }
        // Letter for columns at the bottom of the board.
        std::cout << std::endl << dye::black_on_aqua(colsWhite);
        std::cout << dye::black_on_aqua("    ") << std::endl;
    }
    else            // Black player.
    {
        // Set the columns letter.
        std::cout << std::endl << dye::black_on_aqua(colsBlack);
        std::cout << dye::black_on_aqua("    ") << std::endl;
        std::cout << dye::black_on_aqua("    ") << dye::black_on_aqua(horizontal);
        std::cout << dye::black_on_aqua("    ") << std::endl;

        // Print out the board.
        for (int i = 0; i < 8; i++)
        {
            std::cout << dye::black_on_aqua(" ") << dye::black_on_aqua(i + 1) << dye::black_on_aqua("  ");
            if (i % 2 == 0)
            {
                std::cout << dye::black_on_aqua("|");
                std::cout << dye::black_on_white(" ");
            }
            else
            {
                std::cout << dye::black_on_aqua("|");
                std::cout << dye::white_on_black(" ");
            }

            for (int j = 0; j < 8; j++)
            {
                int p = square[j][i].getPiece();
                int c = square[j][i].getColor();

                if (i % 2 == 0 && j % 2 == 0)
                {
                    indexParity = EVEN;    // both even
                    std::cout << dye::black_on_white(" ");
                }
                else if (i % 2 == 1 && j % 2 == 1)
                {
                    indexParity = ODD;    // both odd
                    std::cout << dye::black_on_white(" ");
                }
                else
                {
                    indexParity = DIFF;    // one even and one odd
                    std::cout << dye::white_on_black(" ");
                }
                printSquare(indexParity, p, c);
                
                // After last square of the line, less space with black background.
                switch (indexParity)
                {
                case 0:
                case 1:
                    (j == 7) ? std::cout << dye::black_on_white("  ") << dye::black_on_aqua("|") : std::cout << dye::black_on_white("  ") << dye::black_on_aqua("|") << dye::white_on_black(" ");
                    break;
                case 2:
                    (j == 7) ? std::cout << dye::white_on_black("  ") << dye::black_on_aqua("|") : std::cout << dye::white_on_black("  ") << dye::black_on_aqua("|") << dye::black_on_white(" ");
                    break;
                default:
                    break;
                }
            }
            std::cout << dye::black_on_aqua("  ") << dye::black_on_aqua(i + 1) << dye::black_on_aqua(" ");
            std::cout << std::endl;
            std::cout << dye::black_on_aqua("    ") << dye::black_on_aqua(horizontal);
            std::cout << dye::black_on_aqua("    ");
            (i == 7) ? std::cout << "" : std::cout << std::endl;
        }
        // Letter for columns at the bottom of the board.
        std::cout << std::endl << dye::black_on_aqua(colsBlack);
        std::cout << dye::black_on_aqua("    ") << std::endl;
    }
}

/// <summary>
/// Method to get a given square given its indexes.
/// </summary>
/// <param name="x">Primary Index</param>
/// <param name="y">Secondary Index</param>
/// <returns></returns>
CSquare* CBoard::getSquare(int x, int y)
{
    return &square[x][y];
}

/// <summary>
///  Set values for a square given its indexes.
/// </summary>
/// <param name="sq">Square</param>
/// <param name="x">Primary Index</param>
/// <param name="y">Secondary Index</param>
void CBoard::setSquare(CSquare* sq, int x, int y)
{
    square[x][y] = *sq;
}