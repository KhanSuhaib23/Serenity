#pragma once
#include <string>
#include <GLEW\glew.h>

#include "../../utils/FileUtils.h"

namespace serenity { namespace render {

	class Texture
	{
	private:
		GLubyte*			m_Image;
		GLuint				m_TextureID;
		const GLchar*		m_FileName;
		const GLchar*		m_TextureName;
		GLenum				m_MinFilter;
		GLenum				m_MagFilter;
		GLuint				m_Width;
		GLuint				m_Height;

	public:
		Texture(
					const GLchar*			fileName,
					const GLchar*			textureName,
					GLenum					minFilter = GL_NEAREST_MIPMAP_NEAREST,
					GLenum					magFilter = GL_NEAREST
			   );

		GLuint load();
		void bind();
		void unbind();

	public:
		inline GLuint			getTextureID() const { return m_TextureID; }
		inline const GLchar*	getName() const { return m_TextureName; }
	
	};

} }