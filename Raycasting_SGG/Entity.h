#pragma once
#include "Item.h"

/// <summary>
/// This interface represents something that can walk in the Level and use Items(see Item.h)
/// An Entitie that has a position in the Level(see Level.h) and an direction in which is looking.
/// Also is has an Item it can use.
/// By calling the update method the entity will be simulated and show complex behavior .
/// </summary>represents
class Entity : public GameObject
{
public:
	Entity(const Vector2& pos, const Vector2& dir)
		:
		GameObject(pos),
		direction(dir)
	{
	}

	Vector2 Direction() const { return direction; };
	void SetDirection(const Vector2& newdir) { direction = newdir; };

	void GoForward(float v)
	{
		position += direction * v;
	}
	void RotateBy(float rad)
	{
		direction.Rotate(rad);
		direction.Normalize();
	}

	void virtual Update(float dt) = 0;

protected:
	Vector2 direction;  // world space direction
	Item* item = nullptr;
};
