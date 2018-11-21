#pragma once
#include <Arduboy2.h>
#include "context.h"
#include "textbox.h"
#include "states.h"
#include "stateBase.h"

#include "utilities/ArrayUtils.h"
#include "nameentry.h"

#include "assets/sprites.h"

class StateNewGame : public StateBase
{
public:
	StateNewGame(Arduboy2 & arduboy, Textbox & textbox, GameContext & context);
private:
	uint8_t index = 0;
	bool nameinput = false;
	uint8_t letter = 0;
	NameEditor<8> nameForm;
	
public:
	GameStateID Run();
};