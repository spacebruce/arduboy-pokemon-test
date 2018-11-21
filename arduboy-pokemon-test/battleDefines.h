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

enum class ElementType : uint8_t
{
	Normal,
	Fire,
	Water,
	Grass,
};

struct AttackType
{
	FlashString label;	//label rather than name because name is a reserved arduino thing
	ElementType type;
	int8_t power;
	constexpr AttackType(FlashString string, ElementType type, int8_t power) : label(string), type(type), power(power) {}
};

const PROGMEM char attackTest1[] = "punch";
const PROGMEM char attackTest2[] = "flambe";

const PROGMEM AttackType Attacks[] = 
{
	AttackType(asFlashString(attackTest1), ElementType::Normal, 10),
	AttackType(asFlashString(attackTest2), ElementType::Fire, 15),
};