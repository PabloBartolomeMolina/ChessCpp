#pragma once

#include <iostream>
#include <vector>
#include "Defines.h"
#include "CPawn.h"
#include "CRook.h"
#include "CKnight.h"
#include "CBishop.h"
#include "CQueen.h"
#include "CKing.h"

class CPlayer
{
private:
	// 0 for black color and 1 for white color.
	bool color = 0;
	// 0 for no turn of movement and 1 for turn of movement.
	bool turn = 0;
	// By default it is for black pieces, to be changed if needed at creation of object.
	std::string pieces[8] = { "Rb", "Nb", "Bb", "Qb", "Kb", "Bb", "Nb", "Rb" };
	std::string whiteInitialPawns[8] = { "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2"};
	std::string whiteInitialPieces[8] = { "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1" };
	std::string blackInitialPawns[8] = { "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7" };
	std::string blackInitialPieces[8] = { "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8" };

	std::vector<CRook> rooks;
	std::vector<CKnight> knights;
	std::vector<CBishop> bishops;
	std::vector<CQueen> queens;
	std::vector<CKing> kings;

	// Creation of pieces.
	void createPieces(bool color = 0);
	// Check notation if destination.
	bool checkDestination(std::string move);
	// Check movement.
	bool CheckMove(std::string movement);
	// Check destination before moving.
	bool CheckOccupied(std::string movement);
	// Check notation if piece.
	bool checkPiece(std::string move);
	// Check possibility of roque movement.
	bool checkRoque(std::string movement);

public:
	std::vector<CPawn> pawns;
	CPlayer(bool input = false);
	~CPlayer();
	std::vector<std::string> Move();
};

