#pragma once

#include "worldEnums.h"

class Player
{
private:
	//x, y and dir stored in context
	int8_t moveX = 0;
	int8_t moveY = 0;
public:
	void move(int8_t moveX, int8_t moveY)
	{
		this->moveX = moveX * TileWidth;
		this->moveY = moveY * TileHeight;
	}
	
	bool ready(void)
	{
		return ((moveX == 0) && (moveY == 0));
	}
	
	int8_t getMoveX(void)
	{
		if(moveX > 0)
		{
			moveX--;
			return +1;
		}
		if(moveX < 0)
		{
			moveX++;
			return -1;
		}
		return 0;
	}
	int8_t getMoveY(void)
	{
		if(moveY > 0)
		{
			moveY--;
			return +1;
		}
		if(moveY < 0)
		{
			moveY++;
			return -1;
		}
		return 0;
	}
};