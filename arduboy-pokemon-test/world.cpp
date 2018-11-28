#include "world.h"

void World::setCamera(const int16_t cameraX, const int16_t cameraY)
{
	this->cameraX = min(ChunkWidth - WIDTH, max(0, cameraX));
	this->cameraY = min(ChunkHeight - HEIGHT, max(0, cameraY));
}

TileType World::tileLookupSprite(uint8_t tx, uint8_t ty)
{
	if((tx & 1) != 0)
		return TileType::Blank;
	else
		return TileType::Post;
}

bool World::npcVisible(uint8_t index)
{
	return false;
}

void World::drawWorld()
{
	const int16_t offsetX = -cameraX;
	const int16_t offsetY = -cameraY;
	
	const int16_t startX = max(0, cameraX);
	const int16_t startY = max(0, cameraY);
	
	//visiblilty. Untidy but works
	const uint8_t tileLeft = startX / TileWidth;
	const uint8_t tileTop = startY / TileHeight;
	const uint8_t tileRight = tileLeft + ((WIDTH / TileWidth) + 1);
	const uint8_t tileBottom = tileTop + ((HEIGHT / TileHeight) + 1);
	
	int8_t dy = offsetY + (tileTop * TileHeight);
	for(auto iy = tileTop; iy < tileBottom; ++iy)
	{
		int8_t dx = offsetX + (tileLeft * TileWidth);
		for(auto ix = tileLeft; ix < tileRight; ++ix)
		{
			auto tileType = tileLookupSprite(ix, iy);

			Sprites::drawOverwrite(dx, dy, Tiles, static_cast<uint8_t>(tileType));
			
			//arduboy.drawBitmap(dx, dy, tile, TileWidth, TileHeight, WHITE);
			//arduboy.drawBitmap(offsetX + (ix * TileWidth), offsetY + (iy * TileHeight), tile, TileWidth, TileHeight, WHITE);	//more progmem hungry method and probably slower too
			
			dx += TileWidth;
		}
		dy += TileHeight;
	}
	
	/*
	arduboy.setCursor(0, 0);
	arduboy.println(context.world.player.x);
	arduboy.println(context.world.player.y);
	arduboy.print(tileLeft);	arduboy.print(" x ");	arduboy.println(tileRight);
	arduboy.print(tileTop);		arduboy.print(" y ");	arduboy.println(tileBottom);
	*/
}

void World::drawStuff()
{
	const int16_t offsetX = -cameraX;
	const int16_t offsetY = -cameraY;
	
	//npc's
	for(uint8_t i = 0; i < MaxNPC; ++i)
	{
		if(npcVisible(i))
		{
			int16_t x = context.world.npcs[i].x;
			int16_t y = context.world.npcs[i].y;
			arduboy.fillRect(x + offsetX, y + offsetY, TileWidth, TileHeight, WHITE);
		}
	}
	
	//player
	arduboy.fillRect(context.world.player.x + offsetX, context.world.player.y + offsetY, TileWidth, TileHeight, WHITE);
	Sprites::drawOverwrite(context.world.player.x + offsetX, context.world.player.y + offsetY, Sprite::Player, 0);
	//arduboy.drawBitmap(context.world.player.x + offsetX, context.world.player.y + offsetY, Sprite::Player, TileWidth, TileHeight, BLACK);
}