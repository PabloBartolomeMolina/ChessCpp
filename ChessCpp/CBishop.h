#pragma once
#include <iostream>
#include "CPiece.h"

using namespace std;

class CBishop : public CPiece
{
public:
	CBishop(bool color = 0, string pos = "c1", int num = 0);
	~CBishop();
	bool move(string movement);
};

