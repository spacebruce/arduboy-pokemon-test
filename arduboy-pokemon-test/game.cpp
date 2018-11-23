#include "game.h"

void Game::StateChange(const GameStateID stateNext)
{
	if(state != nullptr)
	{
		//state->End();
		delete state;
	}

	switch(stateNext)
	{
		case GameStateID::Startup:
			state = new StateStartup(arduboy, textbox, context);
			break;		
		case GameStateID::NewGame:
			state = new StateNewGame(arduboy, textbox, context);
			break;
		case GameStateID::Menu:
			state = new StateMenu(arduboy, textbox,context);
			break;
		case GameStateID::OverWorld:
			state = new StateOverWorld(arduboy, textbox,context);
			break;
		case GameStateID::Battle:
			state = new StateBattle(arduboy, textbox,context);
			break;
	}
	
	stateCurrent = stateNext;
}

void Game::Begin()
{
	arduboy.begin();
	arduboy.setFrameRate(60);
}
	
void Game::Run()
{
	if (!arduboy.nextFrame())
		return;
	
	if((stateNext != stateCurrent) || (state == nullptr))
	{
		StateChange(stateNext);
	}
	
	arduboy.pollButtons();
	
	if(textbox.busy())
	{
		textbox.tick(arduboy);
		textbox.draw(arduboy);
	}
	else
	{
		stateNext = state->Run();
	}
	
	arduboy.display();
}