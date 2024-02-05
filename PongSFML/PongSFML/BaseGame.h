#pragma once

#include <SFML/Graphics.hpp>
#include "BaseRoom.h"

class BaseGame
{
public:
	~BaseGame();
	void ProcessEvents();
	void Draw();
	void Step();
	void Run();
	static BaseGame* GetInstance();

	sf::RenderWindow* GetWindow();

	BaseRoom* GetCurrentRoom();

	void ChangeRoom(BaseRoom* NewRoom);

	float GetFPS();
	void SetFPS(float fps);

	void SetWindowResolution(int width, int height);
	sf::Vector2u GetWindowResolution();

	std::string GetTitleBarText();
	void SetTitleBarText(const std::string& text);

	void QuitGame();

private:
	BaseGame();
	void PossiblyChangeRoom();

	float FramesPerSecond;
	int WindowWidth;
	int WindowHeight;
	std::string TitleBarText;
	sf::RenderWindow* Window;
	sf::Time TimePerFrame;
	BaseRoom* CurrentRoom;
	BaseRoom* NextRoom;

	static BaseGame* Instance;
};