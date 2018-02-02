#include "Sprite.h"

namespace serenity { namespace render {

	struct Sprite::VertexData;

	Sprite::Sprite(float x, float y, manager::TextureManager* textureManager, const GLchar* textureName) :
		m_Scale				(x, y),
		m_TextureManager	(textureManager),
		m_TextureName		(textureName)
	{
		m_TextureManager->getTextureID(textureName);
	}

	GLint Sprite::submit()
	{
		return m_TextureManager->makeTextureActive(m_TextureName);
	}

} }