#pragma once

#include "monster.h"

template<uint8_t capacity>
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
	
	uint8_t count = 0;
	Monster store[capacity];	
	
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