#include "StateNewGame.h"

StateNewGame::StateNewGame(Arduboy2 & arduboy, Textbox & textbox, GameContext & context)
	: StateBase(arduboy, textbox, context)
{
}

bool StateNewGame::tryAccept()
{
	uint8_t beginIndex = nameForm.getTrimmedBegin();
	uint8_t endIndex = nameForm.getTrimmedEnd();

	auto & playerName = context.stats.playerName;

	for(uint8_t i = 0, j = beginIndex; i < ContextStats::nameLength; ++i, ++j)
	{
		if(j < endIndex)
			playerName[i] = nameForm[j];
		else
			playerName[i] = '\0';
	}

	return (endIndex != 0);
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
			bool success = this->tryAccept();

			if(!success)
				index -= 2;

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
		arduboy.drawFastHLine(xOffset + spacing, yOffset + 9, xOffset + spacing + NameUnderlineWidth);
		
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