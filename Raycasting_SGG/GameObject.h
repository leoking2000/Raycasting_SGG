#pragma once
#include "Circle.h"
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
	// the type is used in order to have proper collision response.
	enum COLLIDERTYPE
	{
		INACTIVE = 0,  // ignore the collider
		TRIGGER  = 1,  // is a trigger or an sensors
		STATIC   = 2,  // it does not move when a collition happens.
		DYNAMIC  = 3   // it moves
	};
public:
	virtual ~GameObject() {};

	GameObject::State virtual getState() const = 0;
	GameObject::COLLIDERTYPE virtual getColliderType() const = 0;

	Vector2 virtual Position() const = 0; // the position in level space.
	graphics::Brush virtual GetBrush() const = 0; // info to how to draw the object.

	Circle virtual GetBody() const = 0; // used for collition detection.
	virtual Circle& GetBodyRef() = 0;

	Vector2 virtual Direction() const = 0; // the direction in level space.
	void virtual Hit(GameObject& other) = 0; // used for collition response.
	void virtual Update() { };
};
