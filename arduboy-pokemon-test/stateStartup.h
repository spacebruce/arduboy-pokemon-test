#pragma once
#include <Arduboy2.h>
#include "context.h"
#include "textbox.h"
#include "states.h"
#include "stateBase.h"

class StateStartup : public StateBase
{
public:
	StateStartup(Arduboy2 & arduboy, Textbox & textbox, GameContext & context);
	GameStateID Run();
};