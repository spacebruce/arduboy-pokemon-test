#pragma once

class Textbox : public Print
{
private:
	constexpr static const uint8_t RowLength = 21;
	constexpr static const uint8_t RowCount  = 2;
	constexpr static const uint8_t CharMax = RowLength * RowCount;
	
	bool active = false;
	char text[CharMax];
	uint8_t cursor = 0;
	uint8_t reveal = 0;
public:
	bool isActive() const
	{
		return active;
	}
	
	void clear(void)
	{
		this->cursor = 0;
		for(uint8_t i = 0; i < CharMax; ++i)
			text[i] = '\0';
	}
	
	size_t write(uint8_t letter) override
	{
		if(this->cursor == 0)	//if writing new line, clear out old
			clear();
		
		if(letter == '\n')
		{
			this->cursor  = (((this->cursor / RowLength) + 1) * RowLength) - 1;
		}
		else
		{
			this->text[this->cursor] = letter;
			++this->cursor;
		}
		this->cursor = min(this->cursor, CharMax);
		this->reveal = 0;
		
		active = true;
		
		return 1;
	}

	void update(Arduboy2 & arduboy)
	{
		if(this->reveal < this->cursor)
		{
			this->reveal++;
		}
		else if(arduboy.justPressed(A_BUTTON))
		{
			this->active = false;
			this->cursor = 0;
		}
	}

	void draw(Arduboy2 & arduboy)
	{
		arduboy.fillRect(1, 44, (WIDTH - 2), 20, BLACK);
		arduboy.drawRect(1, 44, (WIDTH - 2), 20, WHITE);
		
		constexpr uint8_t lineHeight = 8;

		const uint8_t xStart = 4;
		const uint8_t yStart = 46;

		uint8_t index = 0;
		for(uint8_t y = 0; y < RowCount; ++y)
		{
			arduboy.setCursor(xStart, yStart + y * lineHeight);

			for(uint8_t x = 0; x < RowLength; ++x)
			{
				if(index > reveal)
					return;

				arduboy.print(text[index]);

				++index;
			}
		}
	}
};