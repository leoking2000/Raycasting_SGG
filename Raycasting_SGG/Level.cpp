#include "Level.h"
#include <fstream>
#include <assert.h>
#include <algorithm>

#include "Player.h"
#include "Decoration.h"
#include "Weapon.h"
#include "Enemy.h"

Level::Level()
	:
	deletionPeriod(2000) // 2000 because it seems ok.
{
}

Level::~Level()
{
	Free();
}

bool Level::Load(const std::string& filename)
{
	Free();

	std::ifstream file(filename);

	if (!file) return false;

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
				player = new Player(x + 0.5f, y + 0.5f, 0.0f, 1.0f, 1000.0f, 10.0f, 2.0f);
				gameobjects.emplace_back(player);
				break;
			case 'E':
				Set(x, y, ' ');
				gameobjects.emplace_back(Enemy::Make_Ghost(x + 0.5f, y + 0.5f));
				break;
			case 'i':
				Set(x, y, ' ');
				gameobjects.emplace_back(Weapon::Make_Pistol({ x + 0.5f, y + 0.5f }));
				break;
			case 'p':
				Set(x, y, ' ');
				gameobjects.emplace_back(new Decoration(x + 0.5f, y + 0.5f, 0.5f, 100.0f, std::string("assets//Entities//pillar.png")));
				break;
			case 'b':
				Set(x, y, ' ');
				gameobjects.emplace_back(new Decoration(x + 0.5f, y + 0.5f, 0.5f, 5.0f, std::string("assets//Entities//barrel.png")));
				break;
			case ' ':
				Set(x, y, ' ');
				break;
			}
		}
	}
	file.close();
	return true;
}

Event Level::Update()
{
	for (int i = 0; i < gameobjects.size(); i++)
	{
		if (gameobjects[i]->getState() == gameobjects[i]->DEAD) continue;

		gameobjects[i]->Update();

		for (GameObject* other : gameobjects)
		{
			if (gameobjects[i] != other && other->getState() == other->ACTIVE && gameobjects[i]->GetBody().IntersectsWith(other->GetBody()))
			{
				gameobjects[i]->Hit(*other);
			}
		}
	}

	if (player->getState() == GameObject::State::DEAD)
	{
		Free();
		return Event::PlayerDies;
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

	return Event::NOTHING;
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

	player = nullptr;

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

const IHasHealth* const Level::GetPlayer() const
{
	return player;
}

const std::vector<GameObject*>& Level::GameObjects() const
{
	return gameobjects;
}

void Level::AddGameObject(GameObject* go)
{
	if (go != nullptr)
	{
		gameobjects.push_back(go);
	}
}
