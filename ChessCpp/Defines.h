#pragma once

using namespace std;

const string initialMessage = "Welcome to the chess program. Please, follow always the instructions on the screen as they appear.";
const string movementText = "Please, enter your movement : ";
const string newGame = "     1. Play a new game.";
const string exitApp = "     2. Exit app.";
const string resignMatch = "You lost due to ressignation.";
const string optionNumber = "Please, select an option by its number :";
const string endGame = "That was the end of the game...";
const string seeYou = "See you next time!!";

const char columns[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
const char rows[8] = { '1', '2', '3', '4', '5', '6', '7', '8' };

const char piecesC[6] = { 'p', 'R', 'N', 'B', 'Q', 'K'};
const string piecesDefault = "pRNBQK";

const int EMPTY = 0;
const int PAWN = 1;
const int ROOK = 2;
const int KNIGHT = 3;
const int BISHOP = 4;
const int QUEEN = 5;
const int KING = 6;

const int WHITE = 1;
const int BLACK = 2;
const int NONE = 2;