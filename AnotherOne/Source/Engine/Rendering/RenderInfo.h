#pragma once

#include "GL/glew.h"

#include "glm/glm.hpp"
#include "vector"
#include "string"

struct Vertex
{
	glm::vec3 Location;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct TextureInfo
{
	unsigned int ID;
	std::string Type;
	std::string Path;
};

struct LayoutElement
{
	unsigned int Count;
	unsigned int Type;
	unsigned int bNormalized;

	static unsigned int GetTypeSize(unsigned int Type)
	{
		switch (Type)
		{
		default: return 0;
		case GL_FLOAT: return 4;
		}
	}
};

class BufferLayout
{

public:

	BufferLayout() : Stride(0) {};

	inline std::vector<LayoutElement> GetElements() const { return Elements; }
	inline const unsigned int& GetStride() const { return Stride; }


	template<typename T>
	void Push(unsigned int Count)
	{
		static_assert(false);
	}

	template<>
	void Push<float>(unsigned int Count)
	{
		Elements.push_back({ Count, GL_FLOAT, GL_FALSE });
		Stride += 4 * Count;//No need to call GetTypeSize here
	}

private:

	std::vector<LayoutElement> Elements;
	unsigned int Stride;
};

class VertexBuffer
{

public:

	VertexBuffer() : ID(0) {}
	~VertexBuffer() {}

	void Generate() { glGenBuffers(1, &ID); }
	void Delete() { glDeleteBuffers(1, &ID); }
	void Bind() { glBindBuffer(GL_ARRAY_BUFFER, ID); }

	//Memory size equals NumOfVertices * MemSize of a single vertex data
	void AddData(const unsigned int& MemSize, const void* Data) { glBufferData(GL_ARRAY_BUFFER, MemSize, Data, GL_STATIC_DRAW); }

private:

	unsigned int ID;
};

class IndexBuffer
{

public:

	IndexBuffer() : ID(0) {};
	~IndexBuffer() {}

	void Generate() { glGenBuffers(1, &ID); }
	void Delete() { glDeleteBuffers(1, &ID); }
	void Bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID); }

	//Count equals NumOfIndices
	void AddData(const unsigned int& Count, const void* Data) { glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Count, Data, GL_STATIC_DRAW); }

private:

	unsigned int ID;
};

class VertexArray
{

public:

	VertexArray() : ID(0) {}
	~VertexArray() {}

	void Generate() { glGenVertexArrays(1, &ID); }
	void Delete() { glDeleteVertexArrays(1, &ID); }
	void Bind() { glBindVertexArray(ID); }
	void CreateBuffer(const BufferLayout& Layout)
	{
		const std::vector<LayoutElement>& Elements = Layout.GetElements();
		unsigned int MemOffset = 0;

		for (unsigned int I = 0; I < Elements.size(); I++)
		{
			glEnableVertexAttribArray(I);

			const LayoutElement& Element = Elements[I];
			glVertexAttribPointer(I, Element.Count, Element.Type, Element.bNormalized, Layout.GetStride(), (const void*)MemOffset);
			MemOffset += Element.Count * LayoutElement::GetTypeSize(Element.Type);
		}
	}

private:

	unsigned int ID;
};