#pragma once


#include <iostream>
#include <GLEW\glew.h>

#include <string>

#include "../../utils/FileUtils.h"

namespace serenity { namespace render {

	class Shader
	{
	private:
		const GLchar*		m_VertexPath;
		const GLchar*		m_FragmentPath;

	public:
		GLuint				m_ShaderID;
		Shader				();
		Shader				(
								const GLchar* vertexPath, 
								const GLchar* fragmentPath
							);

		~Shader() {};

	public:
		void		enable			();
		void		disable			();

	private:
		GLuint		load			();

	};

} }