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

using namespace std;

class CPlayer
{
private:
	// 0 for black color and 1 for white color.
	bool color = 0;
	// 0 for no turn of movement and 1 for turn of movement.
	bool turn = 0;
	// By default it is for black pieces, to be changed if needed at creation of object.
	string pieces[8] = { "Rb", "Nb", "Bb", "Qb", "Kb", "Bb", "Nb", "Rb" };
	string whiteInitialPawns[8] = { "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2"};
	string whiteInitialPieces[8] = { "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1" };
	string blackInitialPawns[8] = { "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7" };
	string blackInitialPieces[8] = { "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8" };

	vector<CRook> rooks;
	vector<CKnight> knights;
	vector<CBishop> bishops;
	vector<CQueen> queens;
	vector<CKing> kings;

	// Creation of pieces.
	void createPieces(bool color = 0);
	// Check movement.
	bool CheckMove(string movement);
	// Check destination before moving.
	bool CheckOccupied(string movement);

public:
	vector<CPawn> pawns;
	CPlayer(bool input = false);
	~CPlayer();
	vector<string> Move();
};

