#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player()
		:
		Entity(0.0f,0.0f,0.0f,1.0f)
	{
	}
	Player(float xPos, float yPos, float xDir, float yDir)
		:
		Entity(xPos, yPos, xDir, yDir)
	{
	}
	Player(const Vector2& pos, const Vector2& dir)
		:
		Entity(pos,dir)
	{
	}

	graphics::Brush getBrush() const override;

	void Update() override;

};

