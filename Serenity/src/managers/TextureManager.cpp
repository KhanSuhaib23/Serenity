#include "TextureManager.h"

namespace serenity { namespace manager {

	TextureManager::TextureManager() :
		m_Textures			(15,	20,		true),
		m_ActiveTextures	(32,	 0,		false)
	{

	}

	void TextureManager::addTexture(const render::Texture* texture)
	{
		m_Textures.push(texture);
	}

	void TextureManager::clearTextures()
	{
		m_Textures.clear();
	}

	GLuint TextureManager::getTextureIndex(const GLchar* textureName)
	{
		for (GLuint i = 0; i < m_Textures.getSize(); i++)
		{
			if (strcmp(m_Textures[i]->getName(), textureName) == 0)
			{
				return i;
			}
		}

		std::cout << "No Such Texture" << std::endl;
		system("PAUSE");
		exit(-1);
	}
	
	GLuint TextureManager::getTextureID(GLuint index)
	{
		return m_Textures[index]->getTextureID();
	}

	GLuint TextureManager::getTextureID(const GLchar* textureName)
	{
		return m_Textures[getTextureIndex(textureName)]->getTextureID();
	}

	const render::Texture* TextureManager::getTexture(GLuint index)
	{
		return m_Textures[index];
	}

	const render::Texture* TextureManager::getTexture(const GLchar* textureName)
	{
		return m_Textures[getTextureIndex(textureName)];
	}

	void TextureManager::clearActiveTexture()
	{
		m_ActiveTextures.clear();
	}

	GLint TextureManager::makeTextureActive(const GLchar* textureName)
	{
		
		for (GLuint i = 0; i < m_ActiveTextures.getSize(); i++)
		{
			const char* anem = m_ActiveTextures[i]->getName();
			if (strcmp(m_ActiveTextures[i]->getName(), textureName) == 0)
			{
				return i;
			}
		}
		if (m_ActiveTextures.getSize() == 32)
		{
			m_ActiveTextures.clear();
			return -1;
		}
		int size = m_ActiveTextures.getSize();
		const render::Texture* texture = getTexture(textureName);

		glActiveTexture(GL_TEXTURE0 + size);
		glBindTexture(GL_TEXTURE_2D, texture->getTextureID());

		m_ActiveTextures.push(texture);
		return size;
	}

} }