#pragma once
#include "GameObject.h"


class Bullet : public GameObject
{
public:
	Bullet(float xPos, float yPos, float xVel, float yVel, float damage);

	GameObject::State getState() const override;
	GameObject::COLLIDERTYPE getColliderType() const override;

	Vector2 virtual Position() const override; // the position in level space.
	graphics::Brush virtual GetBrush() const override; // info to how to draw the object.

	Circle virtual GetBody() const override; // used for collition detection.
	virtual Circle& GetBodyRef() override;

	Vector2 virtual Direction() const override; // the direction in level space.
	void Hit(GameObject& other) override; // used for collition response.
	void Update() override;
private:
	Circle body;
	Vector2 velocity;
	float amountOfDamage;

	GameObject::State state = GameObject::State::ACTIVE;
	GameObject::COLLIDERTYPE type = GameObject::COLLIDERTYPE::TRIGGER;
};

