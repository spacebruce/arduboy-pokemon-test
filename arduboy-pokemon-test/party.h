#pragma once

#include "monster.h"

template <uint8_t capacity>
class Party
{
public:
	bool empty()
	{
		return (count == 0);
	}
	
	uint8_t count = 0;
	bool full()
	{
		return (count == capacity);
	}
	
	
	void add(const Monster &monster)
	{
		if(count >= capacity)
			return;
		store[count] = monster;
		++count;
	}
	
	void remove(const uint8_t index)
	{
		for(uint8_t i = index; i < count; ++i)
		{
			store[i] = store[i + 1];
		}
		--count;
	}
};