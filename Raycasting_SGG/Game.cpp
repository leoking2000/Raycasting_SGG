#include "Game.h"
#include <string>

Game::Game()
	:
	scene(Player({10.0f, 8.0f}), Level()),
	camera(&scene, CanvasWidth, CanvasHeight)
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

void Game::Update(float dt)
{
	if (graphics::getKeyState(graphics::SCANCODE_UP))
	{
		scene.player.GoForward(0.005f * dt);
	}

	if (graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		scene.player.GoForward(-0.005f * dt);
	}

	if (graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		scene.player.RotateBy(-0.002f * dt);
	}

	if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		scene.player.RotateBy(0.002f * dt);
	}

}

void Game::Draw()
{
	
	//camera.RenderSceneAt(scene.level.GetWidth() * 6 + 3, 200);
	camera.RenderSceneAt(0, 0);

	/////////////minimap////////////////////////
	graphics::Brush br;
	br.fill_color[0] = 0.0;
	br.fill_color[1] = 0.5;
	br.fill_color[2] = 0.5f;
	br.outline_opacity = 0.0f;

	for (int y = 0; y < scene.level.GetHeight(); y++)
	{
		for (int x = 0; x < scene.level.GetWidth(); x++)
		{
			if (scene.level.Get(x, y) != '.')
			{
				graphics::drawRect(x * 6 + 3, y * 6 + 3, 5, 5, br);
			}
		}
	}

	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;

	Vector2 v = scene.player.Position() + scene.player.Direction();

	graphics::drawDisk(scene.player.Position().x * 6 + 3, scene.player.Position().y * 6 + 3,2, br);
	br.outline_opacity = 1.0f;
	graphics::drawLine(scene.player.Position().x * 6 + 3, scene.player.Position().y * 6 + 3,
		               v.x * 6 + 3, v.y * 6 + 3, br);
	
	
	
	//FPS counter
	br.fill_color[0] = 1.0;
	br.fill_color[1] = 1.0;
	br.fill_color[2] = 1.0f;

	float frameTime = graphics::getDeltaTime() / 1000.0; //frameTime is the time this frame has taken, in seconds
	graphics::drawText(scene.level.GetWidth() * 6 + 3, 50, 50, std::to_string(int(1.0 / frameTime)), br);

}
