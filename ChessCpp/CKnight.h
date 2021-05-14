#pragma once
#include <iostream>
#include "CPiece.h"

using namespace std;

class CKnight : public CPiece
{
public:
	CKnight(bool color = 0, string pos = "a2", int num = 0);
	~CKnight();
	void move();
};

