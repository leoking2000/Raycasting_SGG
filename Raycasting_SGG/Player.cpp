#include "Player.h"
#include "Game.h"

void Player::Update()
{
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());
	const Level& level = game->GetLevel();

	if (graphics::getKeyState(graphics::SCANCODE_UP))
	{
		Vector2 newPosition = body.GetCenter() + direction * speed * (graphics::getDeltaTime() / 1000);
		if (level.Get(int(newPosition.x), int(newPosition.y)) == ' ')
		{
			body.SetCenter(newPosition);
		}	
	}

	if (graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		Vector2 newPosition = body.GetCenter() + direction * (-1) * speed * (graphics::getDeltaTime() / 1000);
		if (level.Get(int(newPosition.x), int(newPosition.y)) == ' ')
		{
			body.SetCenter(newPosition);
		}
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
	return body.GetCenter();
}

graphics::Brush Player::GetBrush() const
{
	graphics::Brush br;

	return br;
}

Circle Player::GetBody() const
{
	return body;
}

void Player::Hit(const GameObject& other)
{
	switch (other.getType())
	{
	case GameObject::Type::ENTITY:
		Vector2 moveDir = (body.GetCenter() - other.GetBody().GetCenter());
		const float moveBy = body.GetRadious() + other.GetBody().GetRadious() - moveDir.GetLength();

		Vector2 newPosition = body.GetCenter() + moveDir.Normalize() * moveBy;
		body.SetCenter(newPosition);
		break;
	}

}

Vector2 Player::Direction() const
{
	return direction;
}
