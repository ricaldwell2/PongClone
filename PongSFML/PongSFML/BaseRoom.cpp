#include "BaseGame.h"
#include "BaseRoom.h"

BaseRoom::BaseRoom()
	:Objects()
{
	// Getting Ready for BaseObject
}

BaseRoom::~BaseRoom()
{
	for (BaseObject* o : Objects)
	{
		delete o;
	}
	Objects.clear();
}

void BaseRoom::Step()
{
	for (int i = 0; i < Objects.size(); ++i)
	{
		Objects[i]->Step();
	}
}

bool LessThanOperator(BaseObject* lhs, BaseObject* rhs)
{
	return lhs->Depth() < rhs->Depth();
}

void BaseRoom::Draw()
{
	std::sort(Objects.begin(), Objects.end(), LessThanOperator);

	for (BaseObject* o : Objects)
	{
		o->Draw();
	}
}

void BaseRoom::InstanceCreate(BaseObject* Object)
{
	Objects.push_back(Object);
}

void BaseRoom::ChangeRoom(BaseRoom* NextRoom)
{
	BaseGame* g = BaseGame::GetInstance();
	g->ChangeRoom(NextRoom);
}