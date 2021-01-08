#pragma once
#include "Item.h"


class Weapon : public Item
{
public:
	static Weapon* Make_Pistol(const Vector2& pos);

	GameObject::State getState() const final;
	GameObject::COLLIDERTYPE getColliderType() const final;

	Vector2 Position() const final; // the position in level space.
	graphics::Brush GetBrush() const final; // info to how to draw the object.

	Circle GetBody() const final; // used for collition detection.
	Circle& GetBodyRef() final;

	void virtual Hit(GameObject& other) final; // used for collition response.
	void Update() final;
	Vector2 virtual Direction() const final; // the direction in level space.
	
	void Onpickup(GameObject& user) override;
	void OnUse() override;

private:
	Weapon(float xPos, float yPos, float damage);

	Vector2 position;
	Circle body;
	bool isOnGround = true;
	GameObject* user = nullptr;

	float damage;

	GameObject::State state = GameObject::State::ACTIVE;
	GameObject::COLLIDERTYPE type = GameObject::COLLIDERTYPE::TRIGGER;

};

