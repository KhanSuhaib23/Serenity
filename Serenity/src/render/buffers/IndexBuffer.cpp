#include "IndexBuffer.h"

namespace serenity { namespace render {

	IndexBuffer::IndexBuffer(GLushort* buffer, GLsizei size)
	{
		glGenBuffers(1, &m_IndexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
	}

	IndexBuffer::IndexBuffer(GLuint* buffer, GLsizei size)
	{
		glGenBuffers(1, &m_IndexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
	}

	void IndexBuffer::bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
	}

	void IndexBuffer::unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

} }