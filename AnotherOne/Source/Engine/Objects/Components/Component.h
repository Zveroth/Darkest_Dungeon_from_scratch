#pragma once


struct EComponentFlags
{
	enum Value : unsigned int
	{
		NONE = 0,
		RENDERABLE = (1 << 0),
		CLICKABLE = (1 << 1)
	};
};

class IComponent
{

public:

	IComponent() : bPendingDestroy(false) {}

	virtual unsigned int GetComponentFlags() { return EComponentFlags::NONE; }


	//Destruction flag, checked by every system individually
	bool bPendingDestroy;
};