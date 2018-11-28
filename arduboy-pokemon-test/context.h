#pragma once

#include <avr/eeprom.h>
#include "worldDefines.h"
#include "contextWorld.h"
#include "contextStats.h"

#include "Monster.h"

//all shared state lives in here

class GameContext
{
private:
	//"BUTT";
	static constexpr uint32_t magicNumber = 0x42555454;

public:
	static constexpr uintptr_t StartAddress = EEPROM_STORAGE_SPACE_START;
	static constexpr uintptr_t MagicNumberAddress = StartAddress;
	static constexpr uintptr_t WorldAddress = MagicNumberAddress + sizeof(magicNumber);
	static constexpr uintptr_t StatsAddress = WorldAddress + sizeof(ContextWorld);
	static constexpr uintptr_t EndAddress = StatsAddress + sizeof(ContextStats);

public:
	ContextWorld world;
	ContextStats stats;
	
	bool LoadValid()
	{
		const auto magicNumberAddress = reinterpret_cast<const uint32_t *>(MagicNumberAddress);
		return (eeprom_read_dword(magicNumberAddress) == magicNumber);
	}
	
	bool Load()
	{
		if(!LoadValid())
			return false;

		const auto worldAddress = reinterpret_cast<const ContextWorld *>(WorldAddress);
		eeprom_read_block(&world, worldAddress, sizeof(world));

		const auto statsAddress = reinterpret_cast<const ContextStats *>(StatsAddress);
		eeprom_read_block(&stats, statsAddress, sizeof(stats));
		
		return true;
	};
	
	void Save()
	{
		const auto magicNumberAddress = reinterpret_cast<const uint32_t *>(MagicNumberAddress);
		eeprom_write_dword(magicNumberAddress, magicNumber);
		
		const auto worldAddress = reinterpret_cast<const ContextWorld *>(WorldAddress);
		eeprom_write_block(&world, worldAddress, sizeof(ContextWorld));

		const auto statsAddress = reinterpret_cast<const ContextStats *>(StatsAddress);
		eeprom_write_block(&stats, statsAddress, sizeof(ContextStats));
	};
	
	void NewGame()
	{
		stats.party.add(Monster(MonsterSpecies::AyeAye));
		stats.party.add(Monster(MonsterSpecies::Octoface));
	}
};