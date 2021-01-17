#pragma once
#include <vector>
#include "Ifunctors.h"
#include <string>

class Menu
{
public:
	Menu();
	~Menu();
	Menu(const Menu& g) = delete;
	Menu& operator=(const Menu& g) = delete;

	void Insert(const std::string& name, Ifunctor* fun);

	void SelectUp();
	void SelectDown();
	void Åxecute();
	void Draw();


private:
	int selectedIndex = 0;
	std::vector<Ifunctor*> options;
	std::vector<std::string> optionsNames;
};

