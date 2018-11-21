#pragma once
#include "menuDefines.h"
#include "utilities/FlashString.h"

class Menu
{
public:
	const MenuItem * items;
	uint8_t size;
	uint8_t selected = 0;
	
public:	
	Menu(const MenuItem items[], const uint8_t size)
		: items(items), size(size)
	{
	}
	
	template< size_t size >
	Menu(const MenuItem (&items)[size])
		: items(items), size(size)
	{
	}
	
	// (to aru majutsu no) Index
	uint8_t getFirstIndex() const
	{
		return 0;
	}
	
	uint8_t getLastIndex() const
	{
		return (this->size - 1);
	}
	
	uint8_t getEndIndex() const
	{
		return this->size;
	}
	
	uint8_t getSelectedIndex() const
	{
		return this->selected;
	}
	
	uint8_t getPreviousIndex() const
	{
		return (this->selected > this->getFirstIndex()) ? (this->selected - 1) : this->getLastIndex();	
	}
	
	uint8_t getNextIndex() const
	{
		return (this->selected < this->getLastIndex()) ? (this->selected + 1) : this->getFirstIndex();
	}
	
	void selectFirstIndex()
	{
		this->selected = getFirstIndex();
	}
	
	void selectPreviousIndex()
	{
		this->selected = this->getPreviousIndex();
	}
	
	void selectNextIndex()
	{
		this->selected = this->getNextIndex();
	}
	
	// values
	MenuReturn getValue(uint8_t index)
	{
		return static_cast<MenuReturn>(pgm_read_byte(&items[index].result));
	}
	
	MenuReturn getCurrentValue()
	{
		return this->getValue(this->selected);
	}
	
	// strings
	FlashString getString(int8_t index)
	{
		return asFlashString(pgm_read_ptr(&items[index].string));
	}
	
	void print(Arduboy2 & arduboy)
	{
		for (auto i = this->getFirstIndex(); i < this->getEndIndex(); ++i)
			arduboy.print(getString(i));
	}
	
	void print(Arduboy2 & arduboy, int8_t x, int8_t y)
	{
		for (auto i = this->getFirstIndex(); i < this->getEndIndex(); ++i)
		{
			arduboy.setCursor(x, y);
			arduboy.print(getString(i));
			y += 8;
		}
	}
};