#pragma once
#include <Arduboy2.h>

#include "contextStats.h"
#include "monster.h"
//#include "menu.h"

class MonsterMenu
{
private:
	Arduboy2 & arduboy;
	ContextStats &stats;
	
	bool active = false;

	uint8_t selected = 0;
	
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
		auto monster = &stats.party[index];
		const uint8_t startX = menuX + 4;
		if(monster->species == MonsterSpecies::None)
			return;
		
		//draw sprite in left 16x16 square
		arduboy.drawLine(startX + 1, y, startX + 16, y + 15, WHITE);
		
		arduboy.setCursor(startX + 17,y);
		arduboy.print(monster->getSpeciesName());
		arduboy.print(F(" lv 10"));
		
		//draw hp bar (share code with battle??)
		DrawHealthBar(50, startX + 17, y + 10);
		
		//arduboy.setCursor(menuX + 18,y + 8);
		
		if(index == selected)
		{
			//arduboy.drawLine(menuX + 2, y, menuX + 2, y + 16, WHITE);
			arduboy.drawRect(menuX, y, menuWidth, 16, WHITE);
		}
	}
	
	
public:
	MonsterMenu(Arduboy2 & arduboy, ContextStats & stats) : arduboy(arduboy), stats(stats) {};
	
	bool getActive()
	{
		return this->active;
	}
	void setActive(bool active)
	{
		selected = 0;
		this->active = active;
	}
	
	void update()
	{		
		if(stats.party.empty())
		{
			this->active = false;
			return;
		}
		
		if(arduboy.justPressed(UP_BUTTON))
		{
			if(selected > 0)
			{
				--selected;
			}
		}
		if(arduboy.justPressed(DOWN_BUTTON))
		{			
			if(selected < (stats.party.getCount() - 1))
			{
				++selected;
			}
		}			
		if(arduboy.justPressed(B_BUTTON))
		{
			this->active = false;
		}
	}
	
	bool updateSwitchMonster()
	{
		this->update();
		return (arduboy.justPressed(A_BUTTON));
	}
	
	uint8_t getSelectedMonster()
	{
		return selected;
	}
	
	void draw()
	{
		arduboy.fillRect(menuX, menuY, menuWidth, menuHeight, BLACK);
		arduboy.drawRect(menuX, menuY, menuWidth, menuHeight, WHITE);
		
		uint8_t count = stats.party.getCount();
		uint8_t drawY = menuY + 1;
		for(uint8_t i = 0; i < count; ++i)
		{
			drawSegment(i, drawY);
			drawY += heightSegment;
		}
	}
};
