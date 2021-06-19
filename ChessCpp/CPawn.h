#pragma once
#include "CPiece.h"

class CPawn : public CPiece
{
private:
	bool simpleMove(string origin, string movement);
public:
	CPawn(bool color = 0, string pos = "a2", int num = 0);
	~CPawn();
	bool move(string origin, string movement);
};

