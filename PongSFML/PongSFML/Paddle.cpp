#include "Paddle.h"
#include "BaseGame.h"

Paddle::Paddle(float x, float y, sf::Color color)
	:BaseObject(x, y, "", 4, 1),
	 paddle(new sf::RectangleShape()),
	 PaddleColor(sf::Color())
{
	SetDepth(3);
}

Paddle::~Paddle()
{
	delete paddle;
}

void Paddle::SetPaddleColor(sf::Color color)
{
	PaddleColor = color;
}

/*
paddleWidth(50.f),
paddleHeight(150.f)
*/