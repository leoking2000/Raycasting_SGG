#pragma once
#include "Rectangle.h"
#include "graphics.h"
#include <string>

/// <summary>
/// This interface represents something that has a position in the Level(see Level.h).
/// It is used by the camera to draw the Entities and Items.
/// </summary>
class GameObject
{
public:
	GameObject(float xPos, float yPos, const std::string& texture)
		:
		position(xPos, yPos),
		texture(texture),
		body(position, 0.7f, 0.7f)
	{}

	Vector2 Position() const { return position; }
	void SetPosition(const Vector2& newpos) { position = newpos; }

	Rectangle getRectangle() const
	{
		return body;
	}

	// gives the info the camera needs to draw the object.
	graphics::Brush virtual getBrush() const
	{
		graphics::Brush sprite;

		sprite.texture = texture;
		sprite.outline_opacity = 0.0f;

		return sprite;
	}

	void virtual Update() = 0;
	
protected:
	Vector2 position; // level space position
	std::string texture;
	Rectangle body;

};
