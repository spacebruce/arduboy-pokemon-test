#pragma once

#include "monster.h"

class Party
{
public:
	bool Empty()
	{
		return (count == 0);
		/*
		for(uint8_t i = 0; i < Capacity; ++i)
		{
			if(monsterEmpty(i))
				return false;
		}
		return true;
		*/
	}
	
	uint8_t capacity = 6;
	uint8_t count = 0;
	Monster store[6];	
	
	void add(const Monster &monster)
	{
		if(count >= capacity)
			return;
		store[count] = monster;
		++count;
	}

private:
	bool monsterEmpty(uint8_t i)
	{
		return (store[i].species == MonsterSpecies::None);
	}
};