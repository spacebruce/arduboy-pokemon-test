#pragma once
#include "utilities/stat.h"
#include "utilities/FlashString.h"

#include "stringscommon.h"

#include "attacks.h"

const PROGMEM char StringSpeciesNone[] = "-";
const PROGMEM char StringSpeciesAyeAye[] = "Aye-aye";
const PROGMEM char StringSpeciesOctoFace[] = "Octoface";

//ensure this matches up with species enum!!!
const PROGMEM FlashString stringSpeciesName[] = 
{
	asFlashString(StringSpeciesNone), 
	asFlashString(StringSpeciesAyeAye), 
	asFlashString(StringSpeciesOctoFace),
};

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
	
	Attack attacks[4];
	
	FlashString getSpeciesName()
	{
		return asFlashString(pgm_read_ptr(&stringSpeciesName[static_cast<uint8_t>(species)]));
	}
	
	Monster(void) = default;
	Monster(MonsterSpecies species) : species(species) {};
};