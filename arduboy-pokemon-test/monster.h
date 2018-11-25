#pragma once
#include "utilities/stat.h"
#include "utilities/FlashString.h"

#include "stringscommon.h"

const PROGMEM char StringSpeciesNone[] = "missingno";
const PROGMEM char StringSpeciesBike[] = "Aye-aye";
const PROGMEM char StringSpeciesDumOctopus[] = "Octoface";
enum class MonsterSpecies : uint8_t
{
	None,	
	AyeAye,
	Octoface,
};

class Monster
{
public:
	MonsterSpecies species = MonsterSpecies::None;
	char * getSpeciesName()
	{
		return "missingno";
	}
};