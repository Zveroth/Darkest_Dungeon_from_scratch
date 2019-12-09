#include "RenderComponent.h"




LRenderComponent::LRenderComponent() : m_bRenderReady(false)
{

}

unsigned int LRenderComponent::GetComponentFlags()
{
	return EComponentFlags::RENDERABLE;
}