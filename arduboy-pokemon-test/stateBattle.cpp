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
	arduboy.fillRect(x + BorderSize, y + BorderSize, percentage, Height, BLACK);
}

void StateBattle::Draw()
{
	arduboy.setCursor(5,2);
	arduboy.print(F("namehere1"));
	//arduboy.print(F(" HP 45/120"));
	DrawHealthBar(50, 5, 9);
void StateBattle::BattleUI()
{
	const uint8_t xstart = 4;
	const uint8_t ystart = 46;
	
	arduboy.setCursor(xstart, ystart);
	arduboy.print(stringBattleMenuAction);
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
			textbox.print(F("!!!"));
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