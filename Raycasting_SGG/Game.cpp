#include "Game.h"

Game::Game()
	:
	scene(Player({10.0f, 1.0f}), Level()),
	camera(&scene)
{
	graphics::Brush br;
	br.fill_color[0] = 0.1f;
	br.fill_color[1] = 0.1f;
	br.fill_color[2] = 0.1f;
	graphics::setWindowBackground(br);
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
		scene.player.RotateBy(-0.005f * dt);
	}

	if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		scene.player.RotateBy(0.005f * dt);
	}

}

void Game::Draw()
{

	camera.RenderSceneAt(0, 0, CanvasWidth, CanvasHeight);

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

}
