#include "stateOverWorld.h"

StateOverWorld::StateOverWorld(Arduboy2 & arduboy, Textbox & textbox, GameContext & context) : StateBase(arduboy, textbox, context)
{
}

GameStateID StateOverWorld::Run()
{
	GameStateID state = this->Tick();
	this->Draw();
	
	return state;
}

GameStateID StateOverWorld::Tick()
{
	GameStateID state = GameStateID::OverWorld;
	if(!menuShow)
	{		
		if(world.player.ready())
		{
			if(arduboy.justPressed(B_BUTTON))
			{
				menuShow = true;
				menu.selectFirstIndex();
			}
			if(arduboy.pressed(UP_BUTTON))
			{
				world.player.move(0, -1);
			}	
			if(arduboy.pressed(DOWN_BUTTON))
			{
				world.player.move(0, 1);
			}	
			if(arduboy.pressed(LEFT_BUTTON))
			{
				world.player.move(-1, 0);
			}	
			if(arduboy.pressed(RIGHT_BUTTON))
			{
				world.player.move(1, 0);
			}
		}
		else
		{
			context.world.player.x += world.player.getMoveX();
			context.world.player.y += world.player.getMoveY();
		}
	}
	else
	{
		if(arduboy.justPressed(UP_BUTTON))
		{
			menu.selectPreviousIndex();
		}		
		if(arduboy.justPressed(DOWN_BUTTON))
		{
			menu.selectNextIndex();
		}
		if(arduboy.justPressed(B_BUTTON))
		{
			menuShow = false;
		}

		if(arduboy.justPressed(A_BUTTON))
		{
			const uint8_t Selected = menu.getSelectedIndex();
			switch(menu.getCurrentValue())
			{
				case MenuReturn::PauseMenuMonsters:
				break;
				case MenuReturn::PauseMenuPlayer:
				break;
				case MenuReturn::PauseMenuItems:
				break;
				case MenuReturn::PauseMenuMap:
				break;
				case MenuReturn::PauseMenuSave:
					context.Save();
					textbox.print("Saved");
				break;
				case MenuReturn::PauseMenuOptions:
				break;
				case MenuReturn::PauseMenuTestBattle:
					state = GameStateID::Battle;
				break;
			}
		}
	}
	
	return state;
}

void StateOverWorld::Draw()
{
	arduboy.fillScreen(BLACK);
	
	world.setCamera((context.world.player.x + 8) - (WIDTH / 2), (context.world.player.y + 8) - (HEIGHT / 2));
	
	//draw world and stuff
	world.drawWorld();
	world.drawStuff();
	
	//draw NPC's and stuff
	
	//draw UI
	
	if(!menuShow)
	{
	}
	if(menuShow)
	{
		const uint8_t Selected = menu.getSelectedIndex();
		const uint8_t MenuWidth = 58;
		const uint8_t MenuHeight = (ArrayLength(PauseMenuItems) * 8) + 4;
		const uint8_t MenuY = (HEIGHT - MenuHeight) / 2;
		
		int8_t x = (WIDTH - MenuWidth) + 8;
		int8_t y = MenuY + 2;
		
		arduboy.fillRect(WIDTH - MenuWidth, MenuY, MenuWidth, MenuHeight, BLACK);
		arduboy.drawRect(WIDTH - MenuWidth, MenuY, MenuWidth, MenuHeight, WHITE);
		Sprites::drawOverwrite((WIDTH - MenuWidth) + 2, y + (Selected * 8), Sprite::UIArrow, 0);
		//arduboy.drawBitmap((WIDTH - MenuWidth) + 2, y + (Selected * 8), Sprite::UIArrow, 5, 8, WHITE);
		
		for (auto i = menu.getFirstIndex(); i < menu.getEndIndex(); ++i)
		{
			arduboy.setCursor(x, y);
			if(i == PauseMenuPlayerIndex)	
				arduboy.println(context.stats.playerName);
			else
				arduboy.println(menu.getString(i));
			y += 8;
		}
	}
}