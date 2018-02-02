#pragma once

#include "../../maths/Vector.h"
#include "../../managers/TextureManager.h"
#include "../color/Color.h"

namespace serenity { namespace render {

	class Sprite
	{
	public:
		struct VertexData
		{
			maths::Vector3f position;
			float textureID;
			maths::Vector2f textureCoordinate;
			render::Color color;
		};
			
	private:
		manager::TextureManager*		m_TextureManager;
		const GLchar*					m_TextureName;
		maths::Vector2f					m_Scale;

	public:
		Sprite				(
								float							x, 
								float							y, 
								manager::TextureManager*		textureManager, 
								const GLchar*					textureName
							);

	public:
		GLint				submit		();

	public:
		inline const maths::Vector2f&			getScale() { return m_Scale; }
		
	};

} }