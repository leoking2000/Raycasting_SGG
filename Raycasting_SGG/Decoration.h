#pragma once
#include "IHasHealth.h"
#include <string>

class Decoration : public IHasHealth
{
public:
	Decoration(float xPos, float yPos, float size, float health, const std::string& texture, GameObject::COLLIDERTYPE type = GameObject::COLLIDERTYPE::STATIC)
		:
		body({ xPos, yPos }, size),
		health(health),
		texture(texture),
		type(type)
	{
	}

	GameObject::State getState() const override;
	GameObject::COLLIDERTYPE getColliderType() const override;

	Vector2 Position() const override; // the position in level space.
	graphics::Brush GetBrush() const override; // info to how to draw the object.

	Circle GetBody() const override; // used for collition detection.
	Circle& GetBodyRef() override;

	void virtual Hit(GameObject& other) override; // used for collition response.
	Vector2 Direction() const override; // the direction in level space.
	void Update() override;

	void Damage(float amount) override;

private:
	Circle body;
	float health;
	const std::string texture;

	GameObject::State state = GameObject::State::ACTIVE;
	GameObject::COLLIDERTYPE type;
};