#include "Player.h"

void Player::Update()
{

	if (graphics::getKeyState(graphics::SCANCODE_UP))
	{
		GoForward(speed);
	}

	if (graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		GoForward(-speed);
	}

	if (graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		RotateBy(-2.0f);
	}

	if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		RotateBy(2.0f);
	}

	HandleCollision();
}

