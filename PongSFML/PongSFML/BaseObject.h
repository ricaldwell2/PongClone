#pragma once

#include <SFML/Graphics.hpp>

class BaseObject
{
public:

	BaseObject(float x, float y, const std::string& resource = "", int horizontalFrames = 1, int verticalFrames = 1);

	~BaseObject();

	virtual void Draw();
	virtual void Step();

	sf::Sprite* GetSprite();

	float X();
	void SetX(float x);

	float Y();
	void setY(float y);

	float XStart();
	void SetXStart(float x);

	float YStart();
	void SetYStart(float y);

	float XPrevious();
	void SetXPrevious(float y);

	float YPrevious();
	void SetYPrevious(float y);

	bool Visible();
	void SetVisible(bool visible);
	
	float Depth();
	void SetDepth(float depth);

	int Alarm(int alarm);
	void SetAlarm(int alarm, int value);
	virtual void OnAlarm(int alarm);

	float HSpeed();
	void SetHSpeed(float hspeed);

	float VSpeed();
	void SetVSpeed(float vspeed);

	float Speed();
	void SetSpeed(float NewSpeed);

	float Direction();
	void SetDirection(float direction);

	float ImageIndex();
	void SetImageIndex(float value);

	float ImageSpeed();
	void SetImageSpeed(float value);

	int SpriteWidth();
	int SpriteHeight();

	bool IsPointWithinSpriteBounds(int x, int y);

private:
	sf::Sprite* Sprite;
	sf::Vector2f StartPosition;
	sf::Vector2f PreviousPosition;
	bool IsVisible;
	float DepthValue;
	std::vector<int> Alarms;
	sf::Vector2f SpeedVector;
	int HorizontalFrames;
	int VerticalFrames;
	float Image_Index;
	float Image_Speed;
};