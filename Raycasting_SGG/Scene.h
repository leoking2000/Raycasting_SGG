#pragma once
#include "Level.h"
#include "Player.h"

struct Scene
{
	Scene(Player player, Level level) : player(player), level(level) {}

	Level level;
	Player player;
};
