#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "BaseObject.h"
#include "BaseRoom.h" //Why is this calling it's own headerfile??

class BaseRoom
{
public:
	BaseRoom();

	virtual ~BaseRoom();

	virtual void Step();
	virtual void Draw();

	void InstanceCreate(BaseObject* Object);
	void ChangeRoom(BaseRoom* NextRoom);

private:
	std::vector<BaseObject*> Objects;
};