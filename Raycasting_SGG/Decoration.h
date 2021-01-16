#pragma once
#include "IHasHealth.h"
#include <string>

class Decoration : public IHasHealth
{
public:
	static Decoration* Make_Barrel(float x,float y )
	{
		return new Decoration(x, y, 0.5f, 5.0f, std::string("assets//Entities//barrel.png"),
			std::string("assets\\Audio\\mixkit-wood-hard-hit-2182.wav"));
	}

	static Decoration* Make_Pillar(float x, float y)
	{
		return new Decoration(x, y, 0.5f, 5.0f, std::string("assets//Entities//pillar.png"),
			std::string(""));
	}

	static Decoration* Make_GreenLight(float x, float y)
	{
		return new Decoration(x + 0.5f, y + 0.5f, 0.5f, 1.0f, std::string("assets//Entities//greenlight.png"),
			std::string(""), GameObject::COLLIDERTYPE::INACTIVE);
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
	float GetHealth() const override;

private:
	Decoration(float xPos, float yPos, float size, float health,
		const std::string& texture, const std::string& soundHit, GameObject::COLLIDERTYPE type = GameObject::COLLIDERTYPE::STATIC)
		:
		body({ xPos, yPos }, size),
		health(health),
		texture(texture),
		soundHit(soundHit),
		type(type)
	{
	}


	Circle body;
	float health;
	const std::string texture;
	const std::string soundHit;

	GameObject::State state = GameObject::State::ACTIVE;
	GameObject::COLLIDERTYPE type;
};