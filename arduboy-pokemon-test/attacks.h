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
	ElementType element;
	int8_t power;
public:
	constexpr AttackType(FlashString string, ElementType element, int8_t power) : label(string), element(element), power(power) {}
	
	int8_t getPower()
	{
		return this->power;
	}
	
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
	AttackType(asFlashString(attackTest1), ElementType::Normal, 10),
	AttackType(asFlashString(attackTest2), ElementType::Fire, 15),
};

enum class AttackEnum : uint8_t 
{
	Punch,
	Flambe,
};

class AttackType
{
public:
	AttackEnum getElement()
	{
		return AttackDefines[static_cast<uint8_t>(type)].getType();
	}
private:
	AttackEnum type;
}