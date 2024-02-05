#pragma once

#include "BaseRoom.h"

#define Max_main_menu 4

class MainMenu : public BaseRoom
{
public:
	MainMenu();

	void Draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int MainMenuPressed();
	
private:
	int MainMenuSelected;
	sf::Font font;
	sf::Text mainMenu[Max_main_menu];
};