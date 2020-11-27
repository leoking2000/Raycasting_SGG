#pragma once
#include "Array2D.h"
#include <string>

class Level
{
public:
	Level();

	char Get(int x, int y) const;
	void Set(int x, int y, char v);

	int GetWidth() const;
	int GetHeight() const;

private:
	int width;
	int height;
	Array2D<char> arr;
};

