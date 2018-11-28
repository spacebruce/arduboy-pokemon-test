#pragma once

#include "monster.h"

template <uint8_t capacity>
class Party
{
public:
	uint8_t getActive() const
	{
		return this->selected;
	}
	
	void setActive(const uint8_t selected)
	{
		this->selected = selected;
	}

	uint8_t getCount() const
	{
		return count;
	}
	
	constexpr uint8_t getCapacity() const
	{
		return capacity;
	}
	
	inline bool empty() const
	{
		return (count == 0);
	}
	
	inline bool full() const
	{
		return (count == capacity);
	}
	
	void swap(const uint8_t left, const uint8_t right)
	{
		Monster temp = store[left];
		store[left] = store[right];
		store[right] = temp;
	}
	
	void add(const Monster &monster)
	{
		if(count < capacity)
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

	Monster & getMonster(const uint8_t index) const
	{
		return store[index];
	}
	
	Monster & operator [] (const uint8_t index)
	{
		return store[index];
	}
	
private:
	Monster store[capacity];	
	uint8_t count = 0;
	uint8_t selected = 0;
};