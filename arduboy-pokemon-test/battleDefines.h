#pragma once

#include <avr/pgmspace.h>
#include "utilities/FlashString.h"

#include "battlePhase.h"
#include "battleMenu.h"

const PROGMEM char stringBattleMenuAction[] = "Action?";
const PROGMEM char stringBattleMenuFight[] = "Fight!";
const PROGMEM char stringBattleMenuRun[] = "Run?";

const PROGMEM FlashString stringBattleTitle[] = 
{
	asFlashString(stringBattleMenuAction), 
	asFlashString(stringBattleMenuFight), 
	asFlashString(stringBattleMenuRun),
};