#pragma once
#include <Arduboy2.h>
#include "context.h"

#include "npc.h"
#include "player.h"
#include "tileType.h"

#include "assets/sprites.h"
#include "assets/tiles.h"
	
class World
{
private:
	Arduboy2 & arduboy;
	GameContext & context;

	int16_t cameraX = 0;
	int16_t cameraY = 0;
	
	
	
	//progmem intermediary stuff
	bool npcVisible(uint8_t index);
	
	//World and tiles
	TileType tileLookupSprite(uint8_t tx, uint8_t ty);
	
public:
	Player player;
	
	World(Arduboy2 & arduboy, GameContext & context) : arduboy(arduboy), context(context) {}
	
	void drawWorld();
	void drawStuff();
	
	void setCamera(const int16_t cameraX, const int16_t cameraY);
};