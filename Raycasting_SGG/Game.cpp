#include "Game.h"

Game::Game()
	:
	level(),
	camera(canvaswidth)
{
	graphics::Brush background;
	background.fill_color[0] = 0.2f;
	background.fill_color[1] = 0.2f;
	background.fill_color[2] = 0.2f;
	graphics::setWindowBackground(background);
	graphics::setFont("assets//SUBWT___.ttf");

	graphics::playMusic("assets\\Audio\\music.mp3", 1.0f, true);

	main_menu.Insert("Play", new LevelLoader(1));
	main_menu.Insert("Level Selector", new Back(state));

	level_selector.Insert("Level 1", new LevelLoader(1));
	level_selector.Insert("Level 2", new LevelLoader(2));
	level_selector.Insert("Level 3", new LevelLoader(3));
	level_selector.Insert("Back", new Back(state));
}

Game::~Game()
{
}

int Game::CanvasWidth() const
{
	return canvaswidth;
}

int Game::CanvasHeight() const
{
	return canvasheight;
}

Level& Game::GetLevel()
{
	return level;
}

void Game::Update()
{
	switch (state)
	{
	case Game::State::MAINMENU:
		ManageMenu(main_menu);
		break;
	case Game::State::LEVELSELECTOR:
		ManageMenu(level_selector);
		break;
	case Game::State::PLAYSCREEN:
		UpdatePlayScreen();
		break;
	}
}

void Game::Draw()
{
	switch (state)
	{
	case Game::State::MAINMENU:
		main_menu.Draw();
		break;
	case Game::State::LEVELSELECTOR:
		level_selector.Draw();
		break;
	case Game::State::PLAYSCREEN:
		DrawPlayScreen();
		break;
	}

}

void Game::ResizeCanvas(int w, int h)
{
	canvaswidth = w;
	canvasheight = h;
	camera.ResizeBuffer();

	graphics::setCanvasSize((float)canvaswidth, (float)canvasheight);
}

void Game::LoadLevel(int num)
{
	if (level.Load(std::string("assets//Levels//Level") + std::to_string(num) + ".txt"))
	{
		state = Game::State::PLAYSCREEN;
		levelNumber = num;
		showed = false;
	}
	else
	{
		levelNumber = 1;
		state = Game::State::MAINMENU;
	}
}

/////////////////////////////////////////////////////////////////////

void Game::UpdatePlayScreen()
{
	Event event = level.Update();

	switch (event)
	{
	case Event::PlayerWin:
		LoadLevel(levelNumber + 1);
		break;
	case Event::PlayerDies:
		state = Game::State::MAINMENU;
		break;
	}
}

