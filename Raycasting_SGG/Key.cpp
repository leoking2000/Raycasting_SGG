#include "Key.h"
#include "Player.h"
#include "Game.h"

Key::Key(float xPos, float yPos)
	:
	body({ xPos, yPos }, 0.5f)
{
}

void Key::Hit(GameObject& other)
{
	if (dynamic_cast<Player*>(&other) == nullptr) { return; }

	if (pickedUp == false)
	{
		Game* game = reinterpret_cast<Game*>(graphics::getUserData());
		Level& level = game->GetLevel();

		level.KeyPickUp();

		state = GameObject::State::DEAD;
		graphics::playSound("assets\\Audio\\Pickup.wav", 1.0f);
		pickedUp = true;
	}
}

GameObject::State Key::getState() const
{
	return state;
}

GameObject::COLLIDERTYPE Key::getColliderType() const
{
	return type;
}

Vector2 Key::Position() const
{
	return body.GetCenter();
}

graphics::Brush Key::GetBrush() const
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = "assets\\Entities\\key.png";

	return br;
}

Circle Key::GetBody() const
{
	return body;
}

Circle& Key::GetBodyRef()
{
	return body;
}



void Key::Update()
{
}

Vector2 Key::Direction() const
{
	return Vector2(0.0f,0.0f);
}
