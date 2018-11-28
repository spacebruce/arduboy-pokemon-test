#pragma once

#include <stdint.h>

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
	
	//MonsterMenu
	MonsterSelect,
};