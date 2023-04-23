#pragma once
#include <iostream>
#include "CPiece.h"

class CRook : public CPiece
{
public:
	bool firstMove = true;
	CRook(bool color = 0, std::string pos = "a1", int num = 0);
	~CRook();
	bool check_movement(char new_f, char old_f, char new_c, char old_c);
	bool move(std::string origin, std::string movement);
	bool firstMovement(std::string movement, bool color);
};

