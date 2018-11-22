#pragma once
#include <avr/pgmspace.h>
#include "utilities/FlashString.h"

enum class MenuReturn : uint8_t
{
	Null,
	//Generic
	Yes,
	No,
	//Main
	MainNewGame,
	MainLoadGame,
	//Pause
	PauseMenuMonsters,
	PauseMenuPlayer,
	PauseMenuItems,
	PauseMenuMap,
	PauseMenuSave,
	PauseMenuOptions,
	PauseMenuTestBattle,
	//Battle
	BattleMenuFight,
	BattleMenuParty,
	BattleMenuBaggy,
	BattleMenuRunny,
	BattleMenuAttackSelect,
};

struct MenuItem
{
	FlashString string;
	MenuReturn result;
	constexpr MenuItem(FlashString string, MenuReturn result) : string(string), result(result)	{}
};

const PROGMEM char StringEmpty[] = "";
const PROGMEM char StringYes[] = "Yes";
const PROGMEM char StringNo[] = "No";

//main menu
const char StringMainMenuStart[] PROGMEM = "New Game";
const char StringMainMenuLoad[] PROGMEM = "Load Game";

const MenuItem MainMenuItems[] PROGMEM =
{
	MenuItem(asFlashString(StringMainMenuStart), MenuReturn::MainNewGame),
	MenuItem(asFlashString(StringMainMenuLoad), MenuReturn::MainLoadGame),
};

//pause menu
const uint8_t PauseMenuPlayerIndex = 1;

const char StringPauseMenuMonsters[] PROGMEM = "Monsters";
const char StringPauseMenuItems[] PROGMEM = "Bag";
const char StringPauseMenuMap[] PROGMEM = "Map";
const char StringPauseMenuSave[] PROGMEM = "Save";
const char StringPauseMenuOptions[] PROGMEM = "Options";
const char StringPauseMenuTestBattle[] PROGMEM = "BatlTest";

const MenuItem PauseMenuItems[] PROGMEM =
{
	MenuItem(asFlashString(StringPauseMenuMonsters), MenuReturn::PauseMenuMonsters),
	MenuItem(asFlashString(StringEmpty), MenuReturn::PauseMenuPlayer),
	MenuItem(asFlashString(StringPauseMenuItems), MenuReturn::PauseMenuItems),
	MenuItem(asFlashString(StringPauseMenuMap), MenuReturn::PauseMenuMap),
	MenuItem(asFlashString(StringPauseMenuSave), MenuReturn::PauseMenuSave),
	MenuItem(asFlashString(StringPauseMenuOptions), MenuReturn::PauseMenuOptions),
	MenuItem(asFlashString(StringPauseMenuTestBattle), MenuReturn::PauseMenuTestBattle),
};

//battle menu
const PROGMEM char StringBattleMenuFight[] = "Fight";	
const PROGMEM char StringBattleMenuParty[] = "Party";
const PROGMEM char StringBattleMenuItems[] = "Bag";
const PROGMEM char StringBattleMenuRunny[] = "Run!";	
const MenuItem BattleMenuMainItems[] PROGMEM =
{
	MenuItem(asFlashString(StringBattleMenuFight), MenuReturn::BattleMenuFight),
	MenuItem(asFlashString(StringBattleMenuParty), MenuReturn::BattleMenuParty),
	MenuItem(asFlashString(StringBattleMenuItems), MenuReturn::BattleMenuBaggy),
	MenuItem(asFlashString(StringBattleMenuRunny), MenuReturn::BattleMenuRunny),
};

const MenuItem BattleMenuRunItems[] PROGMEM =
{
	MenuItem(asFlashString(StringYes), MenuReturn::Yes),
	MenuItem(asFlashString(StringNo), MenuReturn::No),
};

const MenuItem BattleMenuFight[] PROGMEM =
{
	MenuItem(asFlashString(StringEmpty), MenuReturn::BattleMenuAttackSelect),
	MenuItem(asFlashString(StringEmpty), MenuReturn::BattleMenuAttackSelect),
	MenuItem(asFlashString(StringEmpty), MenuReturn::BattleMenuAttackSelect),
	MenuItem(asFlashString(StringEmpty), MenuReturn::BattleMenuAttackSelect),
};