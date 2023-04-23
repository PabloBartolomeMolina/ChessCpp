#pragma once
#include "CPiece.h"

class CPawn : public CPiece
{
private:
	bool simpleMove(std::string origin, std::string movement);
	bool doubleMove(std::string origin, std::string movement);
	bool eat(std::string origin, std::string movement);
	bool eatPassant(std::string origin, std::string movement);
public:
	CPawn(bool color = 0, std::string pos = "a2", int num = 0);
	~CPawn();
	bool move(std::string origin, std::string movement);
};

