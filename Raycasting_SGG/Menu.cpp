#include "Menu.h"
#include "Game.h"

Menu::Menu()
{
}

Menu::~Menu()
{
	for (int i = 0; i < options.size(); i++)
	{
		delete options[i];
	}
}

void Menu::Insert(const std::string& name, Ifunctor* fun)
{
	options.push_back(fun);
	optionsNames.push_back(name);
}

void Menu::SelectUp()
{
	selectedIndex = (selectedIndex - 1) % options.size();
	graphics::playSound("assets\\Audio\\MenuToggle.wav", 1.0f);
}

void Menu::SelectDown()
{
	selectedIndex = (selectedIndex + 1) % options.size();
	graphics::playSound("assets\\Audio\\MenuToggle.wav", 1.0f);
}

void Menu::Åxecute()
{
	options[selectedIndex]->Do();
	graphics::playSound("assets\\Audio\\MenuToggle.wav", 1.0f);
}

void Menu::Draw()
{
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());

	graphics::Brush br;
	br.outline_opacity = 0.0f;

	for (int i = 0; i < optionsNames.size(); i++)
	{
		if (i == selectedIndex)
		{
			br.fill_color[0] = 0.8f;
			br.fill_color[1] = 0.0f;
			br.fill_color[2] = 0.0f;
		}

		graphics::drawText(game->CanvasWidth() / 2.0f - 10.0f * optionsNames[i].size(), i * 50.0f + 100.0f, 50.0f, optionsNames[i], br);

		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 1.0f;
	}

}
