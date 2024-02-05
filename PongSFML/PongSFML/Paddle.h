#pragma once

#include "BaseObject.h"

class Paddle : public BaseObject
{
public:
	Paddle(float x, float y, sf::Color color);
	~Paddle();

	// will need a step event for the movement...

	void SetPaddleColor(sf::Color color);

private:
	sf::RectangleShape* paddle;
	sf::Vector2f StartPosition;
	sf::Color PaddleColor;
	float paddleWidth;
	float paddleHeight;
};