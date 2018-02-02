#pragma once

#include <GLEW\glew.h>

#include "../../render/renderables/Sprite.h"
#include "../../maths/Matrix4f.h"


namespace serenity { namespace game {

	class GameObject2D
	{
	public:
		maths::Vector3f				position;
		maths::Vector3f				rotation;
		const GLchar*				name;

	public:
		GameObject2D			(	
									maths::Vector3f			position, 
									maths::Vector3f			rotation, 
									const GLchar*			name
								);

	public:

		virtual GLint					getCurrentSpriteTextureID() = 0;
		virtual render::Sprite*			getCurrentSprite() = 0;

	};

} }