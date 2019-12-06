#pragma once


struct ComponentFlags
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

	virtual unsigned int GetComponentFlags() { return ComponentFlags::NONE; }
};