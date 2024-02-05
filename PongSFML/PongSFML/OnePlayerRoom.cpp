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
	playerScores[1].setPosition(1080, 50);

	// Player 1 Paddle
	//PlayerOnePaddle.SetStartPositionX(10.f);
	//PlayerOnePaddle.SetStartPositionY(282.f);
	PlayerOnePaddle.SetPaddleColor(sf::Color::Green);

	// CPU Paddle
	//CPUPaddle.SetStartPositionX(1220.f);
	//CPUPaddle.SetStartPositionY(285.f);
	CPUPaddle.SetPaddleColor(sf::Color::Blue);
}

OnePlayerRoom::~OnePlayerRoom()
{
	// Nothing here??
}

void OnePlayerRoom::Draw(sf::RenderWindow& onePlayerRoom)
{
	/*
	for (int i = 0; i < Player_scores; ++i)
	{
		onePlayerRoom.draw(playerScores[i]);
	}
	*/
}

Paddle OnePlayerRoom::GetPlayerOnePaddle()
{
	return PlayerOnePaddle;
}

Paddle OnePlayerRoom::GetCPUPaddle()
{
	return CPUPaddle;
}

