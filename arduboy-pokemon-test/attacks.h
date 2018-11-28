#pragma once

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
	ElementType type;
	int8_t power;
	constexpr AttackType(FlashString string, ElementType type, int8_t power) : label(string), type(type), power(power) {}
public:
};

const PROGMEM char attackTest1[] = "punch";
const PROGMEM char attackTest2[] = "flambe";

const PROGMEM AttackType Attacks[] = 
{
	AttackType(asFlashString(attackTest1), ElementType::Normal, 10),
	AttackType(asFlashString(attackTest2), ElementType::Fire, 15),
};