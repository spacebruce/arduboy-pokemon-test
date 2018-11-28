#pragma once

#include <stdint.h>

enum class BattleMenu : uint8_t
{
	// Main picker
	Action = 0,
	// Move
	Fight = 1,
	// Run away
	Run = 2,
};