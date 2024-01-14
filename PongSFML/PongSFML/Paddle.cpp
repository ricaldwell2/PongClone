#include "Paddle.h"

Paddle::Paddle()
{
	
}

Paddle::~Paddle()
{
	//delete paddle;
}

void Paddle::SetPaddleDims(float width, float height)
{
	paddle.setSize(sf::Vector2f(width, height));
}

void Paddle::SetPaddlePosition(float x, float y)
{
	paddle.setPosition(x, y);
}

void Paddle::SetPaddleColor(sf::Color color)
{
	paddle.setFillColor(color);
}