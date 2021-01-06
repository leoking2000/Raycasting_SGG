#include "Game.h"

Game::Game()
	:
	level("assets//Levels//TestLevel.txt"),
	camera(1600)
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
	level.Update();
}

void Game::ResizeCanvas(int w, int h)
{
	canvaswidth = w;
	canvasheight = h;
	camera.ResizeBuffer();

	graphics::setCanvasSize((float)canvaswidth, (float)canvasheight);
}

void Game::Draw()
{
	camera.Render();

	graphics::Brush br;

	// DEBUG
	if (graphics::getKeyState(graphics::SCANCODE_M))
	{
		const int scale = 20;

		/////////////////// minimap //////////////////
		br.fill_color[0] = 0.7f;
		br.fill_color[1] = 0.7f;
		br.fill_color[2] = 0.7f;
		br.outline_opacity = 0.0f;

		for (int y = 0; y < level.GetHeight(); y++)
		{
			for (int x = 0; x < level.GetWidth(); x++)
			{
				if (level.Get(x, y) != ' ')
				{
					graphics::drawRect(float(x * scale + scale / 2), float(y * scale + scale / 2), scale - 1, scale - 1, br);
				}
			}
		}

		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.0f;
		br.fill_color[2] = 0.0f;
		// player
		Vector2 v = level.GetPlayer()->Position() + level.GetPlayer()->Direction();
		graphics::drawDisk(level.GetPlayer()->Position().x * scale, level.GetPlayer()->Position().y * scale, 2, br);
		br.outline_opacity = 1.0f;
		graphics::drawLine(level.GetPlayer()->Position().x * scale, level.GetPlayer()->Position().y * scale,
			v.x * scale, v.y * scale, br);

		br.fill_opacity = 0.0f;
		br.outline_opacity = 1.0f;
		Circle body = level.GetPlayer()->GetBody();
		graphics::drawDisk(body.GetCenter().x * scale, body.GetCenter().y * scale, body.GetRadious() * scale, br);
		br.fill_opacity = 1.0f;
		br.outline_opacity = 0.0f;

		for (GameObject* obj : level.GameObjects())
		{
			graphics::drawDisk(obj->Position().x * scale, obj->Position().y * scale, 2, br);

			br.fill_opacity = 0.0f;
			br.outline_opacity = 1.0f;
			Circle body = obj->GetBody();
			graphics::drawDisk(body.GetCenter().x * scale, body.GetCenter().y * scale, body.GetRadious() * scale, br);
			br.fill_opacity = 1.0f;
			br.outline_opacity = 0.0f;
		}
	}

	//FPS counter
	br.fill_color[0] = 1.0;
	br.fill_color[1] = 1.0;
	br.fill_color[2] = 1.0f;

	double frameTime = graphics::getDeltaTime() / 1000.0; //frameTime is the time this frame has taken, in seconds
	graphics::drawText(0.0f, 50.0f, 50.0f, std::to_string(int(1.0 / frameTime)), br);

}
