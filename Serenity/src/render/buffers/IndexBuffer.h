#pragma once

#include <GLEW\glew.h>

namespace serenity { namespace render {

	class IndexBuffer
	{
	private:
		GLuint m_IndexBufferID;

	public:
		IndexBuffer(GLushort* buffer, GLsizei size);
		IndexBuffer(GLuint* buffer, GLsizei size);

		void bind();
		void unbind();
	};

} }