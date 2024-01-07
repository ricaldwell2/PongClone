#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
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
	
	system("PAUSE");
	return 0;
}

/*
	TODO: 
		1. move pink bars out of screen
		2. 

*/