#include "Game.h"

void Update(float dt)
{
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());

	game->Update();
}

void Draw()
{
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());

	game->Draw();
}

int main()
{
    graphics::createWindow(Game::CanvasWidth, Game::CanvasHeight, "Game");
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_WINDOW);
	graphics::setCanvasSize((float)Game::CanvasWidth, (float)Game::CanvasHeight);

	Game game;

	graphics::setUserData(&game);
	graphics::setDrawFunction(Draw);
	graphics::setUpdateFunction(Update);

	graphics::startMessageLoop();

	graphics::destroyWindow();
    return 0;
}
