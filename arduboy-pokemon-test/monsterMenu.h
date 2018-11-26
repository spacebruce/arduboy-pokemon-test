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
	
	const uint8_t x = 4;
	const uint8_t y = 2;
	const uint8_t width = 120;
	const uint8_t height = 60;
	
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
		arduboy.fillRect(x,y,width,height,BLACK);
		arduboy.drawRect(x,y,width,height,WHITE);
		
		uint8_t count = stats.Party.getCapacity();
		arduboy.setCursor(0,0);
		arduboy.print(count);
		
		uint8_t drawY = y;
		for(uint8_t i = 0; i < count; ++i)
		{
			auto monster = &stats.Party[i];
			arduboy.setCursor(x,drawY);
			
			arduboy.print(monster->getSpeciesName());
			drawY += 8;
		}
	}
};
