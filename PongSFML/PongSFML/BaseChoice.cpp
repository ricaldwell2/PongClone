#include "BaseChoice.h"

BaseChoice::BaseChoice(float x, float y, int characterSize, 
	                   std::string characterString, sf::Color color, sf::Font font)
	:BaseObject(x, y),
	 Size(characterSize),
	 CharacterString(characterString),
	 Color(color),
	 Font(font)
{
	// Nothing here??
}

