#pragma once
#include "IHasHealth.h"
#include <string.h>

class Enemy : public IHasHealth
{
public:
	static Enemy* Make_Ghost(float xPos, float yPos)
	{
		return new Enemy(xPos, yPos, 500.0f, 2.0f,
			std::string("assets\\Enemies\\ghost2.png"), std::string("assets\\Audio\\ghost_hurt.wav"), GameObject::COLLIDERTYPE::TRIGGER);
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
	Enemy(float xPos, float yPos, float health, float speed, 
		const std::string& texture,const std::string& soundHurt, GameObject::COLLIDERTYPE type);

	Circle body;
	float speed;
	float health;
	const std::string texture;
	const std::string soundHurt;

	GameObject::State state = GameObject::State::ACTIVE;
	GameObject::COLLIDERTYPE type = GameObject::COLLIDERTYPE::DYNAMIC;
};

