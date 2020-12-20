#include "Game.h"
#include "Enemy.h"

Game::Game()
	:
	scene(Player(10.0f, 8.0f,-1.0, 0.0), Level()),
	camera(&scene, CanvasWidth, CanvasHeight)
{
	graphics::Brush background;
	background.fill_color[0] = 0.2f;
	background.fill_color[1] = 0.2f;
	background.fill_color[2] = 0.2f;
	graphics::setWindowBackground(background);
	graphics::setFont("assets//orange juice 2.0.ttf");


	scene.gameobjects.push_back(new Enemy(3.0f, 8.0f, 1.0f, 0.0f, std::string("assets//barrel.png")));
	scene.gameobjects.push_back(new Enemy(20.0f, 18.0f, 1.0f, 0.0f, std::string("assets//robot.png")));

	scene.gameobjects.push_back(new Enemy(25.0f, 14.0f, 1.0f, 0.0f, std::string("assets//pillar.png")));
	scene.gameobjects.push_back(new Enemy(25.0f, 11.0f, 1.0f, 0.0f, std::string("assets//pillar.png")));
	scene.gameobjects.push_back(new Enemy(25.0f, 9.0f, 1.0f, 0.0f, std::string("assets//pillar.png")));
	scene.gameobjects.push_back(new Enemy(25.0f, 7.0f, 1.0f, 0.0f, std::string("assets//pillar.png")));
	scene.gameobjects.push_back(new Enemy(26.0f, 14.0f, 1.0f, 0.0f, std::string("assets//pillar.png")));
	scene.gameobjects.push_back(new Enemy(26.0f, 11.0f, 1.0f, 0.0f, std::string("assets//pillar.png")));
	scene.gameobjects.push_back(new Enemy(26.0f, 9.0f, 1.0f, 0.0f, std::string("assets//pillar.png")));
	scene.gameobjects.push_back(new Enemy(26.0f, 7.0f, 1.0f, 0.0f, std::string("assets//pillar.png")));

}

Game::~Game()
{
}

void Game::Update()
{
	scene.player.Update();

}

void Game::Draw()
{
	
	//camera.RenderSceneAt(scene.level.GetWidth() * 6 + 3, 200);
	camera.RenderScene();

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
				graphics::drawRect(float(x * 6 + 3), float(y * 6 + 3), 5.0f, 5.0f, br);
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

	double frameTime = graphics::getDeltaTime() / 1000.0; //frameTime is the time this frame has taken, in seconds
	graphics::drawText(float(scene.level.GetWidth() * 6 + 3), 50.0f, 50.0f, std::to_string(int(1.0 / frameTime)), br);

}
