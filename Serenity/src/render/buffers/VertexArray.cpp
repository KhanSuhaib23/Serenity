#include "VertexArray.h"

namespace serenity { namespace render {

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);
	}

	void VertexArray::bind()
	{
		glBindVertexArray(m_VertexArray);
	}

	void VertexArray::unbind()
	{
		glBindVertexArray(0);
	}

} }