#include "BaseFont.h"
#include "BaseGame.h"

BaseFont::BaseFont(const std::string& resource)
	:BaseObject(0, 0, resource, 16, 16)
{
	//Nothing here...
}

//MUST BE CALLED IN A DRAW EVENT!
void BaseFont::Print(int x,
					 int y,
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