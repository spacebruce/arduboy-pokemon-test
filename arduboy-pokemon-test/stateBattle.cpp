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

void StateBattle::BattleUI()
{
	const uint8_t xstart = 4;
	const uint8_t ystart = 46;
	
	arduboy.setCursor(xstart, ystart);
	arduboy.print(asFlashString(pgm_read_ptr(&stringBattleMenu[static_cast<uint8_t>(menuOn)])));
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
			//textbox.print(F("!!!"));
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