#include "Level.h"

Level::Level()
	:
	width(30),
	height(20),
	arr(height, width)
{
	std::string map;

	map += "##############################";
	map += "#............................#";
	map += "#....BBBBBBBBB.BBBBBBBB......#";
	map += "#...................BBB..G...#";
	map += "#....GGGGG.GGGGGGG..GGG......#";
	map += "#....GGGGG.GGGGGGG..GGG..G...#";
	map += "#....RR.RR..RR..RR..RR.......#";
	map += "#........................G...#";
	map += "#............................#";
	map += "#......BRRRR.RRRRG.......G...#";
	map += "#......B.........G...........#";
	map += "#......BRRRRRRRRRGGGG....G...#";
	map += "#......B.....................#";
	map += "#......R.................G...#";
	map += "#.............BBBBB..........#";
	map += "#......R......BBBBB......G...#";
	map += "#......G......BBBBB..........#";
	map += "#......G......BBBBB......G...#";
	map += "#......G......BBBBB..........#";
	map += "##############################";


	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++) 
		{
			const char c = map[width * y + x];

			arr.Set(y, x, c);
		}
	}



}

char Level::Get(int x, int y) const
{
	assert(y < arr.GetRows());
	assert(y >= 0);
	assert(x < arr.GetColumns());
	assert(x >= 0);

	return arr.Get(y, x);
}

void Level::Set(int x, int y, char v)
{
	assert(y < arr.GetRows());
	assert(y >= 0);
	assert(x < arr.GetColumns());
	assert(x >= 0);

	arr.Set(y, x, v);
}

int Level::GetWidth() const
{
	return width;
}

int Level::GetHeight() const
{
	return height;
}
