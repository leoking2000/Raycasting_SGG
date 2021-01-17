#include "LevelLoader.h"
#include "Game.h"

void LevelLoader::Do()
{
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());
	game->LoadLevel(levelNum);
}
