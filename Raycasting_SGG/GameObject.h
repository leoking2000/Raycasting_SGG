#pragma once
#include "Rectangle.h"
#include "graphics.h"

/// <summary>
/// 
/// 
/// </summary>
class GameObject
{
public:
	enum State
	{
		DEAD,     // if it is dead it should be deleted from memory. 
		INACTIVE, // if it is inactive it should not be drawn or update.
		SLEEPING, // if it is sleeping it should not be updated.
		ACTIVE    // if it is active all ok.
	};
	// the type is used in order to have proper collision response and drawing.
	enum Type
	{
		ENTITY,
		ITEM,
		PROJECTILE,
		UI
	};
public:
	GameObject::State getState();

	Vector2 virtual Position() const = 0;
	graphics::Brush virtual GetBrush() const = 0;

	Rectangle virtual GetBody() const = 0;
	Vector2 virtual Direction() const = 0;
	void virtual Update() { };
private:
	State state;
	Type type;
};
