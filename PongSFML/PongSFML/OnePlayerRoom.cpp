#include "OnePlayerRoom.h"
//#include "Paddle.h"

OnePlayerRoom::OnePlayerRoom(float width, float height)
{
	if(!font.loadFromFile("PixelEmulator.ttf"))
		throw("ERROR: COULD NOT LOAD FONT");

	// Score PlayerOne
	playerScores[0].setFont(font);
	playerScores[0].setFillColor(sf::Color::Yellow);
	playerScores[0].setString(("1P: ") + (std::to_string(scorePlayerOne)));
	playerScores[0].setCharacterSize(50);
	playerScores[0].setPosition(50, 50);

	// Score CPU
	playerScores[1].setFont(font);
	playerScores[1].setFillColor(sf::Color::Yellow);
	playerScores[1].setString(("2P: ") + (std::to_string(scoreCPU)));
	playerScores[1].setCharacterSize(50);
	playerScores[1].setPosition(50, 50);

	// Player 1 Paddle
	PlayerOnePaddle.SetPaddleDims(paddleWidth, paddleHeight);
	PlayerOnePaddle.SetPaddlePosition(10.f, 282.f);
	PlayerOnePaddle.SetPaddleColor(sf::Color::Green);

	// CPU Paddle
	CPUPaddle.SetPaddleDims(paddleWidth, paddleHeight);
	CPUPaddle.SetPaddlePosition(1220.f, 285.f);
	CPUPaddle.SetPaddleColor(sf::Color::Blue);
}
OnePlayerRoom::~OnePlayerRoom()
{
	// Nothing here??
}

void OnePlayerRoom::draw(sf::RenderWindow& onePlayerRoom)
{
	for (int i = 0; i < Player_scores; ++i)
	{
		onePlayerRoom.draw(playerScores[i]);
	}

	//onePlayerRoom.draw(PlayerOnePaddle);
}

Paddle OnePlayerRoom::getPlayerOnePaddle()
{
	return PlayerOnePaddle;
}
/*
void OnePlayerRoom::PlayerOnePaddleMove()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (PlayerOnePaddle.getGlobalBounds().intersects(PlayerOnePaddle.getGlobalBounds()))
			PlayerOnePaddle.move(0.f, 0.f);
		else
			PlayerOnePaddle.move(0.f, -25.f);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (PlayerOnePaddle.getGlobalBounds().intersects(PlayerOnePaddle.getGlobalBounds()))
			PlayerOnePaddle.move(0.f, 0.f);
		else
			PlayerOnePaddle.move(0.f, 25.f);
	}
}
*/

Paddle OnePlayerRoom::getCPUPaddle()
{
	return CPUPaddle;
}

