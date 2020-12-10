#pragma once
#include "Level.h"
#include "Player.h"
#include <vector>

struct Scene
{
	Scene(Player player, Level level) 
		: 
		player(player), 
		level(level) 
	{
	}

	Level level;
	Player player;
	std::vector<GameObject*> gameobjects;
};
