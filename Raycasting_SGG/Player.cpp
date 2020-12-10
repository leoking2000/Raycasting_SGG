#include "Player.h"


graphics::Brush Player::getBrush() const
{
	return graphics::Brush();
}

void Player::Update()
{

	if (graphics::getKeyState(graphics::SCANCODE_UP))
	{
		GoForward(5.0f);
	}

	if (graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		GoForward(-5.0f);
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

