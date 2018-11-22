#include "StateBattle.h"

StateBattle::StateBattle(Arduboy2 & arduboy, Textbox & textbox, GameContext & context)
	: StateBase(arduboy, textbox, context)
{
}

void StateBattle::DrawHealthBar(uint8_t percentage, uint8_t x, uint8_t y)
{
	const uint8_t BorderSize = 2;
	const uint8_t Width = 50;
	const uint8_t Height = 2;
	
	arduboy.drawRect(x, y, Width + (BorderSize * 2), Height + (BorderSize * 2), BLACK);
	arduboy.fillRect(x + BorderSize, y + BorderSize, percentage / 2, Height, BLACK);
}

void StateBattle::Draw()
{
	//enemy hp bar
	arduboy.setCursor(2,1);
	arduboy.print(F("namehere1"));
	DrawHealthBar(50, 2, 9);
	
	//player hp bar
	arduboy.setCursor(72, 29);
	arduboy.print(F("namehere1"));
	DrawHealthBar(5, 72, 37);
	
	arduboy.fillRect(1, 44, 126, 20, BLACK);
	arduboy.drawRect(1, 44, 126, 20, WHITE);
}

GameStateID StateBattle::BattleUI()
{	
	auto menuCurrent = &menu[static_cast<uint8_t>(menuOn)];
	const uint8_t menuSize = menuCurrent->getEndIndex();
	
	//logic
	uint8_t select = menuCurrent->getSelectedIndex();
	if(arduboy.justPressed(DOWN_BUTTON))
	{
		if(select < 2)	select += 2;
	}
	if(arduboy.justPressed(UP_BUTTON))
	{
		if(select >= 2)	select -= 2;
	}
	if(arduboy.justPressed(LEFT_BUTTON))
	{
		if((select == 1) || (select == 3))
			select -= 1;
	}
	if(arduboy.justPressed(RIGHT_BUTTON))
	{
		if((select == 0) || (select == 2))
			select += 1;
	}
	menuCurrent->selectIndex(select);
	
	//draw
	const uint8_t xstart = 4;
	const uint8_t ystart = 46;
	
	arduboy.setCursor(xstart, ystart);
	arduboy.print(asFlashString(pgm_read_ptr(&stringBattleTitle[static_cast<uint8_t>(menuOn)])));
	
	static const int8_t menuX[4] = { 54, 94, 54, 94 };
	static const int8_t menuY[4] = { ystart, ystart, ystart + 8, ystart + 8 };

	if(menuOn != BattleMenu::Fight)
	{
		for(uint8_t i = 0; i < menuSize; ++i)
		{
			arduboy.setCursor(menuX[i], menuY[i]);
			arduboy.print(menuCurrent->getString(i));
		}
	}
	Sprites::drawOverwrite(menuX[select] - 6, menuY[select], Sprite::UIArrow, 0);
	
	return(GameStateID::Battle);	//do this more gracefully...
}

GameStateID StateBattle::Run()
{
	arduboy.fillScreen(WHITE);
	Draw();
	
	switch(phase)
	{
		case BattlePhase::Intro:
			textbox.print(F("Battle start"));
			phase = BattlePhase::Select;
		break;
		case BattlePhase::Select:
			BattleUI();
		break;
		case BattlePhase::Attack1:
		break;
		case BattlePhase::Attack2:
		break;
		case BattlePhase::Victory:
		break;
		case BattlePhase::Defeat:
		break;
	}
	
	return GameStateID::Battle;
}