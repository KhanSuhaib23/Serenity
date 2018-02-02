#include "Level.h"

namespace serenity { namespace game {


	Level::Level(const GLchar* name) :
		m_Name		(name)
	{

	}

	void Level::addGameObject(GameObject2D* gameObject)
	{
		m_GameObjects.push(gameObject);
	}

} }