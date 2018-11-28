#pragma once
#include <Arduboy2.h>
#include "context.h"
#include "textbox.h"
#include "states.h"

class StateBase
{
protected:
	Arduboy2 & arduboy;
	Textbox & textbox;
	GameContext & context;
	
	StateBase(Arduboy2 & arduboy, Textbox & textbox, GameContext & context)
		: arduboy(arduboy), textbox(textbox), context(context)
	{
	}

public:
	virtual ~StateBase() = default;

	virtual GameStateID Run() = 0;
};