#pragma once
#include <iostream>
#include "CPiece.h"

using namespace std;

class CKnight : public CPiece
{
public:
	CKnight(bool color = 0, string pos = "b1", int num = 0);
	~CKnight();
	bool move(string movement);
};

