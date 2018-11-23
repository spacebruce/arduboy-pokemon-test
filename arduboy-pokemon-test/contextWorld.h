#pragma once

#include "actor.h"

struct ContextWorld 
{
	Actor player = Actor(16 * 4, 16 * 10, Direction::South);

	Actor npcs[MaxNPC];
};