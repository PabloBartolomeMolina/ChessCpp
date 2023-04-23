#pragma once
#include <iostream>
#include "CPiece.h"

class CKing : public CPiece
{
public:
	bool firstMove = true; 
	CKing(bool color = 0, std::string pos = "e1", int num = 0);
	~CKing();
	bool move(std::string origin, std::string movement);
	bool firstMovement();
};

