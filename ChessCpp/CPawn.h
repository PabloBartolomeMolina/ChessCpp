#pragma once
#include "CPiece.h"

class CPawn : public CPiece
{
public:
	CPawn(bool color = 0, string pos = "a2", int num = 0);
	~CPawn();
	void move();
};

