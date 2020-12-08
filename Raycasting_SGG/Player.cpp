#include "Player.h"


void Player::Update(float dt)
{
	const float multiplier = dt / 1000.0f;

	if (graphics::getKeyState(graphics::SCANCODE_UP))
	{
		GoForward(5.0f * multiplier);
	}

	if (graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		GoForward(-5.0f * multiplier);
	}

	if (graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		RotateBy(-2.0f * multiplier);
	}

	if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		RotateBy(2.0f * multiplier);
	}
}

