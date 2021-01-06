#pragma once
#include "GameObject.h"

class Item : public GameObject
{
public:
	bool IsOnGround() const { return isOnGround; }

	GameObject::State getState() const final;
	GameObject::COLLIDERTYPE getColliderType() const final;

	void virtual Hit(GameObject& other) final; // used for collition response.
	void Update() final;
	Vector2 virtual Direction() const final; // the direction in level space.

	void virtual Onpickup() = 0;
	void virtual OnUse() = 0;

protected:
	bool isOnGround = true;

	GameObject::State state = GameObject::State::ACTIVE;
	GameObject::COLLIDERTYPE type = GameObject::COLLIDERTYPE::TRIGGER;
};
