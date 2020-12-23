#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player()
		:
		Entity(0.0f,0.0f,0.0f,1.0f,std::string(""))
	{
	}
	Player(float xPos, float yPos, float xDir, float yDir)
		:
		Entity(xPos, yPos, xDir, yDir, std::string(""))
	{
	}

	void Update() override;

};

