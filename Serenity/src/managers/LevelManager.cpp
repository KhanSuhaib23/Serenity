#include "LevelManager.h"

namespace serenity { namespace manager {

	utils::DynamicArray<game::Level*> LevelManager::m_Levels;
	GLuint LevelManager::m_CurrentLevel = 0;


	void LevelManager::addLevel(game::Level* level)
	{
		m_Levels.push(level);
	}

	void LevelManager::changeCurrentLevel(const GLchar* levelName)
	{
		for (int i = 0; i < m_Levels.getSize(); i++)
		{
			if (strcmp(levelName, m_Levels[i]->getName()) == 0)
			{
				m_CurrentLevel = i;
			}
		}
	}

	game::Level* LevelManager::getCurrentLevel()
	{
		return m_Levels[m_CurrentLevel];
	}

} }