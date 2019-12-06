#include "SpriteComponent.h"



unsigned int HSpriteComponent::GetComponentFlags()
{
	return (ComponentFlags::RENDERABLE | ComponentFlags::CLICKABLE);
}

void HSpriteComponent::Draw()
{

}