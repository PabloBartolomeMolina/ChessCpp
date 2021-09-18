#pragma once
#include <iostream>
#include "CPiece.h"

using namespace std;

class CRook : public CPiece
{
public:
	bool firstMove = true;
	CRook(bool color = 0, string pos = "a1", int num = 0);
	~CRook();
	bool check_movement(char new_f, char old_f, char new_c, char old_c);
	bool move(string origin, string movement);
	bool firstMovement(string movement, bool color);
};

