#pragma once
#include <Arduino.h>

/*
	pinched from https://github.com/filmote/SimpleTextEntry
*/

namespace NameHelper
{
	// Note that constexpr implies inline linkage
	constexpr bool isUpper(char c)
	{
		return (c >= 'A' && c <= 'Z');
	}
	
	constexpr bool isLower(char c)
	{
		return (c >= 'a' && c <= 'z');
	}
	
	constexpr bool isAlpha(char c)
	{
		return (isLower(c) || isUpper(c));
	}
}

template< uint8_t LengthValue >
class NameEditor
{
public:
	constexpr static const uint8_t Length = LengthValue;
	constexpr static const uint8_t FirstIndex = 0;
	constexpr static const uint8_t LastIndex = Length - 1;
	constexpr static const uint8_t NullIndex = Length;

private:	 
	uint8_t index;
	char name[Length + 1];
	uint8_t stringLength = 0;
public:
	NameEditor(void)
	{
		this->name[NullIndex] = '\0';
		this->clear();
	}

	constexpr uint8_t getLength(void) const
	{
		return Length;
	}
	
	uint8_t getTrimmedBegin(void) const
	{
		for(uint8_t i = FirstIndex; i < Length; ++i)
			if(name[i] != ' ')
				return i;

		return Length;
	}
	
	uint8_t getTrimmedEnd(void) const
	{
		for(uint8_t i = Length; i > FirstIndex; --i)
			if(name[i - 1] != ' ')
				return i;

		return FirstIndex;
	}

	uint8_t getCharIndex(void)
	{
		return this->index;	
	}
	
	char getChar(uint8_t index) const
	{
		return this->name[index];
	}
	
	void setCharIndex(uint8_t value)
	{
		this->index = value;	
	}
	
	void setChar(uint8_t index, char value)
	{
		this->name[index] = value;
	}

	void incrementCharIndex(void)
	{
		if (this->index < LastIndex)
			++this->index;
	}
	
	void decrementCharIndex(void)
	{
		if (this->index > FirstIndex)
			--this->index;	
	}
	
	void incrementChar(void)
	{
		this->incrementChar(this->index);
	}
	
	void incrementChar(uint8_t index)
	{
		const char c = this->name[index];
		if(c == ' ')
		{
			this->name[index] = 'A';
		}
		else if(c == 'z')
		{
			this->name[index] = ' ';
		}
		else if(c == 'Z')
		{
			this->name[index] = 'a';
		}
		else if((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z'))
		{
			++this->name[index];
		}
	}
	
	void decrementChar(void)
	{
		this->decrementChar(this->index);
	}
	
	void decrementChar(uint8_t index)
	{
		const char c = this->name[index];
		if(c == ' ')
		{
			this->name[index] = 'z';
		}
		else if(c == 'A')
		{
			this->name[index] = ' ';
		}
		else if(c == 'a')
		{
			this->name[index] = 'Z';
		}
		else if((c > 'a' && c <= 'z') || (c > 'A' && c <= 'Z'))
		{
			--this->name[index];
		}
	}
	
	char * getString(void)
	{
		return this->name;	
	}
	
	const char * getString(void) const
	{
		return this->name;	
	}
	
	char operator[](uint8_t index) const
	{
		return this->name[index];
	}
	
	void clear()
	{
		this->index = 0;
			
		for(uint8_t i = 0; i < Length; ++i)
			this->name[i] = ' ';
	}
};
