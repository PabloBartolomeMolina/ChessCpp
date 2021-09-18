#pragma once
#include <iostream>
#include "CPiece.h"

using namespace std;

class CBishop : public CPiece
{
public:
	CBishop(bool color = 0, string pos = "c1", int num = 0);
	~CBishop();
	bool check_movement(char new_f, char old_f, char new_c, char old_c);
	bool move(string origin, string movement);
};

