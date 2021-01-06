#include "Player.h"
#include "Game.h"

void Player::Update()
{
	if (health <= 0) {
		state = GameObject::State::DEAD;
		return;
	}

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

	if (graphics::getKeyState(graphics::SCANCODE_SPACE))
	{
		graphics::playSound("assets//Audio//Pistol.wav", 1.0f);
	}

}

void Player::Damage(float amount)
{
	health -= amount;
}

GameObject::State Player::getState() const
{
	return state;
}

GameObject::COLLIDERTYPE Player::getColliderType() const
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

	br.texture = "assets//Weapons//pistol_0.png";
	br.outline_opacity = 0.0f;

	return br;
}

Circle Player::GetBody() const
{
	return body;
}

Circle& Player::GetBodyRef()
{
	return body;
}

void Player::Hit(GameObject& other)
{
	switch (other.getColliderType())
	{
	case GameObject::COLLIDERTYPE::STATIC:
		body.ResolveCollisionStatic(other.GetBodyRef());
		break;
	case GameObject::COLLIDERTYPE::DYNAMIC:
		body.ResolveCollisionDynamic(other.GetBodyRef());
		break;
	}

}

Vector2 Player::Direction() const
{
	return direction;
}
