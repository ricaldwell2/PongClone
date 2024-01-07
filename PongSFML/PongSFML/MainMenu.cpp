#include "MainMenu.h"

MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("PixelEmulator.ttf"))
		throw("ERROR: COULD NOT LOAD FONT");

	// 1P
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::White);
	mainMenu[0].setString("1-Player");
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setPosition(530, 500);

	// 2P
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("2-Player");
	mainMenu[1].setCharacterSize(50);
	mainMenu[1].setPosition(530, 550);
	
	//Options
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("Options");
	mainMenu[2].setCharacterSize(50);
	mainMenu[2].setPosition(575, 600);

	//Exit
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(sf::Color::White);
	mainMenu[3].setString("Exit");
	mainMenu[3].setCharacterSize(50);
	mainMenu[3].setPosition(600, 650);

	MainMenuSelected = -1;
}

MainMenu::~MainMenu()
{

}

// Draw MainMenu
void MainMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < Max_main_menu; ++i)
	{
		window.draw(mainMenu[i]);
	}
}

// MoveUp
void MainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0)
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

// MoveDown
void MainMenu::MoveDown()
{
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
		MainMenuSelected++;
		if (MainMenuSelected == 4)
		{
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

int MainMenu::MainMenuPressed()
{
	return MainMenuSelected;
}