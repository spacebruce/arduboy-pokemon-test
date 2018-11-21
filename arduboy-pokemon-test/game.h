#pragma once
#include <Arduboy2.h>
#include "states.h"

#include "context.h"
#include "textbox.h"

#include "stateBase.h"
#include "stateMenu.h"
#include "stateNewGame.h"
#include "stateOverWorld.h"
#include "stateBattle.h"
#include "stateStartup.h"

class Game
{
public:
	Game(void) = default;
private:
	Arduboy2 arduboy;
	GameContext context;
	Textbox textbox = Textbox(arduboy);
	
	StateBase * state;
	GameStateID stateCurrent = GameStateID::Null;
	GameStateID stateNext = GameStateID::Startup;
	
	void StateChange(const GameStateID stateNext);
public:
	
	void Begin();
	void Run();
};