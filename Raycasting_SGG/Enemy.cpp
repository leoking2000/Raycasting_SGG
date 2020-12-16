#include "Enemy.h"

graphics::Brush Enemy::getBrush() const
{
	graphics::Brush sprite;

	sprite.texture = "assets//barrel.png";
	sprite.outline_opacity = 0.0f;

	return sprite;
}

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
