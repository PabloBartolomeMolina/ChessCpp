#pragma once
#include <iostream>
#include "CPiece.h"

using namespace std;

class CKing : public CPiece
{
public:
	CKing(bool color = 0, string pos = "e1", int num = 0);
	~CKing();
	void move(string movement);
};

