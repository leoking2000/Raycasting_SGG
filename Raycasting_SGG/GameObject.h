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
		DEAD     = 0, // if it is dead it should be deleted from memory. 
		ACTIVE   = 1  // if it is active all ok.
	};
	// the type is used in order to have proper collision response and drawing.
	enum Type
	{
		ENTITY,
		ITEM,
		PROJECTILE
	};
public:
	virtual ~GameObject() {};

	GameObject::State virtual getState() const = 0;
	GameObject::Type virtual getType() const = 0;

	Vector2 virtual Position() const = 0; // the position in level space.
	graphics::Brush virtual GetBrush() const = 0; // info to how to draw the object.

	Rectangle virtual GetBody() const = 0; // used for collition detection.
	void virtual Hit(const GameObject& other) = 0; // used for collition response.
	Vector2 virtual Direction() const = 0; // the direction in level space.
	void virtual Update() { };
};
