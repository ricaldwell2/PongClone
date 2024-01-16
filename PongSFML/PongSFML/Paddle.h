#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>

class Paddle
{
public:
	Paddle(float x, float y, sf::Color color);
	~Paddle();

	virtual void Step();
	virtual void Draw();
	
	void SetStartPositionX(float x);
	void SetStartPositionY(float y);
	void SetPaddleColor(sf::Color color);

private:
	sf::RectangleShape* paddle;
	sf::Vector2f StartPosition;
	sf::Color PaddleColor;
	float paddleWidth;
	float paddleHeight;
};