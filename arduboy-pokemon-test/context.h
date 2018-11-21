#pragma once

#include <avr/eeprom.h>
#include "worldEnums.h"
#include "contextWorld.h"
#include "contextStats.h"

//all shared state lives in here

class GameContext
{
private:
	const char magicName[] = "BUTT";
public:
	ContextWorld world;
	ContextStats stats;
	
	bool LoadValid()
	{
		size_t address = EEPROM_STORAGE_SPACE_START;
		char check[4];
		eeprom_read_block(check, address, sizeof(magicName));
		return (strcmp(check, magicName));
	}
	
	bool Load()
	{
		if(!LoadValid())
			return false;

		size_t address = EEPROM_STORAGE_SPACE_START;

		eeprom_read_block(&world, address + sizeof(magicName), sizeof(world));
		eeprom_read_block(&stats, address + sizeof(magicName) + sizeof(world), sizeof(stats));
		
		return true;
	};
	
	void Save()
	{
		size_t address = EEPROM_STORAGE_SPACE_START;
		
		eeprom_write_block(magicName, address, sizeof(magicName));	address += sizeof(magicName);
		
		eeprom_write_block(&world, address, sizeof(ContextWorld));	address += sizeof(ContextWorld);
		eeprom_write_block(&stats, address, sizeof(ContextStats));
	};
};