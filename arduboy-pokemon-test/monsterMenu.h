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
	
	//taken from battle, share code later
	void DrawHealthBar(uint8_t percentage, uint8_t x, uint8_t y)
	{
		const uint8_t BorderSize = 2;
		const uint8_t Width = 50;
		const uint8_t Height = 2;
		
		arduboy.drawRect(x, y, Width + (BorderSize * 2), Height + (BorderSize * 2), WHITE);
		arduboy.fillRect(x + BorderSize, y + BorderSize, percentage / 2, Height, WHITE);
	}
	//taken from battle, share code later
	
	void drawSegment(uint8_t index, uint8_t y)
	{
		auto monster = &stats.Party[index];
		if(monster->species == MonsterSpecies::None)
			return;
		
		//draw sprite in left 16x16 square
		arduboy.drawLine(menuX + 1, y, menuX + 17, y + 16, WHITE);
		
		arduboy.setCursor(menuX + 18,y);
		arduboy.print(monster->getSpeciesName());
		arduboy.print(F(" lv 10"));
		
		//draw hp bar (share code with battle??)
		DrawHealthBar(50, menuX + 18, y + 10);
		
		//arduboy.setCursor(menuX + 18,y + 8);
		
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
		uint8_t drawY = menuY + 1;
		for(uint8_t i = 0; i < count; ++i)
		{
			drawSegment(i, drawY);
			drawY += heightSegment;
		}
	}
};
