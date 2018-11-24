#pragma once
#include "utilities/List.h"
#include "monster.h"

struct ContextStats
{
public:
	//player
	constexpr static uint8_t nameLength = 8;
	char playerName[nameLength + 1] = "";
	uint16_t playerMoney = 0;
	
	//monster data...
	List<Monster, 6> Party;	
};