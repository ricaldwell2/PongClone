#pragma once

#include "BaseRoom.h"
#include "BaseGame.h"

//---------------------------
//CONSIDER THIS FILE READONLY
//---------------------------

class GameInitializationRoom : public BaseRoom
{
public:
	GameInitializationRoom();

	virtual void Step() override;
};