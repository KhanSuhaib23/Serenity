#include "Buffer.h"

namespace serenity { namespace render {
	
	Buffer::Buffer(GLfloat* buffer, GLsizei size, GLenum usage = GL_STATIC_DRAW)
	{
		glGenBuffers(1, &m_BufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
		glBufferData(GL_ARRAY_BUFFER, size, buffer, usage);
	}

	void Buffer::bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	}

	void Buffer::unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

} }