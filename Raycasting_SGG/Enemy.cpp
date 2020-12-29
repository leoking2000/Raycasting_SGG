#include "Enemy.h"


void Enemy::Update()
{
	if (graphics::getKeyState(graphics::SCANCODE_W))
	{
		GoForward(speed);
	}

	if (graphics::getKeyState(graphics::SCANCODE_S))
	{
		GoForward(-speed);
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
