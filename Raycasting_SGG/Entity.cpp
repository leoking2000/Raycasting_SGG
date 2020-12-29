#include "Entity.h"
#include "Game.h"

void Entity::HandleCollision()
{
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());
	const Level& level = game->GetLevel();

	if (level.Get((int)position.x, (int)position.y) != ' ')
	{
		if (graphics::getKeyState(graphics::SCANCODE_UP)) { GoForward(-speed); }
		if (graphics::getKeyState(graphics::SCANCODE_DOWN)) { GoForward(speed); }
	}

	for (GameObject* obj : level.GameObjects())
	{

		if (body.isCollidingWith(obj->getRectangle()))
		{
			if (graphics::getKeyState(graphics::SCANCODE_UP)) { GoForward(-speed); break; }
			if (graphics::getKeyState(graphics::SCANCODE_DOWN)) { GoForward(speed); break; }
		}
	}
}
