#pragma once
#include <avr/pgmspace.h>
#include "utilities/FlashString.h"

enum class BattlePhase : uint8_t
{
	Intro,
	Select,
	Attack1,
	Attack2,
	Victory,
	Defeat,
};

enum class BattleMenu : uint8_t
{
	Action,	//main picker
	Fight,	//move
	Run,	//run away
};

const PROGMEM char stringBattleMenuAction[] = "Action?";
const PROGMEM char stringBattleMenuFight[] = "Fight!";
const PROGMEM char stringBattleMenuRun[] = "Run?";
const PROGMEM FlashString stringBattleTitle[] = 
{
	asFlashString(stringBattleMenuAction), 
	asFlashString(stringBattleMenuFight), 
	asFlashString(stringBattleMenuRun),
};