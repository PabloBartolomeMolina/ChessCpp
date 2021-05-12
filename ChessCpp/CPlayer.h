#pragma once

#include <iostream>
#include <map>
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

	// Creation of pieces.
	void createPieces(bool color = 0);

public:
	CPlayer(bool input = false);
	~CPlayer();
	void Move();
};

