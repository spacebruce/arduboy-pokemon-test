#pragma once
#include "utilities/stat.h"
#include "utilities/FlashString.h"

#include "stringscommon.h"

const PROGMEM char StringSpeciesNone[] = "missingno";
const PROGMEM char StringSpeciesAyeAye[] = "Aye-aye";
const PROGMEM char StringSpeciesOctoFace[] = "Octoface";

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