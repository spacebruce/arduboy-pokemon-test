#pragma once

#include "utilities/progmem.h"

enum class ElementType : uint8_t
{
	Normal,
	Fire,
	Water,
	Grass,
};

class AttackData
{
private:
	FlashString label;	//label rather than name because name is a reserved arduino thing
	ElementType element;
public:
	constexpr AttackData(FlashString string, ElementType element, int8_t power) : label(string), element(element), power(power) {}
	
	ElementType getElement()
	{
		return this->element;
	}
	
	FlashString getName()
	{
		return this->label;
	}
};

const PROGMEM char attackTest1[] = "punch";
const PROGMEM char attackTest2[] = "flambe";

const PROGMEM AttackData AttackDefines[] = 
{
	AttackData(asFlashString(attackTest1), ElementType::Normal, 10),
	AttackData(asFlashString(attackTest2), ElementType::Fire, 15),
};

enum class AttackEnum : uint8_t 
{
	Punch,
	Flambe,
};

class AttackType
{
public:
	AttackType();
	AttackType(AttackEnum type) : type(type) {};

	ElementType getElement()
	{
		return pgm_read_pointer(&AttackDefines[static_cast<uint8_t>(type)])->getElement();
	}
	FlashString getName()
	{
		return pgm_read_pointer(&AttackDefines[static_cast<uint8_t>(type)])->getName();
	}
	
private:
	AttackEnum type;
};