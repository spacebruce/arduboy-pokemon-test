#pragma once
#include <Arduboy2.h>

#include "contextStats.h"
#include "monster.h"
#include "menu.h"

class MonsterMenu
{
private:
	ContextStats &stats;
	
public:
	MonsterMenu(ContextStats & stats) : stats(stats) {};
	
	void Draw(Arduboy2 & arduboy)
	{
		
	}
};
