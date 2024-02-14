#include <iostream>
#include "BaseGame.h"
#include "BaseObject.h"
#include "TextureManager.h"

BaseObject::BaseObject(float x,
					   float y,
					   const std::string& resource,
					   int horizontalFrames,
					   int verticalFrames)
	:Sprite(new sf::Sprite()),
	 StartPosition(x, y),
	 PreviousPosition(x, y),
	 IsVisible(true),
	 DepthValue(0.0),
	 Alarms(5, -1),
	 SpeedVector(0.0f, 0.0f),
	 HorizontalFrames(horizontalFrames),
	 VerticalFrames(verticalFrames),
	 Image_Index(0),
	 Image_Speed(0)
{
	if (resource != "")
	{
		sf::Texture* Texture =
			TextureManager::GetInstance()->GetTexture(resource);
		Sprite->setTexture(*Texture);
		Sprite->setPosition(x, y);
	}
}

BaseObject::~BaseObject()
{
	delete Sprite;
	Sprite = nullptr;
}

void BaseObject::Draw()
{
	if (Sprite != nullptr)
	{
		if (IsVisible == true)
		{
			int x = static_cast<int>(ImageIndex()) % HorizontalFrames;
			int y = static_cast<int>(ImageIndex()) / HorizontalFrames;
			Sprite->setTextureRect(sf::IntRect(x * SpriteWidth(), y * SpriteHeight(), SpriteWidth(), SpriteHeight()));
		}
	}
}

void BaseObject::Step()
{
	// Look at other project for potential usage for Animations and Speed

	//Alarm
	for (std::size_t i = 0; i < Alarms.size(); ++i)
	{
		if (Alarms[i] > 0)
		{
			--Alarms[i];
			if (Alarms[i] == 0)
			{
				OnAlarm(i);
				Alarms[i] = -1;
			}
		}
	}
}

sf::Sprite* BaseObject::GetSprite()
{
	return Sprite;
}

float BaseObject::X()
{
	return Sprite->getPosition().x;
}

void BaseObject::SetX(float x)
{
	Sprite->setPosition(x, Sprite->getPosition().y);
}

float BaseObject::Y()
{
	return Sprite->getPosition().y;
}

void BaseObject::setY(float y)
{
	Sprite->setPosition(Sprite->getPosition().x, y);
}

float BaseObject::XStart()
{
	return StartPosition.x;
}

void BaseObject::SetXStart(float x)
{
	StartPosition.x = x;
}

float BaseObject::YStart()
{
	return StartPosition.y;
}

void BaseObject::SetYStart(float y)
{
	StartPosition.y = y;
}

float BaseObject::XPrevious()
{
	return PreviousPosition.x;
}

void BaseObject::SetXPrevious(float x)
{
	PreviousPosition.x = x;
}

float BaseObject::YPrevious()
{
	return PreviousPosition.y;
}

void BaseObject::SetYPrevious(float y)
{
	PreviousPosition.y = y;
}

bool BaseObject::Visible()
{
	return IsVisible;
}

void BaseObject::SetVisible(bool visible)
{
	IsVisible = visible;
}

float BaseObject::Depth()
{
	return DepthValue;
}

void BaseObject::SetDepth(float depth)
{
	DepthValue = depth;
}

int BaseObject::Alarm(int alarm)
{
	return Alarms[alarm];
}

void BaseObject::SetAlarm(int alarm, int value)
{
	Alarms[alarm] = value;
}

void BaseObject::OnAlarm(int alarm)
{
	// Do Nothing...
}

float BaseObject::HSpeed()
{
	return SpeedVector.x;
}

void BaseObject::SetHSpeed(float hspeed)
{
	SpeedVector.x = hspeed;
}

float BaseObject::VSpeed()
{
	return SpeedVector.y;
}

void BaseObject::SetVSpeed(float vspeed)
{
	SpeedVector.y = vspeed;
}

float BaseObject::Speed()
{
	return hypot(SpeedVector.x, SpeedVector.y);
}

void BaseObject::SetSpeed(float NewSpeed)
{
	float OldSpeed = Speed();
	if (OldSpeed != 0.0f)
	{
		float factor = NewSpeed / OldSpeed;
		SpeedVector *= factor;
	}
	else
	{
		SpeedVector.x = NewSpeed;
	}
}

float BaseObject::Direction()	//Getting the direction in degrees
{
	//DEGREES = 180 * PI / 180
	return 180.0f * atan2(-SpeedVector.y, SpeedVector.x) / 3.1415926535f;
}

void BaseObject::SetDirection(float direction)
{
	// RADIANS = DEGREES * PI / 100
	float radians = direction * static_cast<float>(3.1415926535) / 180.0f;
	float speed = Speed();
	SpeedVector = sf::Vector2f(speed * cos(radians), -speed * sin(radians));
}

float BaseObject::ImageIndex()
{
	return Image_Index;
}

void BaseObject::SetImageIndex(float value)
{
	value = static_cast<float> (fmod(value, HorizontalFrames * VerticalFrames));
	if (value < 0)
	{
		value += (HorizontalFrames * VerticalFrames);
	}
	Image_Index = value;
}

float BaseObject::ImageSpeed()
{
	return Image_Speed;
}

void BaseObject::SetImageSpeed(float value)
{
	Image_Speed = value;
}

int BaseObject::SpriteWidth()
{
	return Sprite->getTexture()->getSize().x / HorizontalFrames;
}

int BaseObject::SpriteHeight()
{
	return Sprite->getTexture()->getSize().y / VerticalFrames;
}


bool BaseObject::IsPointWithinSpriteBounds(int x, int y)
{
	if ((x >= Sprite->getPosition().x) &&
		(x < Sprite->getPosition().x + SpriteWidth()) &&
		(y >= Sprite->getPosition().y) &&
		(y < Sprite->getPosition().y + SpriteWidth()))
	{
		return true;
	}
	return false;
}