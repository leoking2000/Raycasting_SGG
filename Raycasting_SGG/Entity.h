#pragma once
#include "Item.h"

/// <summary>
/// This interface represents something that can walk in the Level and use Items(see Item.h)
/// An Entitie that has a position in the Level(see Level.h) and an direction in which is looking.
/// Also is has an Item it can use.
/// By calling the update method the entity will be simulated and show behavior.
/// </summary>
class Entity : public GameObject
{
public:
	Entity(float xPos, float yPos, float xDir, float yDir, const std::string& texture)
		:
		GameObject(xPos, yPos, texture),
		direction(xDir, yDir)
	{
	}

	Vector2 Direction() const { return direction; };
	void SetDirection(const Vector2& newdir) { direction = newdir; };

	void GoForward(float speed)
	{
		position += direction * speed * (graphics::getDeltaTime() / 1000);
		body.SetCenter(position);
	}

	void RotateBy(float rad)
	{
		direction.Rotate(rad * graphics::getDeltaTime() / 1000);
		direction.Normalize();
	}

	void HandleCollision();

	void Update() override 
	{
	}

protected:
	Vector2 direction;  // world space direction
	float speed = 5.0f;

	//Item* item = nullptr;
};
