#include "world.h"

void World::setCamera(const int16_t cameraX, const int16_t cameraY)
{
	this->cameraX = min(ChunkWidth - WIDTH, max(0, cameraX));
	this->cameraY = min(ChunkHeight - HEIGHT, max(0, cameraY));
}

char * World::tileLookupSprite(uint8_t tx, uint8_t ty)
{
	uint8_t chunkx = tx / ChunkWidth;
	uint8_t chunky = ty / ChunkHeight;
	if(tx & 1)
		return Tiles::Blank;
	else
		return Tiles::Post;
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
	const int16_t tileLeft = startX / TileWidth;
	const int16_t tileTop = startY / TileHeight;
	const int16_t tileRight = min(ChunkWidth / TileWidth, min(((cameraX + WIDTH) / TileWidth) + 1, ((startX / TileWidth) + 2) + (WIDTH / TileWidth)));
	const int16_t tileBottom = min(ChunkHeight / TileHeight, min(((cameraY + HEIGHT) / TileHeight) + 1, ((startY / TileHeight) + 2) + (HEIGHT / TileHeight)));
	
	int16_t dy = offsetY + (tileTop * TileHeight);
	for(auto iy = tileTop; iy < tileBottom; ++iy)
	{
		int16_t dx = offsetX + (tileLeft * TileWidth);
		for(auto ix = tileLeft; ix < tileRight; ++ix)
		{
			auto tile = tileLookupSprite(ix, iy);
			
			arduboy.drawBitmap(dx, dy, tile, TileWidth, TileHeight, WHITE);
			//arduboy.drawBitmap(offsetX + (ix * TileWidth), offsetY + (iy * TileHeight), tile, TileWidth, TileHeight, WHITE);	//more progmem hungry method and probably slower too
			
			dx += TileWidth;
		}
		dy += TileHeight;
	}
	
	/*
	arduboy.setCursor(0, 0);
	arduboy.println(context.world.playerX);
	arduboy.println(context.world.playerY);
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
			int16_t x = context.world.npcX[i];
			int16_t y = context.world.npcY[i];
			arduboy.fillRect(x + offsetX, y + offsetY, TileWidth, TileHeight, WHITE);
		}
	}
	
	//player
	arduboy.fillRect(context.world.playerX + offsetX, context.world.playerY + offsetY, TileWidth, TileHeight, WHITE);
	arduboy.drawBitmap(context.world.playerX + offsetX, context.world.playerY + offsetY, Sprite::Player, TileWidth, TileHeight, BLACK);
}