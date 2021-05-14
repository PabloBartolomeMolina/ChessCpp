#pragma once
#include <iostream>
#include "CPiece.h"

using namespace std;

class CQueen : public CPiece
{
public:
	CQueen(bool color = 0, string pos = "a2", int num = 0);
	~CQueen();
	void move();
};

