#pragma once
#include "Entity.h"


class Enemy : public Entity
{
public:
	Enemy(const std::string& texture)
		:
		Entity(texture)
	{
	}
	Enemy(float xPos, float yPos, float xDir, float yDir, const std::string& texture)
		:
		Entity(xPos, yPos, xDir, yDir, texture)
	{
	}
	Enemy(const Vector2& pos, const Vector2& dir, const std::string& texture)
		:
		Entity(pos, dir, texture)
	{
	}

	void Update() override;
};

