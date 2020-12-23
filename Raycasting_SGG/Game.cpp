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
	
	//FPS counter
	graphics::Brush br;
	br.fill_color[0] = 1.0;
	br.fill_color[1] = 1.0;
	br.fill_color[2] = 1.0f;

	double frameTime = graphics::getDeltaTime() / 1000.0; //frameTime is the time this frame has taken, in seconds
	graphics::drawText(0.0f, 50.0f, 50.0f, std::to_string(int(1.0 / frameTime)), br);

}
