#pragma once



class HWorld;

class UtilityStatics
{

public:

	static HWorld* GetWorld();

private:

	UtilityStatics() {};
	UtilityStatics(const UtilityStatics& Statics) = delete;
};