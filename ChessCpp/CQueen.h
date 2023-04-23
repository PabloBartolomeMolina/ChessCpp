#pragma once
#include <iostream>
#include "CPiece.h"

class CQueen : public CPiece
{
public:
	CQueen(bool color = 0, std::string pos = "d1", int num = 0);
	~CQueen();
	bool check_movement(char new_f, char old_f, char new_c, char old_c);
	bool move(std::string origin, std::string movement);
};

