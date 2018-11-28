#pragma once

#include <stdint.h>

enum class BattlePhase : uint8_t
{
	Intro,
	Select,
	Attack1,
	Attack2,
	Victory,
	Defeat,
};