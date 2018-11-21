#pragma once
#include <avr/pgmspace.h>
#include "utilities/FlashString.h"

enum class ElementType : uint8_t
{
	Normal,
	Fire,
	Water,
	Grass,
};

struct AttackType
{
	FlashString label;	//label rather than name because name is a reserved arduino thing
	ElementType type;
	int8_t power;
	constexpr AttackType(FlashString string, ElementType type, int8_t power) : label(string), type(type), power(power) {}
};

const PROGMEM char attackTest1[] = "TestAttack1";
const PROGMEM char attackTest2[] = "TestAttack2";

const PROGMEM AttackType Attacks[] = 
{
	AttackType(asFlashString(attackTest1), ElementType::Normal, 10),
	AttackType(asFlashString(attackTest2), ElementType::Fire, 15),
};