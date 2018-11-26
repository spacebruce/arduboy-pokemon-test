#pragma once
#include <Arduboy2.h>

#include "contextStats.h"
#include "monster.h"
#include "menu.h"

class MonsterMenu
{
private:
	Arduboy2 & arduboy;
	ContextStats &stats;
	
	
	
	const uint8_t menuX = 4;
	const uint8_t menuY = 0;
	const uint8_t menuWidth = 120;
	const uint8_t menuHeight = 64;
	const uint8_t heightSegment = 16;
	
	void drawSegment(uint8_t index, uint8_t y)
	{
		auto monster = &stats.Party[index];
		arduboy.setCursor(menuX + 2,y);
		
		arduboy.print(monster->getSpeciesName());
	}
	
public:

	MonsterMenu(Arduboy2 & arduboy, ContextStats & stats) : arduboy(arduboy), stats(stats) {};
	
	bool active = false;
	
	void update()
	{
		if(arduboy.justPressed(A_BUTTON))
		{
			this->active = false;
		}
	}
	
	void draw()
	{
		arduboy.fillRect(menuX, menuY, menuWidth, menuHeight, BLACK);
		arduboy.drawRect(menuX, menuY, menuWidth, menuHeight, WHITE);
		
		uint8_t count = stats.Party.getCapacity();
		uint8_t drawY = menuY;
		for(uint8_t i = 0; i < count; ++i)
		{
			drawSegment(i, drawY);
			drawY += heightSegment;
		}
	}
};
