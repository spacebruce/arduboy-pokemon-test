#pragma once

#include "actor.h"

struct ContextWorld 
{
	Actor player = Actor(0, 0, Direction::South);

	Actor npcs[MaxNPC];
};