#pragma once
#include <Arduboy2.h>
#include "context.h"
#include "textbox.h"
#include "states.h"

class StateBase
{
protected:
	Arduboy2 & arduboy;
	GameContext & context;
	Textbox & textbox;
	
	StateBase(Arduboy2 & arduboy, Textbox & textbox, GameContext & context)
		: arduboy(arduboy), textbox(textbox), context(context)
	{
	}

public:
	virtual GameStateID Run() = 0;
};