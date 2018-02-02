#include "Texture.h"

namespace serenity { namespace render {

	Texture::Texture(const GLchar* fileName, const GLchar* textureName, GLenum minFilter, GLenum magFilter) :
		m_TextureName		(textureName),
		m_MinFilter			(minFilter),
		m_MagFilter			(magFilter)
	{
		
		std::string temp("../resources/textures/");
		temp += std::string(fileName);
		m_FileName = temp.c_str();
		m_TextureID = load();
	}

	GLuint Texture::load()
	{
		GLuint result;
		m_Image = utils::FileUtils::loadImageFile(m_FileName, m_Width, m_Height);

		glGenTextures(1, &result);
		glBindTexture(GL_TEXTURE_2D, result);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_MinFilter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_MagFilter);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_BGRA, GL_UNSIGNED_BYTE, m_Image);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);

		return result;
	}

	void Texture::bind()
	{
		glBindTexture(GL_TEXTURE_2D, m_TextureID);
	}

	void Texture::unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

} }