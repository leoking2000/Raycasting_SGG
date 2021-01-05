#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(float xPos, float yPos, float xDir, float yDir, float speed,float rotationSpeed)
		:
		direction(xDir, yDir),
		body({ xPos, yPos }, 0.25f),
		speed(speed),
		rotationSpeed(rotationSpeed)
	{
	}

	GameObject::State getState() const override;
	GameObject::Type getType() const override;

	Vector2 Position() const override; // the position in level space.
	graphics::Brush GetBrush() const override; // info to how to draw the object.

	Circle GetBody() const override; // used for collition detection.
	void virtual Hit(const GameObject& other) override; // used for collition response.
	Vector2 Direction() const override; // the direction in level space.
	void Update() override;

private:
	Vector2 direction;
	Circle body;
	float speed;
	float rotationSpeed;
	
	GameObject::State state = GameObject::State::ACTIVE;
	GameObject::Type type = GameObject::Type::ENTITY;
};

