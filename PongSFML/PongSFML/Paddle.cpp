#include "Paddle.h"

Paddle::Paddle(float x, float y, sf::Color color)
	:paddle(new sf::RectangleShape()),
	StartPosition(x, y),
	PaddleColor(sf::Color()),
	paddleWidth(50.f),
	paddleHeight(150.f)
{
	
}

Paddle::~Paddle()
{
	delete paddle;
}

void Paddle::Step()
{

}

void Paddle::Draw()
{
	//sf::RenderWindow draw(*paddle);
}

/*
void Paddle::SetPaddleDims(float width, float height)
{
	paddle.setSize(sf::Vector2f(width, height));
}
*/

void Paddle::SetStartPositionX(float x)
{
	StartPosition.x = x;
}

void Paddle::SetStartPositionY(float y)
{
	StartPosition.y = y;
}

void Paddle::SetPaddleColor(sf::Color color)
{
	PaddleColor = color;
}