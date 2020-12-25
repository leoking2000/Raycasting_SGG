#include "Player.h"
#include "Game.h"

void Player::Update()
{
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());
	const Level& level = game->GetLevel();

	if (graphics::getKeyState(graphics::SCANCODE_UP))
	{
		GoForward(5.0f);
		if (level.Get((int)position.x, (int)position.y) != ' ')
		{
			GoForward(-5.0f);
		}
	}

	if (graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		GoForward(-5.0f);
		if (level.Get((int)position.x, (int)position.y) != ' ')
		{
			GoForward(5.0f);
		}
	}

	if (graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		RotateBy(-2.0f);
	}

	if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		RotateBy(2.0f);
	}

}

