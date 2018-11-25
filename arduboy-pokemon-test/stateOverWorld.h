#pragma once
#include <Arduboy2.h>
#include "context.h"
#include "textbox.h"
#include "states.h"
#include "stateBase.h"
#include "utilities/ArrayUtils.h"

#include "assets/sprites.h"

#include "worldDefines.h"
#include "world.h"
#include "menuDefines.h"
#include "menu.h"

#include "monsterMenu.h"

class StateOverWorld : public StateBase
{
public:
	StateOverWorld(Arduboy2 & arduboy, Textbox & textbox, GameContext & context);
private:

	bool menuShow = false;
	
	Menu menu = Menu(PauseMenuItems);
	World world = World(arduboy, context);
	MonsterMenu monsterMenu = MonsterMenu(context.stats);
	
	GameStateID Tick();
	void Draw();
public:
	GameStateID Run();
	
};