#pragma once

#include "worldEnums.h"

struct ContextWorld 
{
	int16_t playerX = 0;
	int16_t playerY = 0;
	Direction playerDir = Direction::South;
	
	int16_t npcX[MaxNPC];
	int16_t npcY[MaxNPC];
	Direction npcDir[MaxNPC];
};