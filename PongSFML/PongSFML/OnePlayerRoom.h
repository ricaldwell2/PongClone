#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "BaseRoom.h"
#include "Paddle.h"

#define Player_scores 2

class OnePlayerRoom : public BaseRoom
{
public:
	OnePlayerRoom(float width, float height);
	~OnePlayerRoom();
	
	void Draw(sf::RenderWindow& onePlayerRoom);

	Paddle GetPlayerOnePaddle();
	void PlayerOnePaddleMove();
	
	Paddle GetCPUPaddle();
	void CPUPaddleMove();

private:
	// Scores
	sf::Font font;
	sf::Text playerScores[Player_scores];

	int scorePlayerOne = 0;
	int scoreCPU = 0;

	// Objects
	Paddle PlayerOnePaddle = { 10.f, 285.f, sf::Color::Green };
	Paddle CPUPaddle = { 1220.f, 285.f, sf::Color::Blue };
	sf::CircleShape ball;

	// Clock
	sf::Clock clock;
};