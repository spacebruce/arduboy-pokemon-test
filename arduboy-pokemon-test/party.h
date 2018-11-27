#pragma once

#include "monster.h"

class Party
{
public:
	bool Empty()
	{
		return (Count == 0);
		/*
		for(uint8_t i = 0; i < Capacity; ++i)
		{
			if(monsterEmpty(i))
				return false;
		}
		return true;
		*/
	}
	
	uint8_t Capacity;
	uint8_t Count;
	Monster store[6];	
private:
};