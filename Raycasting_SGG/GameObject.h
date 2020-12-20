#pragma once
#include "Vector2.h"
#include "graphics.h"
#include <string>

/// <summary>
/// This interface represents something that has a position in the Level(see Level.h).
/// It is used by the camera to draw the Entities and Items.
/// </summary>
class GameObject
{
public:
	GameObject(const std::string& texture)
		:
		position(0.0f, 0.0f),
		texture(texture)
	{}

	GameObject(float xPos, float yPos, const std::string& texture)
		:
		position(xPos,yPos),
		texture(texture)
	{}

	GameObject(const Vector2& pos, const std::string& texture)
		: 
		position(pos),
		texture(texture)
	{}

	Vector2 Position() const { return position; }
	void SetPosition(const Vector2& newpos) { position = newpos; }

	// gives the info the camera needs to draw the object.
	graphics::Brush virtual getBrush() const
	{
		graphics::Brush sprite;

		sprite.texture = texture;
		sprite.outline_opacity = 0.0f;

		return sprite;
	}
	

protected:
	Vector2 position; // level space position
	std::string texture;

};
