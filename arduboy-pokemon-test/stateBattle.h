#pragma once
#include <Arduboy2.h>
#include "context.h"
#include "textbox.h"
#include "states.h"
#include "stateBase.h"

#include "assets/sprites.h"
#include "battleDefines.h"

class StateBattle : public StateBase
{
private:
	uint8_t transition = 0;
	BattleMenu menuOn = BattleMenu::Action;
	uint8_t select = 0;
	
	void BattleUI();
	
	void DrawHealthBar(uint8_t percentage, uint8_t x, uint8_t y);
	void Draw();
	BattlePhase phase = BattlePhase::Intro;
public:
	StateBattle(Arduboy2 & arduboy, Textbox & textbox, GameContext & context);
	GameStateID Run();
};