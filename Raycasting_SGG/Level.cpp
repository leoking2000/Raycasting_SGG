#include "Level.h"

Level::Level()
	:
	width(30),
	height(20),
	arr(height, width)
{
	std::string map;

	map += "###############.##############";
	map += "#............................#";
	map += "#....BBBBBBBBB.BBBBBBBB......#";
	map += "#............................#";
	map += "#....GGGGG..........GGG......#";
	map += "#....GGGGG..........GGG......#";
	map += "#....RR.RR..RR..RR..RR.......#";
	map += "#............................#";
	map += "#............................#";
	map += "#......BRRRR.RRRRG...........#";
	map += "#......B.........G...........#";
	map += "#......BRRRRRRRRRGGGG........#";
	map += "#..T...B.....................#";
	map += "#..T...R.....................#";
	map += "#..T..........BBBBB..........#";
	map += "#..T...R......BR..B..........#";
	map += "#..T...G......B...B..........#";
	map += "#..T...G......B..............#";
	map += ".......G......B.BBB...........";
	map += "###############.##############";


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
	return arr.Get((y % height + height) % height, (x % width + width) % width);
}

void Level::Set(int x, int y, char v)
{
	arr.Set((y % height + height) % height, (x % width + width) % width, v);
}

int Level::GetWidth() const
{
	return width;
}

int Level::GetHeight() const
{
	return height;
}
