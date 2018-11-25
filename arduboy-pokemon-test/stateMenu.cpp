#include "stateMenu.h"

StateMenu::StateMenu(Arduboy2 & arduboy, Textbox & textbox, GameContext & context)
	: StateBase(arduboy, textbox, context)
{
}

GameStateID StateMenu::Run()
{
	GameStateID state = GameStateID::Menu;
	
	if(arduboy.justPressed(UP_BUTTON))
	{
		menu.selectPreviousIndex();
	}

	if(arduboy.justPressed(DOWN_BUTTON))
	{
		menu.selectNextIndex();
	}
	
	if(arduboy.justPressed(A_BUTTON))
	{
		switch(menu.getCurrentValue())
		{
			case MenuReturn::MainLoadGame:
				if(context.Load())
				{
					textbox.print(F("Loaded"));
					state = GameStateID::OverWorld;
				}
				else
				{
					textbox.print(F("Corrupted save!"));
				}
			break;
			case MenuReturn::MainNewGame:
				state = GameStateID::NewGame;
				context.NewGame();
			break;
		}
	}
	
	const uint8_t Selected = menu.getSelectedIndex();
	const int8_t drawY = HEIGHT - 18;
	
	arduboy.fillScreen(BLACK);
	
	arduboy.drawRect(0, HEIGHT - 20, 66, 19, WHITE);
	Sprites::drawOverwrite(2, drawY + (Selected * 8), Sprite::UIArrow, 0);
	//arduboy.drawBitmap(2, drawY + (Selected * 8), Sprite::UIArrow, 5, 8, WHITE);
	
	menu.print(arduboy, 10, drawY);
	return state;
}