#pragma once

const uint8_t MaxNPC = 16;

const int16_t TileWidth = 16;
const int16_t TileHeight = 16;
const int16_t ChunkWidth = 512;
const int16_t ChunkHeight = 512;

enum class Direction : uint8_t
{
	North,
	East,
	South,
	West,
};