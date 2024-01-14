#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>

class Paddle
{
public:
	Paddle();
	~Paddle();

	void SetPaddleDims(float width, float height);
	void SetPaddlePosition(float x, float y);
	void SetPaddleColor(sf::Color color);

private:
	sf::RectangleShape paddle;

	float paddleWidth = 50.f;
	float paddleHeight = 150.f;
};