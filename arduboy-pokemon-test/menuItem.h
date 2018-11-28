#pragma once

#include "utilities/FlashString.h"
#include "menuReturn.h"

struct MenuItem
{
	FlashString string;
	MenuReturn result;

	constexpr MenuItem(FlashString string, MenuReturn result)
		: string(string), result(result) {}
};