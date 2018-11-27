#pragma once

#include "monster.h"

class Party
{
public:
	uint8_t Capacity;
	uint8_t Count;
	Monster store[6];	
private:
};