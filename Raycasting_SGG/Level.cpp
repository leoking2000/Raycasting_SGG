#include "Level.h"
#include <fstream>
#include <assert.h>
#include <algorithm>

#include "Player.h"
#include "Decoration.h"

Level::Level(const std::string& filename)
	:
	deletionPeriod(500) // 500 because it seems ok.
{
	Load(filename);
}

Level::~Level()
{
	Free();
}

void Level::Load(const std::string& filename)
{
	Free();

	std::ifstream file(filename);

	assert(file);

	std::string map = ""; 
	int w = 0;
	int h = 0;

	bool hasReadFirstLine = false;

	while (file.good())
	{
		char c = file.get();

		if(c != '\n') map += c;

		if (c == '\n')
		{
			h++;
			hasReadFirstLine = true;
		}
		else if (hasReadFirstLine == false) {
			w++;
		}
	}

	width = w;
	height = h + 1;

	arr = Array2D<char>(height, width);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			char c = map[width * y + x];

			switch (c)
			{
			case '#':
				Set(x, y, '#');
				break;
			case 'P':
				Set(x, y, ' ');
				player = new Player(x + 0.5f, y + 0.5f, 0.0f, -1.0f,5.0f, 2.0f);
				gameobjects.emplace_back(player);
				break;
			case 'E':
				Set(x, y, ' ');
				gameobjects.emplace_back(new Decoration(x + 0.5f, y + 0.5f, 1.0f, 100.0f, std::string("assets//robot.png")));
				break;
			case 'p':
				Set(x, y, ' ');
				gameobjects.emplace_back(new Decoration(x + 0.5f, y + 0.5f, 1.0f, 100.0f, std::string("assets//pillar.png")));
				break;
			case 'b':
				Set(x, y, ' ');
				gameobjects.emplace_back(new Decoration(x + 0.5f, y + 0.5f, 1.0f, 5.0f, std::string("assets//barrel.png")));
				break;
			case ' ':
				Set(x, y, ' ');
				break;
			}
		}
	}
	file.close();

}

void Level::Update()
{
	for (GameObject* obj : gameobjects)
	{
		if (obj->getState() != obj->ACTIVE) continue;

		obj->Update();

		for (GameObject* other : gameobjects)
		{
			if (obj != other && other->getState() == other->ACTIVE && obj->GetBody().IntersectsWith(other->GetBody()))
			{
				obj->Hit(*other);
			}
		}
	}

	if (deletionPeriod <= timePassed)
	{
		DeleteDeadGameObjects();
		timePassed = 0;
	}
	else
	{
		timePassed += graphics::getDeltaTime();
	}
}

char Level::Get(int x, int y) const
{
	return arr.Get(y % height, x % width);
}

void Level::Set(int x, int y, char v)
{
	arr.Set(y % height, x % width, v);
}

void Level::DeleteDeadGameObjects()
{
	for (int i = 0; i < gameobjects.size(); i++)
	{
		if (gameobjects[i]->getState() == GameObject::State::DEAD) {
			delete gameobjects[i];
			gameobjects[i] = nullptr;
		}
	}

	gameobjects.erase(std::remove_if(gameobjects.begin(), gameobjects.end(), [](GameObject* ob) { return ob == nullptr; }), gameobjects.end());
}

void Level::Free()
{
	for (GameObject* obj : gameobjects)
	{
		delete obj;
		obj = nullptr;
	}

	gameobjects.clear();
}

int Level::GetWidth() const
{
	return width;
}

int Level::GetHeight() const
{
	return height;
}

const GameObject* const Level::GetPlayer() const
{
	return player;
}

const std::vector<GameObject*>& Level::GameObjects() const
{
	return gameobjects;
}
