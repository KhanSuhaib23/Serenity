#pragma once

#include "src\gamehandler\2D\GameObject2D.h"
#include "src\render\renderables\Sprite.h"

class ExampleGameObject : public serenity::game::GameObject2D
{
private:
	serenity::render::Sprite* m_Sprite;

public:
	ExampleGameObject(serenity::maths::Vector3f position, serenity::maths::Vector3f rotation, const GLchar* name) :
		serenity::game::GameObject2D(position, rotation, name)
	{

	}

	void addSprite(serenity::render::Sprite* sprite)
	{
		m_Sprite = sprite;
	}

	GLint getCurrentSpriteTextureID() override
	{
		return m_Sprite->submit();
	}

	serenity::render::Sprite* getCurrentSprite() override
	{
		return m_Sprite;
	}
};