#pragma once

class IHasHealth
{
public:
	void virtual Damage(float amount) = 0;
};