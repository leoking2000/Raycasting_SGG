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
	Entity()
		:
		GameObject(0.0f,0.0f),
		direction(0.0f,1.0f)
	{
	}
	Entity(float xPos, float yPos, float xDir, float yDir)
		:
		GameObject(xPos, yPos),
		direction(xDir, yDir)
	{
	}
	Entity(const Vector2& pos, const Vector2& dir)
		:
		GameObject(pos),
		direction(dir)
	{
	}

	Vector2 Direction() const { return direction; };
	void SetDirection(const Vector2& newdir) { direction = newdir; };

	void GoForward(float speed)
	{
		position += direction * speed * (graphics::getDeltaTime() / 1000);
	}
	void RotateBy(float rad)
	{
		direction.Rotate(rad * graphics::getDeltaTime() / 1000);
		direction.Normalize();
	}

	void virtual Update() = 0;

protected:
	Vector2 direction;  // world space direction
	Item* item = nullptr;
};
