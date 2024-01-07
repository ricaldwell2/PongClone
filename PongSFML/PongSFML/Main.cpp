#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"

int main()
{
	sf::RenderWindow Menu(sf::VideoMode(1280, 720), "Pong");
	MainMenu mainMenu(Menu.getSize().x, Menu.getSize().y);

	while (Menu.isOpen())
	{
		sf::Event event;
		while (Menu.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Menu.close();
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					mainMenu.MoveUp();
					break;
				}
				else if (event.key.code == sf::Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					sf::RenderWindow Play(sf::VideoMode(1280, 720), "game_name");
					sf::RenderWindow Options(sf::VideoMode(1280, 720), "Options");
					sf::RenderWindow About(sf::VideoMode(1280, 720), "About");
					sf::RenderWindow Exit(sf::VideoMode(1280, 720), "Exit");

					int x = mainMenu.MainMenuPressed();
					if (x == 0)
					{
						while (Play.isOpen())
						{
							sf::Event eventX;
							while (Play.pollEvent(eventX))
							{
								if (eventX.type == sf::Event::Closed)
								{
									Play.close();
								}
								if (eventX.type == sf::Event::KeyPressed)
								{
									if (eventX.key.code == sf::Keyboard::Escape)
									{
										Play.close();
									}
								}
							}

							Options.close();
							About.close();
							Play.clear();
							Play.display();
						}
					}
				}
			}
		}

		Menu.clear();
		mainMenu.draw(Menu);
		Menu.display();
	}

	/*
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Pong");

	sf::FloatRect windowBounds(sf::Vector2f(0.f, 0.f), window.getDefaultView().getSize());
	
	// Left Paddle
	sf::RectangleShape leftPaddle(sf::Vector2f(50.f, 150.f));
	leftPaddle.setFillColor(sf::Color::Green);
	leftPaddle.setPosition(10.f, 285.f);

	// Right Paddle
	sf::RectangleShape rightPaddle(sf::Vector2f(50.f, 150.f));
	rightPaddle.setFillColor(sf::Color::Blue);
	rightPaddle.setPosition(1220.f, 285.f);

	// Ball
	sf::CircleShape ball(25.f);
	ball.setFillColor(sf::Color(150, 200, 6));
	ball.setPosition(627.f, 347.f);

	// Upper Boundry
	sf::RectangleShape upperBoundry(sf::Vector2f(1280.f, 5.f));
	upperBoundry.setFillColor(sf::Color(255, 0, 255));
	upperBoundry.setPosition(0.f, 0.f);

	// Lower Boundry
	sf::RectangleShape lowerBoundry(sf::Vector2f(1280.f, 5.f));
	lowerBoundry.setFillColor(sf::Color(255, 0, 255));
	lowerBoundry.setPosition(0.f, 715.f);

	sf::Event event;

	while(window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			// Keyboard actions
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				if (leftPaddle.getGlobalBounds().intersects(upperBoundry.getGlobalBounds()))
					leftPaddle.move(0.f, 0.f);
				else
					leftPaddle.move(0.f, -25.f);
				
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				if (leftPaddle.getGlobalBounds().intersects(lowerBoundry.getGlobalBounds()))
					leftPaddle.move(0.f, 0.f);
				else
					leftPaddle.move(0.f, 25.f);
			}
		}

		window.clear();
		window.draw(leftPaddle);
		window.draw(rightPaddle);
		window.draw(upperBoundry);
		window.draw(lowerBoundry);
		window.draw(ball);
		window.display();
	}
	*/
	
	system("PAUSE");
	return 0;
}

/*
	TODO: 
		1. move pink bars out of screen
		2. 

*/