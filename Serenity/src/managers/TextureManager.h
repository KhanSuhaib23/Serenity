#pragma once

#include <cstring>

#include "..\render\textures\Texture.h"
#include "..\utils\DynamicArray.h"

namespace serenity { namespace manager {

	class TextureManager
	{
	private:
		utils::DynamicArray<const render::Texture*> m_Textures;
		utils::DynamicArray<const render::Texture*> m_ActiveTextures;

	public:
		TextureManager();

	public:
		void						addTexture					(const render::Texture*			texture);
		void						clearTextures				();
		GLuint						getTextureIndex				(const GLchar*					textureName);
		GLuint						getTextureID				(GLuint							index);
		GLuint						getTextureID				(const GLchar*					textureName);
		const render::Texture*		getTexture					(GLuint							index);
		const render::Texture*		getTexture					(const GLchar*					textureName);
		
		void						clearActiveTexture			();
		GLint						makeTextureActive			(const GLchar*					textureName);

	};

} }