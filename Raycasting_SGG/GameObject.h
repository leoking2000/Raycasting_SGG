#pragma once
#include "Vector2.h"
#include "graphics.h"

/// <summary>
/// This interface represents something that has a position in the Level(see Level.h).
/// It is used by the camera to draw the Entities and Items.
/// </summary>
class GameObject
{
public:
	GameObject() 
		: 
		position(0.0f,0.0f)
	{}

	GameObject(const Vector2& pos) 
		: 
		position(pos)
	{}

	Vector2 Position() const { return position; }
	void SetPosition(const Vector2& newpos) { position = newpos; }

	graphics::Brush virtual getBrush() const = 0; // gives the info the camera needs to draw the object.

protected:
	Vector2 position; // world space position

};
