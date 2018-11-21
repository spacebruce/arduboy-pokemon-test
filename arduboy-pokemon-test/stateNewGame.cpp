#include "StateNewGame.h"

StateNewGame::StateNewGame(Arduboy2 & arduboy, Textbox & textbox, GameContext & context)
	: StateBase(arduboy, textbox, context)
{
}

GameStateID StateNewGame::Run()
{
	arduboy.fillScreen(BLACK);
	GameStateID state = GameStateID::NewGame;
	
	if(nameinput)
	{
		if (arduboy.justPressed(UP_BUTTON))
			nameForm.incrementChar();
		
		if (arduboy.justPressed(DOWN_BUTTON))
			nameForm.decrementChar();
		
		if (arduboy.justPressed(LEFT_BUTTON))
			nameForm.decrementCharIndex();
			
		if (arduboy.justPressed(RIGHT_BUTTON))
			nameForm.incrementCharIndex();

		if (arduboy.justPressed(A_BUTTON))
		{
			bool empty = true;
			uint8_t i = 0;
			for(uint8_t n = nameForm.getFirstChar(); n <= nameForm.getLastChar(); ++n)
			{
				char letter = nameForm.getChar(n);
				if(letter != ' ')
					empty = false;
				context.stats.playerName[i] = letter;
				++i;
			}
			context.stats.playerName[nameForm.getLastChar() + 1] = '\0';
			
			if(empty)
			{
				index -= 2;	//repeat last line
			}
			nameinput = false;
		}
		
		const uint8_t NameCharacterSpacing = 6;
		const uint8_t NameUnderlineWidth = 4;

		const uint8_t xOffset = 42;
		const uint8_t yOffset = 10;

		arduboy.setCursor(4, 9);
		//arduboy.fillRect(xOffset - 2, yOffset - 2 , 73, 13, BLACK);
		arduboy.drawRect(xOffset - 2, yOffset - 2 , 73, 13, WHITE);
		arduboy.print(F("Name:"));
			
		arduboy.setCursor(xOffset, yOffset);
		for (uint8_t i = 0; i < nameForm.getLength(); i++)
		{
			arduboy.print(nameForm.getChar(i));
		}
		
		const uint8_t position = nameForm.getCharIndex();
		const uint8_t spacing = (position * NameCharacterSpacing);
		arduboy.drawLine(xOffset + spacing, yOffset + 9, xOffset + spacing + NameUnderlineWidth, yOffset + 9);
		
		textbox.draw();
	}
	else
	{
		switch(index)
		{
			case 0:	textbox.print(F("yo ho!")); break;
			case 1:	textbox.print(F("what's your name,\nson?")); break;
			case 2:
			{
				nameinput = true;
			} break;
			case 3:
			{
				char str[20] = "hello ";	//hacky, fix
				for(auto i = 0; i < 8; ++i)
				{
					str[i + 6] = context.stats.playerName[i];
				}
				
				textbox.print(str); 
			} break;
			case 4:
			{
				state = GameStateID::OverWorld;
			} break;
		}
		++index;
	}
	
	return state;
}