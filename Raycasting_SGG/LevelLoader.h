#pragma once
#include "Ifunctors.h"

class LevelLoader : public Ifunctor
{
private:
	const int levelNum;
public:
	LevelLoader(int levelNum)
		:
		levelNum(levelNum)
	{
	}

	void Do() override;
};