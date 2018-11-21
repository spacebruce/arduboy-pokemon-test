#pragma once
#include <Arduboy2.h>
#include "context.h"
#include "textbox.h"
#include "states.h"
#include "stateBase.h"

#include "assets/sprites.h"
#include "menuDefines.h"
#include "menu.h"


class StateMenu : public StateBase
{
private:
	Menu menu = Menu(MainMenuItems);

public:
	StateMenu(Arduboy2 & arduboy, Textbox & textbox, GameContext & context);
	GameStateID Run();
};