#pragma once

#include "contextStats.h"

class MonsterMenu
{
private:
	ContextStats &stats;
public:
	MonsterMenu(ContextStats & stats) : stats(stats) {};
};