#pragma once
#include <iostream>
#include "CPiece.h"

using namespace std;

class CKing : public CPiece
{
public:
	CKing();
	~CKing();
	void move();
};

