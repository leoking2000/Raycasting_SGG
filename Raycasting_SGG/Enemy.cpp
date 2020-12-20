#include "Enemy.h"


void Enemy::Update()
{
	if (graphics::getKeyState(graphics::SCANCODE_W))
	{
		GoForward(5.0f);
	}

	if (graphics::getKeyState(graphics::SCANCODE_S))
	{
		GoForward(-5.0f);
	}

	if (graphics::getKeyState(graphics::SCANCODE_A))
	{
		RotateBy(-2.0f);
	}

	if (graphics::getKeyState(graphics::SCANCODE_D))
	{
		RotateBy(2.0f);
	}

}
