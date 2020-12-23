#pragma once
#include "Entity.h"


class Enemy : public Entity
{
public:
	Enemy(float xPos, float yPos, float xDir, float yDir, const std::string& texture)
		:
		Entity(xPos, yPos, xDir, yDir, texture)
	{
	}

	void Update() override;
};

