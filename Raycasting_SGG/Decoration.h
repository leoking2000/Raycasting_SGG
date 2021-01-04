#pragma once
#include "GameObject.h"
#include <string>

class Decoration : public GameObject
{
public:
public:
	Decoration(float xPos, float yPos, float size, float health, const std::string& texture)
		:
		position(xPos, yPos),
		body(position, size, size),
		health(health),
		texture(texture)
	{
	}

	GameObject::State getState() const override;
	GameObject::Type getType() const override;

	Vector2 Position() const override; // the position in level space.
	graphics::Brush GetBrush() const override; // info to how to draw the object.

	Rectangle GetBody() const override; // used for collition detection.
	void virtual Hit(const GameObject& other) override; // used for collition response.
	Vector2 Direction() const override; // the direction in level space.
	void Update() override;

private:
	Vector2 position;
	Rectangle body;
	float health;
	const std::string texture;

	GameObject::State state = GameObject::State::SLEEPING;
	GameObject::Type type = GameObject::Type::ENTITY;
};