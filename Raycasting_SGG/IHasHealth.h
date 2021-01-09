#pragma once
#include "GameObject.h"

class IHasHealth : public GameObject
{
public:
	void virtual Damage(float amount) = 0;
};