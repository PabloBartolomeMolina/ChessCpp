#pragma once
#include <iostream>
#include "CPiece.h"

using namespace std;

class CRook : public CPiece
{
public:
	CRook(bool color = 0, string pos = "a1", int num = 0);
	~CRook();
	void move();
};

