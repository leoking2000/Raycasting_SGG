#include "Player.h"
#include "Game.h"
#include "Key.h"

void Player::Update()
{
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());
	const Level& level = game->GetLevel();

	if (graphics::getKeyState(graphics::SCANCODE_UP) || graphics::getKeyState(graphics::SCANCODE_W))
	{
		Vector2 newPosition = body.GetCenter() + direction * speed * (graphics::getDeltaTime() / 1000);
		if (level.Get(int(newPosition.x), int(newPosition.y)) == ' ')
		{
			body.SetCenter(newPosition);
		}	
	}

	if (graphics::getKeyState(graphics::SCANCODE_DOWN) || graphics::getKeyState(graphics::SCANCODE_S))
	{
		Vector2 newPosition = body.GetCenter() + direction * (-1) * speed * (graphics::getDeltaTime() / 1000);
		if (level.Get(int(newPosition.x), int(newPosition.y)) == ' ')
		{
			body.SetCenter(newPosition);
		}
	}

	if (graphics::getKeyState(graphics::SCANCODE_LEFT) || graphics::getKeyState(graphics::SCANCODE_A))
	{
		direction.Rotate(-rotationSpeed * graphics::getDeltaTime() / 1000);
		direction.Normalize();
	}

	if (graphics::getKeyState(graphics::SCANCODE_RIGHT) || graphics::getKeyState(graphics::SCANCODE_D))
	{
		direction.Rotate(rotationSpeed * graphics::getDeltaTime() / 1000);
		direction.Normalize();
	}

	if (graphics::getKeyState(graphics::SCANCODE_SPACE) && timePassed >= usePeriod)
	{
		if (item != nullptr) { item->OnUse(); timePassed = 0; }
	}
	else
	{
		if (timePassed < usePeriod)
		{
			timePassed += graphics::getDeltaTime();
		}	
	}

}

void Player::Damage(float amount)
{
	health -= amount;
	if (health <= 0) {
		state = GameObject::State::DEAD;
		graphics::playSound("assets\\Audio\\Player_Dies.wav", 1.0f);
		return;
	}

	graphics::playSound("assets\\Audio\\Human_Hurt.wav", 1.0f);
}

float Player::GetHealth() const
{
	return health;
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
	if (item != nullptr) return item->GetBrush();

	graphics::Brush br;

	br.fill_opacity = 0.0f;
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
	case GameObject::COLLIDERTYPE::TRIGGER:
		if (item == nullptr)
		{
			item = dynamic_cast<Item*>(&other);
			if (item != nullptr)
			{
				item->Onpickup(*this);
			}
			break;
		}
	}

}

Vector2 Player::Direction() const
{
	return direction;
}
