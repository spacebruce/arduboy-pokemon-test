#pragma once
#include <Arduboy2.h>

#include "contextStats.h"
#include "monster.h"
#include "menu.h"

class MonsterMenu
{
private:
	ContextStats &stats;
	
	const uint8_t x = 4;
	const uint8_t y = 2;
	const uint8_t width = 120;
	const uint8_t height = 60;
	
public:
	MonsterMenu(ContextStats & stats) : stats(stats) {};
	
	bool active = false;
	
	void update(Arduboy2 & arduboy)
	{
		if(arduboy.justPressed(A_BUTTON))
		{
			this->active = false;
		}
	}
	
	void draw(Arduboy2 & arduboy)
	{
		arduboy.drawRect(x,y,width,height,BLACK);
	}
};
