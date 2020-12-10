#pragma once
#include "Entity.h"


class Enemy : public Entity
{
public:
	Enemy()
		:
		Entity(0.0f, 0.0f, 0.0f, 1.0f)
	{
	}
	Enemy(float xPos, float yPos, float xDir, float yDir)
		:
		Entity(xPos, yPos, xDir, yDir)
	{
	}
	Enemy(const Vector2& pos, const Vector2& dir)
		:
		Entity(pos, dir)
	{
	}

	graphics::Brush getBrush() const override;

	void Update() override;
};

