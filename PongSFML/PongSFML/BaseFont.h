#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class BaseFont
{
	////////////////////////////////////////////////////////////////////////////////
	// DEV NOTE: Originally I wanted to make this inherit BaseObject, but it needs 
	// sprites and textures, and this will only be strings. For that reason, I am
	// re-writing entire functions here...probably bad practice. Return here when
	// better idea comes
	////////////////////////////////////////////////////////////////////////////////

public:
	BaseFont(float x, float y, std::string text, const std::string& resource = "basic_font");

	virtual ~BaseFont();

	float X();
	void SetX(float x);

	float Y();
	void SetY(float y);

	float XStart();
	void SetXStart(float x);

	float YStart();
	void SetYStart(float y);

	float XPrevious();
	void SetXPrevious(float x);

	float YPrevious();
	void SetYPrevious(float y);

	bool Selected();
	void SetSelected(bool isSelected);

	float Depth();
	void SetDepth(float depth);

	std::string GetMenuChoice();
	void SetMenuChoice(std::string MenuChoice);


	//MUST BE CALLED IN DRAW EVENT
	void Print(float x,
			   float y,
			   const std::string& text,
			   sf::Color tint = sf::Color::White,
			   float xScale = 1.0f,
			   float yScale = 1.0f);
	  
private:
	sf::Vector2f StartPosition;
	sf::Vector2f PreviousPosition;
	bool IsSelected;
	float DepthValue;
	std::vector<int> Alarms;
	const std::string MenuChoice;
};
