#include "Game.h"
#include "Enemy.h"

Game::Game()
	:
	level("assets//Levels//TestLevel.txt"),
	camera(&level, CanvasWidth, CanvasHeight)
{
	graphics::Brush background;
	background.fill_color[0] = 0.2f;
	background.fill_color[1] = 0.2f;
	background.fill_color[2] = 0.2f;
	graphics::setWindowBackground(background);
	graphics::setFont("assets//orange juice 2.0.ttf");
}

Game::~Game()
{
}

void Game::Update()
{
	level.Update();
}

void Game::Draw()
{
	camera.Render();

	graphics::Brush br;

	if (graphics::getKeyState(graphics::SCANCODE_M))
	{
		/////////////////// minimap //////////////////
		br.fill_color[0] = 0.0;
		br.fill_color[1] = 0.5;
		br.fill_color[2] = 0.5f;
		br.outline_opacity = 0.0f;

		for (int y = 0; y < level.GetHeight(); y++)
		{
			for (int x = 0; x < level.GetWidth(); x++)
			{
				if (level.Get(x, y) != ' ')
				{
					graphics::drawRect(float(x * 6 + 3), float(y * 6 + 3), 5.0f, 5.0f, br);
				}
			}
		}

		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.0f;
		br.fill_color[2] = 0.0f;

		Vector2 v = level.GetPlayer().Position() + level.GetPlayer().Direction();

		graphics::drawDisk(level.GetPlayer().Position().x * 6 + 3, level.GetPlayer().Position().y * 6 + 3, 2, br);
		br.outline_opacity = 1.0f;
		graphics::drawLine(level.GetPlayer().Position().x * 6 + 3, level.GetPlayer().Position().y * 6 + 3,
			v.x * 6 + 3, v.y * 6 + 3, br);
	}

	//FPS counter
	br.fill_color[0] = 1.0;
	br.fill_color[1] = 1.0;
	br.fill_color[2] = 1.0f;

	double frameTime = graphics::getDeltaTime() / 1000.0; //frameTime is the time this frame has taken, in seconds
	graphics::drawText(0.0f, 50.0f, 50.0f, std::to_string(int(1.0 / frameTime)), br);

}
