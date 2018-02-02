#pragma once

#include <GLEW\glew.h>

namespace serenity { namespace render {

	class VertexArray
	{
	private:
		GLuint m_VertexArray;

	public:
		VertexArray();

		void bind();
		void unbind();
	};

} }