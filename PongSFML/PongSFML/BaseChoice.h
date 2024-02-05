#pragma once

#include "BaseObject.h"

class BaseChoice : public BaseObject
{
public:
	BaseChoice(float x,
		float y,
		int characterSize,
		std::string characterString,
		sf::Color color,
		sf::Font font);

private:
	int Size;
	std::string CharacterString;
	sf::Color Color;
	sf::Font Font;
};