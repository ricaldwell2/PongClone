#include "GameInitializationRoom.h"
#include "BaseChoice.h"
#include "MainMenu.h"

GameInitializationRoom::GameInitializationRoom()
{
	//Engine level sprite memory allocation

	//Game level sprite memory allocation
	BaseChoice OnePlayer(530.f, 500.f, 50, "1-Player", sf::Color::White, sf::Font(font));

	//...put main menu background here
	//SFMLTextureManager::GetInstance->AddTexture("mainmenubackground", "Mainmenu.filename");

	//Put in all sprite memory allocation and inialization here
		// Not sure if I will need this...only if there are outside sprites being brought in
}

void GameInitializationRoom::Step()
{
	//What is the first "real" room of the game
	ChangeRoom(new MainMenu());
}