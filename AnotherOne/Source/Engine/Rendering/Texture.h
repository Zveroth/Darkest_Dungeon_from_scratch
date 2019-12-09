#pragma once

#include "string"

class Texture
{

public:

	Texture();
	Texture(const std::string& Path);
	~Texture();

	void Bind(unsigned int Slot = 0) const;
	void Unbind() const;

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }

	void LoadTexture(const std::string& Path);

private:

	unsigned int m_RendererID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;//Local storage for the texture
	int m_Width, m_Height, BPP;
};