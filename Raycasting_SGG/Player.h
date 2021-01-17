#pragma once
#include "IHasHealth.h"
#include "Item.h"

class Player : public IHasHealth
{
public:
	Player(float xPos, float yPos, float xDir, float yDir, float health, float speed, float rotationSpeed)
		:
		direction(xDir, yDir),
		body({ xPos, yPos }, 0.5f),
		speed(speed),
		rotationSpeed(rotationSpeed),
		health(health)
	{
	}

	GameObject::State getState() const override;
	GameObject::COLLIDERTYPE getColliderType() const override;

	Vector2 Position() const override;
	graphics::Brush GetBrush() const override;

	Circle GetBody() const override;
	Circle& GetBodyRef() override;

	void virtual Hit(GameObject& other) override;
	Vector2 Direction() const override;
	void Update() override;

	void Damage(float amount) override;
	float GetHealth() const override;

private:
	Vector2 direction;
	Circle body;
	float speed;
	float rotationSpeed;
	float health;

	Item* item = nullptr;

	const float usePeriod = 300; // in milliseconds
	float timePassed = 0;
	
	GameObject::State state = GameObject::State::ACTIVE;
	GameObject::COLLIDERTYPE type = GameObject::COLLIDERTYPE::DYNAMIC;
};

