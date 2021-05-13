#pragma once
#include <iostream>
#include "CPiece.h"

using namespace std;

class CBishop : public CPiece
{
public:
	CBishop();
	~CBishop();
	void move();
};

