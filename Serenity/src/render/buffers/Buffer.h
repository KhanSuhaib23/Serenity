#pragma once

#include <GLEW\glew.h>

namespace serenity { namespace render {

	class Buffer
	{
	private:
		GLuint m_BufferID;

	public:
		Buffer(GLfloat* buffer, GLsizei size, GLenum usage);

		void bind();
		void unbind();
	};

} }