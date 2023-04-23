#pragma once
#include <iostream>
#include "CPiece.h"

class CKnight : public CPiece
{
public:
	CKnight(bool color = 0, std::string pos = "b1", int num = 0);
	~CKnight();
	bool check_movement(char new_f, char old_f, char new_c, char old_c);
	bool move(std::string origin, std::string movement);
};

