#include <iostream>
#include "BaseGame.h"
#include "GameInitializationRoom.h"

BaseGame* BaseGame::Instance = nullptr;

BaseGame::BaseGame()
	:FramesPerSecond(),
	WindowWidth(1280),
	WindowHeight(720),
	TitleBarText("Pong"),
	Window(new sf::RenderWindow(sf::VideoMode(WindowWidth, WindowHeight), TitleBarText)),
	TimePerFrame(sf::seconds(1.0f / FramesPerSecond)),
	CurrentRoom(new GameInitializationRoom()),
	NextRoom(nullptr)
{
	//Nothing here...
}

void BaseGame::PossiblyChangeRoom()
{
	if (NextRoom != nullptr)
	{
		delete CurrentRoom;
		CurrentRoom = NextRoom;
		NextRoom = nullptr;
	}
}

BaseGame::~BaseGame()
{
	delete Window;
}

void BaseGame::ProcessEvents()
{
	sf::Event event;
	while (Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			Window->close();
		}
	}
}

void BaseGame::Draw()
{
	Window->clear();
	CurrentRoom->Draw();
	Window->display();
}

void BaseGame::Step()
{
	CurrentRoom->Step();
}

void BaseGame::Run()
{
	//Game Loop
	sf::Clock Clock;
	sf::Time TimeSinceLastUpdate = sf::Time::Zero;

	while (Window->isOpen())
	{
		TimeSinceLastUpdate += Clock.restart();
		ProcessEvents();
		while (TimeSinceLastUpdate > TimePerFrame)
		{
			//Keyboard::GetInstance()->Update();
			//Mouse::GetInstance()->Update();
			TimeSinceLastUpdate -= TimePerFrame;
			Step();
			ProcessEvents();
		}
		Draw();
		PossiblyChangeRoom();
	}
}

sf::RenderWindow* BaseGame::GetWindow()
{
	return Window;
}

BaseRoom* BaseGame::GetCurrentRoom()
{
	return CurrentRoom;
}

void BaseGame::ChangeRoom(BaseRoom* NewRoom)
{
	if (NextRoom == nullptr)
	{
		NextRoom = NewRoom;
	}
	else
	{
		delete NewRoom;
	}
}

BaseGame* BaseGame::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new BaseGame();
	}
	return Instance;
}

float BaseGame::GetFPS()
{
	return FramesPerSecond;
}

void BaseGame::SetFPS(float fps)
{
	FramesPerSecond = fps;
	TimePerFrame = sf::seconds(1.0f / FramesPerSecond);
}

void BaseGame::SetWindowResolution(int width, int height)
{
	delete Window;
	WindowWidth = width;
	WindowHeight = height;
	Window = new sf::RenderWindow(sf::VideoMode(WindowWidth, WindowHeight), TitleBarText);
}

sf::Vector2u BaseGame::GetWindowResolution()
{
	return Window->getSize();
}

std::string BaseGame::GetTitleBarText()
{
	return TitleBarText;
}

void BaseGame::SetTitleBarText(const std::string& text)
{
	TitleBarText = text;
	Window->setTitle(TitleBarText);
}

void BaseGame::QuitGame()
{
	exit(0);
}