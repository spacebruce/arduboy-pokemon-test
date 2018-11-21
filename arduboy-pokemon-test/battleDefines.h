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

const PROGMEM char stringBattleFight[] = "Fight";
const PROGMEM char stringBattleParty[] = "Party";
const PROGMEM char stringBattleItems[] = "Bag";
const PROGMEM char stringBattleRunny[] = "Run!";	
const PROGMEM FlashString stringBattleAction[] = 
{
	asFlashString(stringBattleFight), 
	asFlashString(stringBattleParty), 
	asFlashString(stringBattleItems),
	asFlashString(stringBattleRunny),
};

const PROGMEM char stringBattleRunYes[] = "Yes";
const PROGMEM char stringBattleRunNo[] = "No";	
const PROGMEM FlashString stringBattleRun[] = 
{
	asFlashString(stringBattleRunYes), 
	asFlashString(stringBattleRunNo), 
};
