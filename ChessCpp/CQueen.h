#pragma once
#include <iostream>
#include "CPiece.h"

using namespace std;

class CQueen : public CPiece
{
public:
	CQueen();
	~CQueen();
	void move();
};

