#pragma once

#include "BaseFont.h"
#include "BaseObject.h"

class BaseChoice : public BaseObject
{
public:
	BaseChoice(float x,
			   float y,
			   const std::string& spriteResource,
		       void(*callback)(),
			   const std::string& text,
			   sf::Color onColor,
			   sf::Color offColor,
			   const std::string& fontResource = "basic_font");

	virtual ~BaseChoice();

	virtual void Step() override;
	virtual void Draw() override;

private:
	void(*Callback)();

	//int CharacterSize;
	BaseFont* Font;
	std::string Text;
	
	sf::Color OnColor;
	sf::Color OffColor;
};