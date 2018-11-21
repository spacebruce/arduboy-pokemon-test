#pragma once

#include <avr/eeprom.h>
#include "worldEnums.h"
#include "contextWorld.h"
#include "contextStats.h"

//all shared state lives in here

class GameContext
{
private:
	//"BUTT";
	static constexpr uint32_t magicNumber = 0x42555454;

public:
	ContextWorld world;
	ContextStats stats;
	
	bool LoadValid()
	{
		size_t address = EEPROM_STORAGE_SPACE_START;
		return (eeprom_read_dword(address) == magicNumber);
	}
	
	bool Load()
	{
		if(!LoadValid())
			return false;

		size_t address = EEPROM_STORAGE_SPACE_START;

		eeprom_read_block(&world, address + sizeof(magicNumber), sizeof(world));
		eeprom_read_block(&stats, address + sizeof(magicNumber) + sizeof(world), sizeof(stats));
		
		return true;
	};
	
	void Save()
	{
		size_t address = EEPROM_STORAGE_SPACE_START;
		
		eeprom_write_dword(address, magicNumber);	address += sizeof(magicNumber);
		
		eeprom_write_block(&world, address, sizeof(ContextWorld));	address += sizeof(ContextWorld);
		eeprom_write_block(&stats, address, sizeof(ContextStats));
	};
};