#pragma once

#include "direction.h"

class Actor
{
public:
	int16_t x;
	int16_t y;
	Direction direction;

public:
	Actor() = default;
	constexpr Actor(int16_t x, int16_t y, Direction direction)
		: x(x), y(y), direction(direction)
	{
	}
};