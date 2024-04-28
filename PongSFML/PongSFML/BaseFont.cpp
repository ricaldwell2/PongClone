#include "BaseFont.h"
#include "BaseGame.h"

BaseFont::BaseFont(float x, float y, std::string text, const std::string& resource)
	:StartPosition(x, y),
	 PreviousPosition(x, y),
	 IsSelected(false),
	 DepthValue(0.0),
	 Alarms(5, -1),
	 MenuChoice(text)
{
	//Nothing here...
}

BaseFont::~BaseFont()
{
	delete MenuChoice;
	MenuChoice = nullptr;
}

float BaseFont::X()
{
	return MenuChoice->getPosition().x;
}

//MUST BE CALLED IN A DRAW EVENT!
void BaseFont::Print(float x,
					 float y,
					 const std::string& text,
					 sf::Color tint,
					 float xScale,
					 float yScale)
{
	GetSprite()->setPosition(x, y);
	GetSprite()->setScale(xScale, yScale);
	GetSprite()->setColor(tint);
	for (const char& c : text)
	{
		SetImageIndex(static_cast<float>(c));
		Draw();
		SetX(X() + (xScale + SpriteWidth()));
	}
}