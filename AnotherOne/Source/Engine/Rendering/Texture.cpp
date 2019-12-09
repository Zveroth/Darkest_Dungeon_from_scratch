#include "Texture.h"
#include "GL/glew.h"
#include "External/stb_image/stb_image.h"


Texture::Texture() : m_RendererID(0), m_FilePath(""), m_LocalBuffer(nullptr), m_Width(0), m_Height(0), BPP(0)
{

}

Texture::Texture(const std::string& Path) : m_RendererID(0), m_FilePath(Path), m_LocalBuffer(nullptr), m_Width(0), m_Height(0), BPP(0)
{
	LoadTexture(Path);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_RendererID);
}

void Texture::Bind(unsigned int Slot) const
{
	glActiveTexture(GL_TEXTURE0 + Slot);
	glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

void Texture::Unbind() const
{
}

void Texture::LoadTexture(const std::string& Path)
{
	if (m_RendererID != 0)
		glDeleteTextures(1, &m_RendererID);

	stbi_set_flip_vertically_on_load(1);
	m_LocalBuffer = stbi_load((Path).c_str(), &m_Width, &m_Height, &BPP, 4);

	glGenTextures(1, &m_RendererID);
	glBindTexture(GL_TEXTURE_2D, m_RendererID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (m_LocalBuffer)
		stbi_image_free(m_LocalBuffer);
}