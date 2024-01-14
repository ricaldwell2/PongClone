#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"
//#include <vector>
#define Player_scores 2

class OnePlayerRoom
{
public:
	OnePlayerRoom(float width, float height);
	~OnePlayerRoom();
	
	void draw(sf::RenderWindow& onePlayerRoom);

	Paddle getPlayerOnePaddle();
	void PlayerOnePaddleMove();
	
	Paddle getCPUPaddle();
	void CPUPaddleMove();

private:
	// Scores
	sf::Font font;
	sf::Text playerScores[Player_scores];

	int scorePlayerOne = 0;
	int scoreCPU = 0;

	// Objects
	Paddle PlayerOnePaddle;
	Paddle CPUPaddle;
	sf::CircleShape ball;

	float paddleWidth = 50.f;
	float paddleHeight = 150.f;

	// Clock
	sf::Clock clock;
};