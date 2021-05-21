#pragma once
#include <iostream>
#include "CPiece.h"

using namespace std;

class CKing : public CPiece
{
private:
	bool castling = true;
public:
	CKing(bool color = 0, string pos = "e1", int num = 0);
	~CKing();
	bool move(string origin, string movement, bool firscligtMove = true);
};

