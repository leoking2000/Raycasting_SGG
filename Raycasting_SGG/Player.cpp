#include "Player.h"
#include "Game.h"

void Player::Update()
{


	if (graphics::getKeyState(graphics::SCANCODE_UP))
	{
		position += direction * speed * (graphics::getDeltaTime() / 1000);
		body.SetCenter(position);
	}

	if (graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		position += direction * (- 1)*speed * (graphics::getDeltaTime() / 1000);
		body.SetCenter(position);
	}

	if (graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		direction.Rotate(-rotationSpeed * graphics::getDeltaTime() / 1000);
		direction.Normalize();
	}

	if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		direction.Rotate(rotationSpeed * graphics::getDeltaTime() / 1000);
		direction.Normalize();
	}
}

GameObject::State Player::getState() const
{
	return state;
}

GameObject::Type Player::getType() const
{
	return type;
}

Vector2 Player::Position() const
{
	return position;
}

graphics::Brush Player::GetBrush() const
{
	graphics::Brush br;

	return br;
}

Rectangle Player::GetBody() const
{
	return body;
}

void Player::Hit(const GameObject& other)
{


}

Vector2 Player::Direction() const
{
	return direction;
}
