#pragma once

#include "utilities/progmem.h"

enum class ElementType : uint8_t
{
	Normal,
	Fire,
	Water,
	Grass,
};

struct AttackData
{
	constexpr AttackData(FlashString name, ElementType element, int8_t(power) : name(name), element(element), power(power) {}

	FlashString name;
	ElementType element;
	uint8_t power;
};

const PROGMEM char attackTest1[] = "punch";
const PROGMEM char attackTest2[] = "flambe";

const PROGMEM AttackData AttackDefines[] = 
{
	AttackData(asFlashString(attackTest1), ElementType::Normal, 10),
	AttackData(asFlashString(attackTest2), ElementType::Fire, 15),
};

enum class AttackID : uint8_t 
{
	Punch,
	Flambe,
};

ElementType AttackGetElement(AttackID type)
{
	return static_cast<ElementType>(pgm_read_byte(&(AttackDefines[static_cast<uint8_t>(type)].element)));
}
		
FlashString AttackGetName(AttackID type)
{
	return static_cast<FlashString>(pgm_read_byte(&(AttackDefines[static_cast<uint8_t>(type)].label)));
}
	

class Attack
{
public:
	Attack();
	Attack(AttackID type) : type(type) {};

	ElementType getElement()
	{
		return AttackGetElement(type);
	}
	
	FlashString getName()
	{
		return AttackGetName(type);
	}
	
private:
	AttackID type;
};