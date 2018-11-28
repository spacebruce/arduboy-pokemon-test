#pragma once

#include "monster.h"

template <uint8_t capacity>
class Party
{
public:
	Monster store[capacity];	
	
	uint8_t getCount()
	{
		return count;
	}
	
	constexpr uint8_t getCapacity() const
	{
		return capacity;
	}
	
	bool empty()
	{
		return (count == 0);
	}
	
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

	Monster & getMonster(const uint8_t index)
	{
		return store[index];
	}
	
	Monster & operator [] (const uint8_t index)
	{
		return store[index];
	}
	
private:
	uint8_t count = 0;
};