void Game::DrawPlayScreen()
{
	camera.Render();


	/// UI ///
	
	graphics::Brush ui;

	// draw player item.
	graphics::drawRect(canvaswidth / 2.0f, canvasheight - 300.0f, 600, 600, level.GetPlayer()->GetBrush());

	// draw Health
	graphics::drawText(10.0f, 60.0f, 50.0f, "Health:", ui);
	graphics::drawText(190.0f, 60.0f, 50.0f, std::to_string((int)level.GetPlayer()->GetHealth()), ui);
	
	// draw num of keys
	graphics::drawText(10.0f, 120.0f, 50.0f, "Keys  to  collect:", ui);
	graphics::drawText(395.0f, 120.0f, 50.0f, std::to_string((int)level.GetNumOfkeys()), ui);

	if (showed == false)
	{
		if (timePassed >= levelShowPeriod)
		{
			showed = true;
			timePassed = 0;
		}
		else
		{
			// draw level
			graphics::drawText(canvaswidth / 2.0f - 100.0f, canvasheight / 2.0f, 50.0f, "Level:", ui);
			graphics::drawText(canvaswidth / 2.0f + 50.0f, canvasheight / 2.0f, 50.0f, std::to_string(levelNumber), ui);
			timePassed += graphics::getDeltaTime();
		}
	}

	// DEBUG
	if (graphics::getKeyState(graphics::SCANCODE_M))
	{
		graphics::Brush map;

		const int scale = 10;

		/////////////////// minimap //////////////////
		map.fill_color[0] = 0.7f;
		map.fill_color[1] = 0.7f;
		map.fill_color[2] = 0.7f;
		map.outline_opacity = 0.0f;

		for (int y = 0; y < level.GetHeight(); y++)
		{
			for (int x = 0; x < level.GetWidth(); x++)
			{
				if (level.Get(x, y) != ' ')
				{
					graphics::drawRect(float(x * scale + scale / 2), float(y * scale + scale / 2), scale - 1, scale - 1, map);
				}
			}
		}

		map.fill_color[0] = 1.0f;
		map.fill_color[1] = 0.0f;
		map.fill_color[2] = 0.0f;
		// player
		Vector2 v = level.GetPlayer()->Position() + level.GetPlayer()->Direction();
		graphics::drawDisk(level.GetPlayer()->Position().x * scale, level.GetPlayer()->Position().y * scale, 2, map);
		map.outline_opacity = 1.0f;
		graphics::drawLine(level.GetPlayer()->Position().x * scale, level.GetPlayer()->Position().y * scale,
			v.x * scale, v.y * scale, map);

		map.fill_opacity = 0.0f;
		map.outline_opacity = 1.0f;
		Circle body = level.GetPlayer()->GetBody();
		graphics::drawDisk(body.GetCenter().x * scale, body.GetCenter().y * scale, body.GetRadious() * scale, map);
		map.fill_opacity = 1.0f;
		map.outline_opacity = 0.0f;

		for (GameObject* obj : level.GameObjects())
		{
			graphics::drawDisk(obj->Position().x * scale, obj->Position().y * scale, 2, map);

			map.fill_opacity = 0.0f;
			map.outline_opacity = 1.0f;
			Circle body = obj->GetBody();
			graphics::drawDisk(body.GetCenter().x * scale, body.GetCenter().y * scale, body.GetRadious() * scale, map);
			map.fill_opacity = 1.0f;
			map.outline_opacity = 0.0f;
		}
	}

	if (graphics::getKeyState(graphics::SCANCODE_N))
	{
		//FPS counter
		graphics::Brush fps;

		fps.fill_color[0] = 1.0;
		fps.fill_color[1] = 1.0;
		fps.fill_color[2] = 1.0f;

		graphics::drawText(canvaswidth - 200.0f, 50.0f, 50.0f, "FPS: ", fps);

		double frameTime = graphics::getDeltaTime() / 1000.0; //frameTime is the time this frame has taken, in seconds
		graphics::drawText(canvaswidth - 80.0f, 50.0f, 50.0f, std::to_string(int(1.0 / frameTime)), fps);
	}

}

void Game::ManageMenu(Menu& menu)
{
	if (graphics::getKeyState(graphics::SCANCODE_UP) && upArrowPress == false)
	{
		menu.SelectUp();
		upArrowPress = true;
	}
	else
	{
		upArrowPress = graphics::getKeyState(graphics::SCANCODE_UP);
	}

	if (graphics::getKeyState(graphics::SCANCODE_DOWN) && downArrowPress == false)
	{
		menu.SelectDown();
		downArrowPress = true;
	}
	else
	{
		downArrowPress = graphics::getKeyState(graphics::SCANCODE_DOWN);
	}

	if (graphics::getKeyState(graphics::SCANCODE_RETURN) && spaceEnder == false)
	{
		menu.Åxecute();
		spaceEnder = true;
	}
	else
	{
		spaceEnder = graphics::getKeyState(graphics::SCANCODE_RETURN);
	}
}

Game::Back::Back(Game::State& state)
	:
	state(state)
{
}

void Game::Back::Do()
{
	switch (state)
	{
	case Game::State::MAINMENU:
		state = Game::State::LEVELSELECTOR;
		break;
	case Game::State::LEVELSELECTOR:
		state = Game::State::MAINMENU;
		break;
	}
}


Game::LevelLoader::LevelLoader(int levelNum, Game& game)
	:
	levelNum(levelNum),
	game(game)
{
}

void Game::LevelLoader::Do()
{
	game.LoadLevel(levelNum);
}
