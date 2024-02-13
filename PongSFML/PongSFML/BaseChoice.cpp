#include "BaseFont.h"
#include "BaseChoice.h"

BaseChoice::BaseChoice(float x, 
					   float y,
					   const std::string& spriteResource, 
	                   void (*callback)(),
					   const std::string& text,
	                   sf::Color onColor, 
	                   sf::Color offColor,
					   const std::string& fontResource)
	:BaseObject(x, y, spriteResource, 2, 1),
	 Callback(callback),
	 Font(new BaseFont(fontResource)),
	 Text(text),
	 OnColor(onColor),
	 OffColor(offColor)
{
	SetImageSpeed(0.1f);
}

BaseChoice::~BaseChoice()
{
	delete Font;
}

void BaseChoice::Step()
{
	//original project utilizes the mouse....do I want to do this here too??
}

void BaseChoice::Draw()
{
	BaseObject::Draw();
	sf::Color DrawColor = (ImageIndex() == 0) ? OffColor : OnColor;
	Font->Print(X() + 45, Y() + 52, Text, DrawColor, 3, 3);
}