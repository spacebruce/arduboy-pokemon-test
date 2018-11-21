#include "stateStartup.h"

StateStartup::StateStartup(Arduboy2 & arduboy, Textbox & textbox, GameContext & context)
	: StateBase(arduboy, textbox, context)
{
}

GameStateID StateStartup::Run()
{
	arduboy.print(F("logo goes here"));
	
	if(arduboy.justPressed(A_BUTTON))
		return GameStateID::Menu;
	
	return GameStateID::Startup;
}