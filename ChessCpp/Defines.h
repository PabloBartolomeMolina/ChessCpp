#pragma once

const  std::string initialMessage = "Welcome to the chess program. Please, follow always the instructions on the screen as they appear.";
const  std::string movementText = "Please, enter your movement : ";
const  std::string newGame = "     1. Play a new game.";
const  std::string exitApp = "     2. Exit app.";
const  std::string resignMatch = "You lost due to ressignation.";
const  std::string optionNumber = "Please, select an option by its number :";
const  std::string endGame = "That was the end of the game...";
const  std::string seeYou = "See you next time!!";

const char columns[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
const char rows[8] = { '1', '2', '3', '4', '5', '6', '7', '8' };

const char piecesC[6] = { 'p', 'R', 'N', 'B', 'Q', 'K'};
const  std::string piecesDefault = "pRNBQK";

// Defines for pieces
const int EMPTY = 0;
const int PAWN = 1;
const int ROOK = 2;
const int KNIGHT = 3;
const int BISHOP = 4;
const int QUEEN = 5;
const int KING = 6;

// Defines for colors
const int WHITE = 1;
const int BLACK = 2;
const int NONE = 2;

// Defines for pieces with colors
const int KING_WHITE = 0;
const int KING_BLACK = 1;
const int QUEEN_WHITE = 2;
const int QUEEN_BLACK = 3;
const int ROOK_WHITE = 4;
const int ROOK_BLACK = 5;
const int KNIGHT_WHITE = 6;
const int KNIGHT_BLACK = 7;
const int BISHOP_WHITE = 8;
const int BISHOP_BLACK = 9;
const int PAWN_WHITE = 10;
const int PAWN_BLACK = 11;
const int EMPTY_NULL = 12;