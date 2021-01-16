#pragma once
#include "GameObject.h"

class Key : public GameObject
{
public:
	static Key* Make_key(float x, float y)
	{
		return new Key(x, y);
	}

	GameObject::State getState() const final;
	GameObject::COLLIDERTYPE getColliderType() const final;

	Vector2 Position() const final; // the position in level space.
	graphics::Brush GetBrush() const final; // info to how to draw the object.

	Circle GetBody() const final; // used for collition detection.
	Circle& GetBodyRef() final;

	void virtual Hit(GameObject& other) final; // used for collition response.
	void Update() final;
	Vector2 virtual Direction() const final; // the direction in level space.

private:
	Key(float xPos, float yPos);

	Circle body;
	bool pickedUp = false;

	GameObject::State state = GameObject::State::ACTIVE;
	GameObject::COLLIDERTYPE type = GameObject::COLLIDERTYPE::TRIGGER;
};

